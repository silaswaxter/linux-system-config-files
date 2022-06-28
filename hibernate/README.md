To enable hibernation for computer, [follow the wiki](https://wiki.archlinux.org/title/Power_management/Suspend_and_hibernate#Hibernation);  
in general, the follow these steps, but remember the wiki takes precedance:
1. "Configure the initramfs" by adding `resume` to `HOOKS`
2. [modify the grub config](https://wiki.archlinux.org/title/GRUB#Configuration) by adding  
   the specific swap partition (eg `/dev/sda1`) as a default kernel parameter:
   - `resume=/dev/sda1`
3. regenerate the grub cfg
