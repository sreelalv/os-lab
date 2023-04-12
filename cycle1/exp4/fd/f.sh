#!/bin/bash
read -p "Enter the specific character " ch 

ls -A | grep "^${ch}" -c 
