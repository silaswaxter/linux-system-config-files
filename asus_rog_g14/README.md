# About
The following notes describe the necesary steps to get many expected features of  
an asus zephyrus g14 (GA401) laptop to work.

"packages.lst" and "packages_foreign.lst" files describe the necesary packages  
for these configs to work;  packages is for pacman, and packages_foregin is for  
AUR packages.

## Installing patched kernel, display drivers, and asusctl utillity
Follow official asus arch linux guide: asus-linux.org/wiki/arch-guide
Addendum:
    1) when installing nvidia display drivers, install:     (must enable multilib)
            nvidia-dkms nvidia-utils lib32-nvidia-utils
    2) when installing amd display drivers, install:        (must enable multilib)
            mesa lib32-mesa

## Mapping Keys
Following:  https://www.reddit.com/r/ZephyrusG14/comments/k69zjm/linux_new_daily_driver/
This will map many keys to their associated XF86__ key codes.
xbindkeys can interpret the key codes and make the corresponding commands.
### Tutorial
1) Create a symbolic link for hardware keycodes config
    - `ln -s $(pwd)/90-g14-mod.hwdb /etc/udev/hwdb.d/`
    - update with new config:
        + `sudo systemd-hwdb update`
        + `sudo udevadm trigger`
2) Ensure packages.lst and packages_foreign.lst are installed
    - xbindkeys is run when x server starts if the user starting x server has a config  
      file at ~/.xbindkeysrc.  To use alternate config file, run  
      `xbindkeys -f LOCATION_OF_RC_FILE`;  this can be executed in user's login start  
      script (ie ~/.xinitrc, ~/.i3/config, etc.).
### Troubleshooting
- Keyboard brightness isn't changing when button is being pressed, but xbindkeys  
  recognizes and passes the XF86__ code.
    + The program used to change keyboard brightness 'light' adds a udev rule which  
      allows users in the video group to modify the brightness;  ensure the user is
      apart of the video group


## About the Mute-Mic Key
The following is my understanding of why this is tricky:
You can run "xbindkeys --key" to test what xserver keycode is transmitted when a button
is pressed.  When the mute-mic key is pressed, nothing is transmitted.  However, by
installing acpid and running "acpi_listen" its clear that the button press transmits a
code on the acpi bus.  The next logical step is to create a acpi event that listens 
for this code and toggles pulseaudio's mute when activated;  this doesn't work because
the handler is "root"--you cant imitate the button press bc that requires passing the
current x server to the handler, and you cant direclty mute pulseaudio bc of the same
reason:  pulseaudio is running user level.

tried following: https://makandracards.com/makandra/47162-how-to-enable-the-thinkpad-microphone-mute-key-on-ubuntu-16-04
