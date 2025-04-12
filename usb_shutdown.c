#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yogeshwaran");
MODULE_DESCRIPTION("Shutdown system on USB device insertion");
MODULE_VERSION("1.0");

static int usb_notify(struct notifier_block *nb, unsigned long action, void *data)
{
    struct usb_device *udev = data;

    pr_info("usb_shutdown: USB notifier called. Action = %lu\n", action);

    if (action == USB_DEVICE_ADD) {
        pr_info("usb_shutdown: USB device inserted.\n");
        pr_info("usb_shutdown: Vendor ID = 0x%04x, Product ID = 0x%04x\n",
                le16_to_cpu(udev->descriptor.idVendor),
                le16_to_cpu(udev->descriptor.idProduct));

        pr_info("usb_shutdown: Initiating graceful system shutdown...\n");
        orderly_poweroff(true); // use kernel_power_off() for hard shutdown
    }

    return NOTIFY_OK;
}

static struct notifier_block usb_nb = {
    .notifier_call = usb_notify,
};

static int __init usb_shutdown_init(void)
{
    pr_info("usb_shutdown: Module loaded\n");
    usb_register_notify(&usb_nb);  // Try register_usb_notifier(NULL, &usb_nb) if needed
    return 0;
}

static void __exit usb_shutdown_exit(void)
{
    usb_unregister_notify(&usb_nb);  // Or unregister_usb_notifier(NULL, &usb_nb)
    pr_info("usb_shutdown: Module unloaded\n");
}

module_init(usb_shutdown_init);
module_exit(usb_shutdown_exit);
