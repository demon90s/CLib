#! /bin/bash

all_c=$(ls *.c)
all_h=$(ls *.h)

params="-npro -nip -nlp -npsl -npcs -i4 -ts4 -sob -l200 -ss -bl -bli 0"

indent $params $all_c
indent $params $all_h

rm -f *~