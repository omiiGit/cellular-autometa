#!/bin/bash

KEY_PATH=~/.ssh/id_rsa

if ssh-add $KEY_PATH >> /dev/null
then
    eval "$(ssh-agent -s)"
    ssh-add $KEY_PATH
else
    git add .
    git commit -m updated 
    git push origin master
fi
