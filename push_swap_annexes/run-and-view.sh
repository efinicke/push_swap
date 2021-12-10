#!/bin/bash

make re

./push_swap $1 | ./viewer $1
