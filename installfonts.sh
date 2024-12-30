#!/bin/bash

# Set the source folder and target directory
SOURCE_FOLDER="./Hack"
FONT_DIR="$HOME/.fonts"

# Create the target directory if it doesn't exist
mkdir -p "$FONT_DIR"

# Move the entire folder to the font directory
cp -r "$SOURCE_FOLDER" "$FONT_DIR/"

# Refresh font cache on Linux
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    fc-cache -fv
fi

echo "Hack folder moved to $FONT_DIR successfully!"

