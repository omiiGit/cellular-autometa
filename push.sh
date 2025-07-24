#!/bin/bash

KEY_PATH=~/.ssh/id_rsa

if ! pgrep -u $USER "ssh-agent" 1> /dev/null 2> /dev/null
then
    eval "$(ssh-agent -s)"
    ssh-add $KEY_PATH
else
    git add .
    git commit -m updated 
    git push origin master
fi
