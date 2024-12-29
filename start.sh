# Start DBus session in the background
dbus-launch --sh-syntax --exit-with-session &

# Start the status bar
~/icede/bar.sh |

# Launch dwl
dbus-run-session dwl
