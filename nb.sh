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

# Nerd Font Icons
ICON_TIME=" "      # Time icon
ICON_BATTERY=""   # Battery icon
ICON_CPU=" "       # CPU icon
ICON_MEM=" "       # Memory icon

while true; do
    # Get the current time
    TIME=$(date '+%H:%M:%S')

    # Get battery status
    BATTERY=$(cat /sys/class/power_supply/BAT0/capacity)

    # Get CPU usage (you can adjust the awk command to format this better)
    CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1 "%"}')

    # Get memory usage
    MEM_USAGE=$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)  # Memory usage (in GB/MB)

    # Output with colored text and NerdFont icons
    echo "^fg($CYAN)$ICON_TIME ^fg($WHITE)$TIME ^fg($GREEN)| ^fg($RED)$ICON_BATTERY ^fg($WHITE)$BATTERY% ^fg($YELLOW)| ^fg($PINK)$ICON_CPU ^fg($WHITE)$CPU_USAGE ^fg($CYAN)| ^fg($PURPLE)$ICON_MEM ^fg($WHITE)$MEM_USAGE ^fg($BLUE)"

    # Update every second
    sleep 1
done

