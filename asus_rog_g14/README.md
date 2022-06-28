# About
The following notes describe the necesary steps to get many expected features of an asus  
zephyrus g14 (GA401) laptop to work.

`packages.lst` and `packages_foreign.lst` files describe the necesary packages for these  
configs to work;  for native (ie pacman) and foreign (ie AUR) packages  
respectively.

## Installing patched kernel, display drivers, and asusctl utillity
Follow official asus arch linux [guide](asus-linux.org/wiki/arch-guide).
Addendum:
    1) when installing nvidia display drivers, install:     (must enable multilib)
        - nvidia-dkms nvidia-utils lib32-nvidia-utils
    2) when installing amd display drivers, install:        (must enable multilib)  
        - mesa lib32-mesa

## Mapping Keys
This [tutorial](https://www.reddit.com/r/ZephyrusG14/comments/k69zjm/linux_new_daily_driver/)
shows how to map many keys to their associated XF86__ key codes.  xbindkeys can interpret the  
key codes and make the corresponding commands.

### Tutorial
1) Create a symbolic link for hardware keycodes config
    - `ln -s $(pwd)/90-g14-mod.hwdb /etc/udev/hwdb.d/`
    - update with new config:
        + `sudo systemd-hwdb update`
        + `sudo udevadm trigger`
2) Ensure packages.lst and packages_foreign.lst are installed
    - xbindkeys is run when x server starts if the user starting x server has a config file at  
      `~/.xbindkeysrc`;  to use an alternate config file, run: `xbindkeys -f LOCATION_OF_RC_FILE`.  
      This can be run in a startup script of some form (eg ~/.xinitrc, ~/.i3/config, etc.).

### Common Issues
- Keyboard brightness isn't changing when button is being pressed, but xbindkeys recognizes and  
  passes the XF86__ code.  
    + The program used to change keyboard brightness 'light' adds a udev rule which  
      allows users in the video group to modify the brightness;  ensure the user is  
      apart of the video group
