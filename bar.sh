#!/bin/bash

# Nord Theme Colors (using only foreground colors, no backgrounds)
NORD1="d8dee9"  # Light color for foreground text (time, battery, etc.)
NORD2="5e81ac"  # Red for all icons

# Nerd Font Icons
ICON_TIME="󱑃"      # Time icon
ICON_BATTERY=""   # Battery icon
ICON_CPU="󰘚"       # CPU icon
ICON_MEM=""       # Memory icon
ICON_NET_CONNECTED="" # Wi-Fi connected icon
ICON_NET_DISCONNECTED="󱚼" # Wi-Fi disconnected icon
ICON_VOLUME=""     # Volume icon
ICON_VOLUME_MUTED=""  # Volume muted icon

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

    # Output with Nord color scheme (monochrome look, no background)
    echo "^bg($NORD2) ^fg($NORD1)$ICON_BATTERY ^bg() ^fg($NORD1)$BATTERY% \
^bg($NORD2) ^fg($NORD1)$ICON_CPU ^bg() ^fg($NORD1)$CPU_USAGE \
^bg($NORD2) ^fg($NORD1)$ICON_MEM ^bg() ^fg($NORD1)$MEM_USAGE \
^bg($NORD2) ^fg($NORD1)$NET_STATUS_ICON ^bg() ^fg($NORD1)$NET_STATUS \
^bg($NORD2) ^fg($NORD1)$VOLUME_ICON ^bg() ^fg($NORD1)$VOLUME_STATUS \
^bg($NORD2) ^fg($NORD1)$ICON_TIME ^bg() ^fg($NORD1)$TIME " 

    # Update every second
    sleep 1
done

