# Open-Gate MQTT client
## Made for the rb3 gen2
## RECOMMENDED to use provided dockerfile to build

## build requirements
A provided docker file can be found in the docker-build-tool directory, build the dockerfile, and copy out the library found inside of it. Note on non-arm machines you may need to configure docker to run an arm image to produce the check architecture output.


## first time build issue
If building the bindings for the first time an error will occur, disregard it run the script a second time and the library will be compiled.

## external dependencies
* python3-dev (needs to be python 3.12)
* python3.12
