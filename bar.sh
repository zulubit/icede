#!/bin/bash

# Dracula Theme Colors
BLACK="282A36"
WHITE="F8F8F2"
CYAN="8BE9FD"
GREEN="50FA7B"
RED="FF5555"
YELLOW="F1FA8C"
PINK="FF79C6"
PURPLE="BD93F9"
BLUE="6272A4"

# Nerd Font Icons
ICON_TIME="  "      # Time icon
ICON_BATTERY=" "   # Battery icon
ICON_CPU="  "       # CPU icon
ICON_MEM="  "       # Memory icon
ICON_NET_CONNECTED="  " # Wi-Fi connected icon
ICON_NET_DISCONNECTED="X " # Wi-Fi disconnected icon
ICON_VOLUME="  "     # Volume icon
ICON_VOLUME_MUTED="  "  # Volume muted icon

while true; do
    # Get the current time
    TIME=$(date '+%Y-%m-%d %H:%M:%S')

    # Get battery status
    BATTERY=$(cat /sys/class/power_supply/BAT0/capacity)

    # Get CPU usage
    CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1 "%"}')

    # Get memory usage
    MEM_USAGE=$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)  # Memory usage (in GB/MB)

    # Get network status using nmcli
    NETWORK_STATUS=$(nmcli -t -f DEVICE,TYPE,STATE dev status | grep 'connected' | awk '{print $2}')
    if [[ -z "$NETWORK_STATUS" ]]; then
        NET_STATUS_ICON=$ICON_NET_DISCONNECTED
        NET_STATUS="Disconnected"
    else
        NET_STATUS_ICON=$ICON_NET_CONNECTED
        NET_STATUS="Connected"
    fi

    # Get current volume level (using pamixer)
    VOLUME=$(pamixer --get-volume)
    VOLUME_MUTED=$(pamixer --get-mute)

    # If the volume is muted, change the icon and status
    if [[ "$VOLUME_MUTED" == "true" ]]; then
        VOLUME_ICON=$ICON_VOLUME_MUTED
        VOLUME_STATUS="Muted"
    else
        VOLUME_ICON=$ICON_VOLUME
        VOLUME_STATUS="$VOLUME"
    fi

    # Output with colored text and NerdFont icons
    echo "^fg($CYAN)$ICON_TIME ^fg($WHITE)$TIME ^fg($GREEN) | ^fg($RED)$ICON_BATTERY ^fg($WHITE)$BATTERY% ^fg($YELLOW) | ^fg($PINK)$ICON_CPU ^fg($WHITE)$CPU_USAGE ^fg($CYAN) | ^fg($PURPLE)$ICON_MEM ^fg($WHITE)$MEM_USAGE ^fg($BLUE) | ^fg($CYAN)$NET_STATUS_ICON ^fg($WHITE)$NET_STATUS ^fg($CYAN) | ^fg($WHITE)$VOLUME_ICON ^fg($WHITE)$VOLUME_STATUS "

    # Update every second
    sleep 1
done

