#About
I currently am using a forked version of slock (a suckless session locker);  the fork adds  
transparency and blur features.  The fork's [repo](https://codeberg.org/jos/slock) is a submodule  
of this project.

##Installation
1. after using git's sync/update submodule to pull the source into `./slock_fork/`, follow the  
   docs.
2. you will likely want to change the insallation location to `/opt/slock`.
3. `config.h` in this directory contains my current theming information for slock;  this is a  
   good starting point.

To use bluring, you must use a compositor like picom.  See 
[ref](https://codeberg.org/jos/slock/issues/1).
