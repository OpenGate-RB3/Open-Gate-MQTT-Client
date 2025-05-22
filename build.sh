#!/bin/bash

set -e # crash and stop

if [[ -z "$1" ]]; then
    echo "must set path to sdk root: ${1}";
    exit 1
fi

source $1/environment-setup-armv8-2a-qcom-linux

mkdir build

cd build

cmake .. -DCMAKE_BUILD_TYPE=Release

cmake --build . --target openGateMqttPython