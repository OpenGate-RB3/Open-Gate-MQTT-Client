#include <mqttClient.hpp>
#include <pybind11/pybind11.h> // python module creation

MQTTClientWrapper::MQTTClientWrapper(const std::string &broker, const std::string &clientId)
: broker_(broker), clientId_(clientId), client_(broker, clientId) {}


void MQTTClientWrapper::connect() {
    mqtt::connect_options connOpts;
    connOpts.set_automatic_reconnect(true);
    connOpts.set_clean_session(false);
    connOpts.set_mqtt_version(MQTTVERSION_3_1_1);
    client_.connect(connOpts)->wait();
}

void MQTTClientWrapper::disconnect() {
    client_.disconnect()->wait();
}

void MQTTClientWrapper::publish(const std::string &topic, const std::string &payload, int qos, bool retained) {
    const auto msg = mqtt::make_message(topic,payload);
    msg->set_qos(qos);
    msg->set_retained(retained);
    client_.publish(msg)->wait();
}

namespace py = pybind11;

PYBIND11_MODULE(openGateMqttPython, m) {
    py::class_<MQTTClientWrapper>(m,"MQTTClient")
        .def(py::init<const std::string&, const std::string&>())
        .def("connect",&MQTTClientWrapper::connect)
        .def("disconnect", &MQTTClientWrapper::disconnect)
        .def("publish", &MQTTClientWrapper::publish,
            py::arg("topic"), py::arg("payload"),
            py::arg("qos") = 1, py::arg("retained") = false);
}