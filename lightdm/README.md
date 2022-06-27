# Setting Up lightdm and slick-greeter
1. Ensure lightdm and lightdm-slick-greeter are installed
2. Enable lightdm.service
3. Create symlinks (use absolute paths):
    * `ln -s $(pwd)/lightdm.conf /etc/lightdm/lightdm.conf`
    * `ln -s $(pwd)/slick-greeter.conf /etc/lightdm/slick-greeter.conf`
    * `ln -s $(pwd)/black_marble.jpeg /usr/share/wallpapers/black_marble.jpeg`
