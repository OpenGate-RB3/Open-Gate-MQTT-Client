# Open-Gate MQTT client
## Made for the rb3 gen2
## RECOMMENDED to use the provided Dockerfile to build

## build requirements
A provided Docker file can be found in the docker-build-tool directory. Build the Docker file and copy the library to your host machine. Note that on non-arm machines, you will need to configure Docker to run an arm image to produce the correct architecture output.


## first time build issue
Building the bindings for the first time will make an error; you can just disregard it, run the script a second time, and the library will be compiled.

## external dependencies
* python3-dev (needs to be python 3.12)
* python3.12

## Generate .pyi file for PyLance IntelliSense
To generate .pyi files for intellisense, you must install the mypy pip package for the stubgen utility. After doing so, you will need to run this command \
 ```sh
stubgen -m openGateMqttPython -o .
```
This will generate a pyi file that can be used to provide intellisense for Pylance and other LSPs.
