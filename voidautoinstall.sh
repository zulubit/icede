#!/bin/bash

# Function to handle errors and exit the script
error_exit() {
    echo "Error: $1"
    exit 1
}

# Install all the packages
sudo xbps-install -y NetworkManager Thunar base-devel base-system blueman curl mako elogind fcft void-repo-nonfree fcft-devel firefox foot gcc git libxml2-devel xdg-desktop-portal-wlr xdg-desktop-portal-gtk light make mesa-dri pamixer pavucontrol pipewire pulseaudio qt5-wayland qt6-wayland sof-firmware sof-tools swaybg wget wl-clipboard wlroots-devel wlroots0.18 wlroots0.18-devel wmenu dejavu-fonts-ttf xorg-server-xwayland || error_exit "Package installation failed."

# Remove the wpa_supplicant symlink
sudo rm -f /var/service/wpa_supplicant || error_exit "Failed to remove wpa_supplicant symlink."

# Create correct symlinks in /var/service
sudo ln -s /etc/sv/NetworkManager /var/service || error_exit "Failed to create NetworkManager symlink."
sudo ln -s /etc/sv/dbus /var/service || error_exit "Failed to create dbus symlink."
sudo ln -s /etc/sv/elogind /var/service || error_exit "Failed to create elogind symlink."
sudo ln -s /etc/sv/bluetoothd /var/service || error_exit "Failed to create bluetoothd symlink."

# Clone icede
git clone https://github.com/zulubit/icede.git || error_exit "Failed to clone icede repository."

# Cd into icede
cd icede || error_exit "Failed to change directory into icede."

# Build icede
sudo make HOME_DIR=$(echo ~) install || error_exit "Failed to build and install icede."

# Make bar.sh and start.sh executable
chmod +x bar.sh || error_exit "Failed to make bar.sh executable."
chmod +x start.sh || error_exit "Failed to make start.sh executable."

# Install themes (add the installtheme.sh script)
chmod +x installtheme.sh || error_exit "Failed to make installtheme.sh executable."
./installtheme.sh || error_exit "Failed to run installtheme.sh."

# Install fonts (add the installfonts.sh script)
chmod +x installfonts.sh || error_exit "Failed to make installfonts.sh executable."
./installfonts.sh || error_exit "Failed to run installfonts.sh."

echo "alias ice='cat ~/icede/USEFUL.md'" >> ~/.bashrc || error_exit "Failed to add alias to .bashrc."

# Completion message
echo "You should 'sudo reboot' your system, then you can use './icede/start' after logging back in."

