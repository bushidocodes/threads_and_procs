# Created on Sat Sep 07 2019:19:22:21
# Created by Ratnadeep Bhattacharya
# Copyright (c) 2019 George Washington University

CC = gcc
CFLAGS = -g -Werror -Wextra -Wall -pedantic --std=gnu99 -lpthread
THREAD=-pthread
BUILD=build/
RM=rm -rf
CFILES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(CFILES))
CFUNCS=$(wildcard fibonacci.*)

#all: $(BUILD)multi_procs $(BUILD)multi_threads
all: multiprocs multithreads

#$(BUILD)single_proc: single_proc.c fibonacci.h fibonacci.c
	#@$(CC) $(CFLAGS) -o $@ $^

#$(BUILD)multi_procs: multi_procs.c fibonacci.h fibonacci.c
multi_procs: multiprocs.c fibonacci.h fibonacci.c
	@$(CC) $(CFLAGS) -o $@ $^

#$(BUILD)multi_threads: multi_threads.c fibonacci.h fibonacci.c
multi_threads: multithreads.c fibonacci.h fibonacci.c
	@$(CC) $(CFLAGS) -o $@ $^ $(THREAD)

clean:
	@$(RM) $(BUILD)/*
