#!/bin/bash

# Nord Theme Colors (using only foreground colors, no backgrounds)
NORD1="d8dee9"  # Light color for foreground text (time, battery, etc.)
NORD2="5e81ac"  # Red for all icons
NORD3="bf616a"  # Red for background when muted, disconnected, or low battery

# Nerd Font Icons
ICON_TIME="󱑃"      # Time icon
ICON_BATTERY=""   # Battery icon
ICON_NET_CONNECTED="" # Wi-Fi connected icon
ICON_NET_DISCONNECTED="󱚼" # Wi-Fi disconnected icon
ICON_VOLUME=""     # Volume icon
ICON_VOLUME_MUTED=""  # Volume muted icon

while true; do
    # Get the current time
    # TIME=$(date '+%Y-%m-%d %H:%M:%S')
    TIME=$(date '+%H:%M:%S')

    # Get battery status
    BATTERY=$(cat /sys/class/power_supply/BAT0/capacity)
    
    # Check if battery is below 15% for red background
    if [ "$BATTERY" -lt 15 ]; then
        BATTERY_BG_COLOR=$NORD3  # Red background for low battery
    else
        BATTERY_BG_COLOR=$NORD2  # Default background color for battery
    fi

    # Get network status using nmcli
    NETWORK_STATUS=$(nmcli -t -f DEVICE,TYPE,STATE dev status | grep 'wifi:connected')
    if [[ -z "$NETWORK_STATUS" ]]; then
        NET_STATUS_ICON=$ICON_NET_DISCONNECTED
        NET_STATUS="D"
        NET_BG_COLOR=$NORD3  # Red background for disconnected Wi-Fi
    else
        NET_STATUS_ICON=$ICON_NET_CONNECTED
        NET_STATUS="C"
        NET_BG_COLOR=$NORD2  # Default red background for connected Wi-Fi
    fi

    # Get current volume level (using pamixer)
    VOLUME=$(pamixer --get-volume)
    VOLUME_MUTED=$(pamixer --get-mute)

    # If the volume is muted, change the icon and status, and set red background
    if [[ "$VOLUME_MUTED" == "true" ]]; then
        VOLUME_ICON=$ICON_VOLUME_MUTED
        VOLUME_STATUS="Muted"
        VOLUME_BG_COLOR=$NORD3  # Red background for muted volume
    else
        VOLUME_ICON=$ICON_VOLUME
        VOLUME_STATUS="$VOLUME"
        VOLUME_BG_COLOR=$NORD2  # Default red background for volume
    fi

    # Output with Nord color scheme (monochrome look, no background)
    echo "^bg($BATTERY_BG_COLOR) ^fg($NORD1)$ICON_BATTERY ^bg() ^fg($NORD1)$BATTERY% \
^bg($VOLUME_BG_COLOR) ^fg($NORD1)$VOLUME_ICON ^bg() ^fg($NORD1)$VOLUME_STATUS \
^bg($NORD2) ^fg($NORD1)$ICON_TIME ^bg() ^fg($NORD1)$TIME \
^bg($NET_BG_COLOR) ^fg($NORD1)$NET_STATUS_ICON ^bg()"

    # Update every second
    sleep 0.5
done

