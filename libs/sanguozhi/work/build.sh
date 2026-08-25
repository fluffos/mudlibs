#!/bin/bash

if [ ! -d "fluffos" ]; then
    git clone https://gitee.com/mudren/fluffos.git
fi

cd fluffos && git checkout v2017 && cd src

if [ -f "../../local_options" ]; then
    cp -f ../../local_options .
fi

./build.FluffOS
make install