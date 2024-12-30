#!/bin/bash

# Install all the packages
sudo xbps-install -y NetworkManager Thunar base-devel base-system blueman curl dunst elogind fcft fcft-devel firefox foot gcc git libxml2-devel light make mesa-dri pamixer pavucontrol pipewire pulseaudio qt5-wayland qt6-wayland sof-firmware sof-tools swaybg wget wl-clipboard wlroots-devel wlroots0.18 wlroots0.18-devel wmenu dejavu-fonts-ttf xorg-server-xwayland

# Remove the wpa_supplicant symlink
sudo rm -f /var/service/wpa_supplicant

# Create correct symlinks in /var/service
sudo ln -s /etc/sv/NetworkManager /var/service
sudo ln -s /etc/sv/dbus /var/service
sudo ln -s /etc/sv/elogind /var/service
sudo ln -s /etc/sv/bluetoothd /var/service

