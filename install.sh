#!/bin/sh

echo "Installation of Shellmates calculator begins now !!!"

echo "Do you want the  calculator to be installed globally , if you chose no it'll be installed only for this user : (y/n)"
read -n 1 choice
echo

gcc src/calculator.c -o shellmates_calculator -lm

if [ "$choice" = "y" ]; then
    echo "Global installation :"
    sudo mv shellmates_calculator /usr/local/bin
else
    echo "Local installation :"
    mkdir -p ~/.local/bin 
    mv shellmates_calculator ~/.local/bin
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
    source ~/.bashrc
fi

echo "Shellmates calculator installed successfully"
