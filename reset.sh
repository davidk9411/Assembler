#!/bin/bash
rm -r outputs/bin/*
rm -r outputs/text/*
rm -r outputs/process/*

rmdir outputs/bin
rmdir outputs/text
rmdir outputs/process
rmdir outputs

make clear