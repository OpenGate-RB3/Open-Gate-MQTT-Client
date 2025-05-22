//
// Created by andrew on 5/21/25.
//
#pragma once
#include <mqtt/async_client.h>
#include <string>

class MQTTClientWrapper {
public:
    MQTTClientWrapper(const std::string& broker, const std::string& clientId);

    void connect();
    void disconnect();
    void publish(const std::string& topic, const std::string& payload, int qos = 1, bool retained = false);

private:
    std::string broker_;
    std::string clientId_;
    mqtt::async_client client_;
};
