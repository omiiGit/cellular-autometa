#!/bin/bash

KEY_PATH=~/.ssh/id_rsa
DATE=$(date)

if ! pgrep -u $USER "ssh-agent" 1> /dev/null 2> /dev/null
then
    eval "$(ssh-agent -s)"
    ssh-add $KEY_PATH
    git add .
    git commit -m "updated on $DATE" 
    git push origin master
else
    git add .
    git commit -m "updated on $DATE"
    git push origin master
fi
