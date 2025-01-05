#!/bin/sh

# Start DBus session in the background
dbus-launch --sh-syntax --exit-with-session &

# Set the GTK3/GTK4 theme (works for GTK3 and GTK4 apps)
export GTK_THEME="Nordic"

# Set the GTK2 theme
export GTK2_RC_FILES="$HOME/.themes/Nordic/gtk-2.0/gtkrc"

# Set Wayland environment variables
export ELM_DISPLAY=wl
export SDL_VIDEODRIVER=wayland
export QT_QPA_PLATFORM=wayland-egl
export XDG_SESSION_TYPE=xwayland

# Add Flatpak executables to the PATH for wmenu to detect
# These are the directories where Flatpak apps are installed
export PATH="$PATH:$HOME/.local/bin:/var/lib/flatpak/exports/bin"

# Set light brightness to 50%
light -S 50

# Start the status bar
~/icede/bar.sh |

# Launch dwl
dbus-run-session dwl

