 # honestly 3.10 is oldest stable release still supported, but you really should upgrade
cmake_minimum_required(VERSION 3.10)
project(openGateMqtt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add pybind to openGateMqtt
add_subdirectory(3rdparty/pybind11)
 # build config for PAHO.CPP dependency
set(PAHO_WITH_MQTT_C ON)
set(PAHO_BUILD_STATIC ON)
set(PAHO_BUILD_SHARED OFF)
# since we are building a shared libary this needs to be set
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_subdirectory(3rdparty/paho.mqtt.cpp)

pybind11_add_module(openGateMqttPython src/mqttClient.cpp)
target_include_directories(openGateMqttPython PUBLIC include)
target_link_libraries(openGateMqttPython PUBLIC paho-mqttpp3-static)