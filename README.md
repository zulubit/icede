# IceDE - dwl fork by Zulubit

## Dependencies

### System Packages
- **base-devel** - Development tools for building software
- **base-system** - Core system packages

### Network Management
- **NetworkManager** - Network connection management (Wi-Fi, Ethernet, VPN, etc.)
- **blueman** - Bluetooth manager for GTK

### Multimedia
- **pipewire** - Multimedia server for handling audio and video streams
- **pulseaudio** - Sound server for Linux (optional if using PipeWire)
- **pavucontrol** - PulseAudio volume control (works with PulseAudio or PipeWire)
- **pamixer** - Simple command-line audio mixer (works with PulseAudio or PipeWire)

### Display and Window Management
- **xorg-server-xwayland** - XWayland server for running X applications on Wayland
- **wlroots** - Modular Wayland compositor library
- **wlroots-devel** - Development files for wlroots
- **swaybg** - Background manager for Sway
- **wmenu** - Menu for Wayland
- **qt5-wayland** - Qt5 bindings for Wayland
- **qt6-wayland** - Qt6 bindings for Wayland
- **wl-clipboard** - Clipboard utilities for Wayland

### Fonts
- **dejavu-fonts-ttf** - DejaVu TrueType fonts for general use

### Utilities
- **curl** - Command-line tool for transferring data
- **wget** - Command-line utility for downloading files from the web
- **git** - Version control system
- **make** - Build automation tool
- **dunst** - Lightweight notification daemon
- **light** - Simple and lightweight backlight control
- **foot** - Lightweight Wayland terminal

### Graphics
- **mesa-dri** - Direct Rendering Infrastructure for 3D graphics
- **fcft** - Minimal C library for handling fonts
- **fcft-devel** - Development files for fcft

### System Services
- **elogind** - Session and login manager for users under systemd
- **sof-firmware** - Sound Open Firmware for Intel sound devices
- **sof-tools** - Tools for managing Sound Open Firmware

### Web Browser
- **firefox** - Firefox web browser

### Compiler & Development Tools
- **gcc** - GNU Compiler Collection
- **libxml2-devel** - Development files for libxml2, a library for XML parsing

---

## Build

```bash
sudo make HOME_DIR=$(echo ~) install
```

## DWL

For more information, you should visit [dwl](https://codeberg.org/dwl/dwl).
