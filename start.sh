# Start DBus session in the background
dbus-launch --sh-syntax --exit-with-session &

# Set the GTK3/GTK4 theme (works for GTK3 and GTK4 apps)
export GTK_THEME="Nordic"

# Set the GTK2 theme
export GTK2_RC_FILES="$HOME/.themes/Nordic/gtk-2.0/gtkrc"

# Start the status bar
~/icede/bar.sh |

# Launch dwl
dbus-run-session dwl
