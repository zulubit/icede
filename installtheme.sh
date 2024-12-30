#!/bin/bash

# Define the archive filename and the user-specific theme directory
ARCHIVE="Nordic.tar.xz"
THEME_DIR="$HOME/.themes/Nordic"

# Check if the archive exists in the current directory
if [ ! -f "$ARCHIVE" ]; then
    echo "Error: Archive $ARCHIVE not found in the current directory."
    exit 1
fi

# Create the user-specific themes directory if it doesn't exist
mkdir -p "$THEME_DIR"

# Extract the theme to the ~/.themes directory
echo "Extracting theme to $THEME_DIR..."
tar -xvf "$ARCHIVE" -C "$THEME_DIR" --strip-components=1

echo "Theme installed successfully to $THEME_DIR."