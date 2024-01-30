#include <Eigen/Dense>
#include <memory>

#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

// The goal of this function is to automatically extract the data from the xml file to be used with the linearized estimate


struct InertialProperties {
    double mass;
    std::vector<double> position;
    std::vector<double> quaternion;
    std::vector<double> diagonalInertia;
};

// Function to parse XML and extract inertial properties
bool parseXML(const std::string& xmlFileName, InertialProperties& inertialProperties) {
    std::ifstream file(xmlFileName.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open XML file." << std::endl;
        return false;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    rapidxml::xml_document<> doc;
    doc.parse<0>(&buffer[0]);

    rapidxml::xml_node<>* inertialNode = doc.first_node("inertial");
    if (!inertialNode) {
        std::cerr << "Error: Inertial node not found in XML." << std::endl;
        return false;
    }

    // Extract mass
    inertialProperties.mass = std::stod(inertialNode->first_attribute("mass")->value());

    // Extract position
    rapidxml::xml_node<>* posNode = inertialNode->first_node("pos");
    for (rapidxml::xml_node<>* coordNode = posNode->first_node(); coordNode; coordNode = coordNode->next_sibling()) {
        inertialProperties.position.push_back(std::stod(coordNode->value()));
    }

    // Extract quaternion
    rapidxml::xml_node<>* quatNode = inertialNode->first_node("quat");
    for (rapidxml::xml_node<>* coordNode = quatNode->first_node(); coordNode; coordNode = coordNode->next_sibling()) {
        inertialProperties.quaternion.push_back(std::stod(coordNode->value()));
    }

    // Extract diagonal inertia
    rapidxml::xml_node<>* diagInertiaNode = inertialNode->first_node("diaginertia");
    for (rapidxml::xml_node<>* coordNode = diagInertiaNode->first_node(); coordNode; coordNode = coordNode->next_sibling()) {
        inertialProperties.diagonalInertia.push_back(std::stod(coordNode->value()));
    }

    return true;
}

int main() {
    InertialProperties inertialProperties;

    if (parseXML("your_xml_file.xml", inertialProperties)) {
        // Access the extracted inertial properties
        std::cout << "Mass: " << inertialProperties.mass << std::endl;
        std::cout << "Position: ";
        for (const auto& coord : inertialProperties.position) {
            std::cout << coord << " ";
        }
        std::cout << std::endl;

        // Similarly, print quaternion and diagonal inertia

        return 0;
    }

    return 1;
}



// This is where all the predefined parameters are set
class RobotParams
{

public:
    const std::unique_ptr<Eigen::Matrix<float, 3, 3>> I;         // Inertial Tensor - Body Frame
};

RobotParams::RobotParams(){
    I = 
}

RobotParams::~RobotParams(){

}