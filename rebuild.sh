#!/bin/bash

cd ~/icede

sudo rm config.h

sudo make clean

sudo make HOME_DIR=$(echo ~) install
