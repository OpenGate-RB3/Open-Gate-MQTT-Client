# Open-Gate MQTT client
## Made for the rb3 gen2
## RECOMMENDED to use the provided Dockerfile to build

## build requirements
A provided Docker file can be found in the docker-build-tool directory. Build the Docker file and copy out the library inside of it. Note that on non-arm machines you may need to configure Docker to run an arm image to produce the correct architecture output.


## first time build issue
Building the bindings for the first time, an error will occur; disregard it, run the script a second time, and the library will be compiled.

## external dependencies
* python3-dev (needs to be python 3.12)
* python3.12
