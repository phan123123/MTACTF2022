#!/bin/sh

sudo docker build -t "canary" . && sudo docker run -d -p "0.0.0.0:1338:1337" --cap-add=SYS_PTRACE --security-opt seccomp=unconfined canary
