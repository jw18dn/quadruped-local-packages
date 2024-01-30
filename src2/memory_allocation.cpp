#include <iostream>
#include <vector>
#include <Eigen/Dense>  // Include Eigen header
#include "gait_params.cpp"


// This runs once at the begining of the program to allocation space

int main() {
    // Optimization Matricies
    Eigen::MatrixXd Aeq, Aiq;
    Eigen::VectorXd beq, biq;

    // Vector to store matrices
    std::vector<Eigen::Matrix<float, 12, 12>> A;
    std::vector<Eigen::Matrix<float, 12, 12>> B;
    std::vector<Eigen::Matrix<int, 4, 4>> contact_seq;   // Bianary contact sequence matrix
    std::vector<Eigen::Matrix<float, 3, 12>> qt_traj;       // Foot contact locations

    // Vector to store vectors
    std::vector<Eigen::Vector<float, GaitParams::Nodes*12>> u_traj;       
    std::vector<Eigen::Vector<float, GaitParams::Nodes*12>> q_traj;    

    // Initialize Matrix List with all zeros
    for (int i = 0; i < GaitParams::Nodes; ++i) {
        Eigen::MatrixXd matrix = Eigen::MatrixXd::Zero(12, 12);  
        A.push_back(matrix);
    }

    // Loop to modify matrices - move to other classes
    for (int i = 0; i < GaitParams::Nodes; ++i) {
        // Access and modify elements of the i-th matrix
        for (int row = 0; row < A[i].rows(); ++row) {
            for (int col = 0; col < matrixList[i].cols(); ++col) {
                // Modify matrix element, for example, set it to the row+col value
                matrixList[i](row, col) = row + col;
            }
        }
    }

    // Print the modified matrices
    for (int i = 0; i < GaitParams::Nodes; ++i) {
        std::cout << "Matrix " << i + 1 << ":\n" << matrixList[i] << "\n\n";
    }

    return 0;