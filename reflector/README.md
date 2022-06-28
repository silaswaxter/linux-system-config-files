#About Reflector
The default config is prtty good and is currently used.  To setup reflector:
1. ensure reflector is installed
2. enable/start relector.service
3. edit the service so that reflector is delayed;  should be enough time for network stuff to  
   finish setting up.
    - add `ExecStartPre=/bin/sleep 10` before `ExecStart...` entry.  see [reference]  
      (https://www.reddit.com/r/archlinux/comments/9tnh00/reflector_service_does_not_wait_for_network_to_be/)
3. add "mirrorlist.pacnew" to "NoExtract" list in /etc/pacman.conf
    - stops pacman from creating mirrorlist.pacnew files when pacman is  
      updated;  reflector will ensure this stays up to date by running  
      once a week (default).

