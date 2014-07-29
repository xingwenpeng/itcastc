#! /bin/sh
committime=$(date);

git add ./*;
git commit -m "$committime";
git push origin master;

