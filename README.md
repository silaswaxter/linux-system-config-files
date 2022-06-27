# About
This repo contains custom configuration files for system programs (e.g. display manager lightdm).  
Additionaly, the repo contains files to patch specific computer's (e.g. asus rog g14) functionality
like volume control buttons, keyboard brightness control buttons, etc.

## Where to place in system
This repo's directory should be placed somewhere in root space because symbolic links from user to
root space are "bad";  this is a documented problem for systems that have different root and user
root partitions.  Symlinks properly resolve when this repo is placed at /etc.
