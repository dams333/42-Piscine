#!/bin/bash

#clear save folder
rm -Rf save/*

#copy all document in save folder
cp -R ~/Documents/Piscine save
cp ~/shell/save.sh save
cp ~/.zshrc save
cp ~/.vimrc save

#clear gits
cd save
find . -name "*.git" -mindepth 2 -type d -exec rm -rf {} \;

#git save
read -p 'Choisir un nom de commit: ' commit_name

git add .
git commit -m '$commit_name'
git push
