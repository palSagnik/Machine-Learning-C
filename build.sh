#!/bin/sh

set -xe
gcc -Wall -Wextra -o twoParam twoParam.c
gcc -Wall -Wextra -o or-gates ./Neural-Network/Single-Neuron/OR-gate.c -lm
gcc -Wall -Wextra -o and-gates ./Neural-Network/Single-Neuron/AND-gate.c -lm

