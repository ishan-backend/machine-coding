#include "Subscriber.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

boost::uuids::random_generator Subscriber::rg; // initialisation of static member outside class

Subscriber::Subscriber(std::string Name): name(Name) {
    id = boost::uuids::to_string(Subscriber::rg());
}

std::string Subscriber::getId() const {
    return id;
}

void Subscriber::consumeMessage(Message msg) {
    // Here in consume Message we are just printing the message contents
    std::cout << "Sub " << name << " consuming... " << msg.getMessage() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Sub " << name << " got message: " << msg.getMessage() << std::endl;
}