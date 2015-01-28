#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: calc

calc: calc.cc
	$(CC) $(CFLAGS) -o calc calc.cc

clean:
	rm calc
