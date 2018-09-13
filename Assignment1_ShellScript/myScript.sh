#!/bin/bash
#Welcome to the interactive System Prompter Tutotial. 
 
#The purpose of this script is create an interactive selection menu to quickly access information
#about the computer, all in one capsule. This info includes the computer's connectivity to the 
#internet, the system's host name and ip adress and lastly information on the hardware.

#Iitializa global condition for the while loop that keeps the program runnninn until manual exit
CONDITIONAL=true

#While loop that breaks when conditional is false (keyed in by user)
while [ "$CONDITIONAL" = "true" ]
do
	#The script begins with prompts using the echo command which is similar to printf to display text
	echo What would you like to know more about?
	echo 1. Connectivity
	echo 2. Host Information
	echo 3. Hardware Information
	echo 4. Exit Program
	printf "\n"

	#The read command takes in user input and the -p flag displays a prompt before accepting input
	#The variable holding the input is "n"
	read -p 'Option #: ' n

	#In the followong conditional statements, the action depends on the value of "n" 
	if [ "$n" == 1 ];
	then
		#Option 1 determines internet connectivity
		#wget command retrieves content from web servers
		#-q flag hides the output from wget
		#--spider supresses download from wget and only makes sure that webpage is there 
		#$? returns the exit value of the last executed command
		wget -q --spider www.google.com
		if [ $? -eq 0 ];
		then
			echo "Computer is online :)"
			printf "\n"
		else
			echo "Computer is offline :("
			printf "\n"
		fi

	elif [ "$n" == 2 ];
	then
		#Option 2 determines the hostname information thorugh the hostname -a -i flags
		HOST_NAME="$(hostname -a)"
		IPADDRESS="$(hostname -i)"
		echo Hostname:  "$HOST_NAME"
		echo Ip Address:  "$IPADDRESS" 
		printf "\n"
	elif [ "$n" == 3 ];
	then 
		#Option 3 similarly determines hardware information through the uname and free commands
		HARDWAREINFO="$(uname -i -s)"
		MEMORYSPACE="$(free -h)"
		echo OS/Hardware:  "$HARDWAREINFO"
		echo Memory Overview: 
		printf "\n"
		echo "$MEMORYSPACE"
		printf "\n"		

	elif [ "$n" == 4 ];
	then
		#Option 4 exits the program be breaking the while loop
		echo "GOODBYE"
		CONDITIONAL=false

	else
		#Error catching is user enters a non-valid option
		echo Unrecognized option! Please enter a vaid option.
		printf "\n"
	fi
done



