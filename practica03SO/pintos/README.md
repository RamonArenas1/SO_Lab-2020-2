# Pintos Programming Exercises

## Introduction

This project aims to provide an organized way to solve every [pintos project](https://web.stanford.edu/class/cs140/projects/pintos/pintos.html#SEC_Contents). This project includes infrastructure to run the code from a docker image and every exercise provide a script to actually execute the tests to be graded in that specific exercise and the previous tests within the same project.

This project only has the code base, the dockerimage and some branches with the solutions, if you want to see the exercise descriptions you may visit the [this repo](https://github.com/alain-chevanier/pintos-exercise-descriptions).

## Software Dependencies

This project assumes the user is using a operating system with the following software:

* A bash console.
* Docker and Docker deamon

To use docker you can use an image from Dockerhub or build the image contained here. Use the following instructions in each case:

To pull the image from Dockerhub:
```bash
./docker-exec pull-image
```

To build the image locally:
```bash
./docker-exec build-image
```
To use this locally-built image you need to update the script `docker-exec` in the option `enter-container`, just comment and uncomment the lines in there and it should the the work.

To verify the installation, run the following instructions from a console:

1. Enter the bash console in the docker image
```bash
./docker-exec enter-container
```
2. Once you successfully accessed the console, move to the `threads` directory and compile the code.
```bash
cd /pintos/src/threads
make
```
3. Finally just run a test to verify that everything is up and running.
```bash
pintos run alarm-multiplo
```

