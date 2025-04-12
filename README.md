# 🔒 Prevent Unauthorized USB Access with Auto-Shutdown Kernel Module for Linux

This Linux kernel module enhances system security by automatically initiating a shutdown whenever a USB device (such as a keyboard, mouse, or storage device) is connected. It's particularly useful in environments where unauthorized USB access must be prevented.

---

## 🧠 Overview

The module operates by monitoring USB device events within the kernel space. Upon detecting the insertion of any USB device, it immediately triggers a system shutdown, preventing potential security breaches or data exfiltration.

**Note:** After the system shuts down, the kernel module is removed from memory. Therefore, to maintain this protective behavior, you must manually reload the module after each startup.

---

## 🛠️ Features

- Real-Time USB Monitoring
- Immediate Shutdown on USB insertion
- Kernel-Level Operation
- Lightweight and minimal resource usage

---

## 📦 Prerequisites

- **Operating System:** Linux (Kernel version 3.x or higher recommended)
- **Kernel Headers:** Make sure the kernel headers are installed
- **Build Tools:** `make`, `gcc`, etc.

---

## 🛠️ Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yogeshwaran5/usb-shutdown-kernel-module.git
   cd usb-shutdown-kernel-module
   ```

2. **Build the Module:**
   ```bash
   make
   ```

3. **Insert the Module:**
   ```bash
   sudo insmod usb_shutdown.ko
   ```

4. **Verify Module is Loaded:**
   ```bash
   lsmod | grep usb_shutdown
   ```

---

## ⚙️ Usage

Once loaded, the kernel module watches for any USB device insertions. If a device is connected, the module immediately shuts down the system to prevent unauthorized access.

> **Reminder:** After shutdown, this module is no longer loaded. You need to reload it on every reboot if continuous protection is required.

---

## 🔄 Uninstallation

1. **Remove the Module:**
   ```bash
   sudo rmmod usb_shutdown
   ```

2. **Clean Up Build Files:**
   ```bash
   make clean
   ```

---

## ⚠️ Important Notes

- **Warning:** The shutdown is immediate and unsaved work will be lost.
- **Use with Caution:** Test this module in a virtual machine or non-critical system before deploying.
- **Reload Kernel module on Boot:** Consider adding it to startup scripts if needed regularly.

---

## 📄 License

This project is licensed under the [GNU General Public License v2.0](https://www.gnu.org/licenses/gpl-2.0.en.html).

---

## 🙏 Acknowledgements

Inspired by security tools like [USBKill](https://github.com/hephaest0s/usbkill) and [BusKill](https://github.com/BusKill/buskill), this module provides kernel-level protection against physical USB threats.
