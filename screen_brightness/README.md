# About
These scripts use xrandr to modify the brightness of displays.  

"all\_monitor\_brightness" uses xrandr to find the currently connected display;  then to inc/dec  
the brightness for all displays it calls "all\_monitor\_brightness" on each of the displays.  See  
top of script file for more details.

"all\_monitor\_brightness" inc/dec the brightness of a single display using xrandr.  It also  
sends a notification via `notify-send`;  this notification reports a mapped brightness as an
integer meaning the notification will display a visual filled bar indicating brightness.
Developed using dunst.

## Setting Up Screen Brightness Scripts
1. Add an enviornment variable titled `SCREEN_BRIGHTNESS_SCRIPTS_DIR` that contains the absolute  
   path of this folder.
