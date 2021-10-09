#!/usr/bin/bash

make

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

make clean

echo ""
echo ""
echo ""

# ./compilador ./python/wilcoxon.py
./compilador ./python/test1.py