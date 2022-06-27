#About Reflector
The default config is prtty good and is currently used.  To setup reflector:
1. ensure packages listed in ./packages.lst are installed
2. enable/start relector.service
3. add "mirrorlist.pacnew" to "NoExtract" list in /etc/pacman.conf
    - stops pacman from creating mirrorlist.pacnew files when pacman is  
      updated;  reflector will ensure this stays up to date by running  
      once a week (default).
