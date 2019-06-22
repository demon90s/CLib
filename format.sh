#! /bin/bash

astyle --style=stroustrup --indent=tab --align-pointer=type --recursive ./*.c,*.h

find . -name "*.orig" | xargs rm -f