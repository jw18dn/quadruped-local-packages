#include <cmath>
#include "robot_params.cpp"

// IN: simulated states, footstep plan
// OUT: A, B, f for individual nodes


class LinearDynamics
{
private:
    // Robot Parameters
    RobotParams robot_properties;

    // Matrix Components
    // std::unique_ptr<Eigen::Matrix<float, 3, 3>> X;         // Rotation Matrix - Extimated w/ small roll & pitch angles
    Eigen::Matrix<float, 3, 3> R;         // Rotation Matrix - Extimated w/ small roll & pitch angles
    Eigen::Matrix<float, 3, 3> I;         // Inertial Tensor - World Frame
    Eigen::Matrix<float, 3, 3> Eye;       // Identity Matrix
    Eigen::Vector<float, 12> G;           // Gravity Vector

    // Matrix 
    Eigen::Matrix<float, 3, 4> r;           // Vector from body COM to toe position 

    // State Space Matricies
    static Eigen::Matrix<float, 12, 12> A;        // A Matrix
    static Eigen::MatrixXf B;                     // B Matrix

    // Temporary Variables for Testing
    int numb_contacts = 2;
    int phi = 1;
    Eigen::Vector<float, 4> Gait_Seq; 

public:
    LinearDynamics(/* args */);
    ~LinearDynamics();
    void StateSpace();
    void Print();
};

LinearDynamics::LinearDynamics(/* args */)
{
    // Dynamic Matricies/Vectors Initialization
    R = Eigen::MatrixXf::Zero(3,3);         // Body Rotation
    I = robot_properties.GetInertia();      // Inertia Matrix
    G = Eigen::VectorXf::Zero(12);          // Gravity Vecotor

    // Constant Matrix Initialization
    Eye = Eigen::MatrixXf::Identity(3,3);   // Identity Matrix

    // State Space Matrix Initialization
    A = Eigen::MatrixXf::Zero(12,12);
    B = Eigen::MatrixXf::Zero(12,numb_contacts*3);

    // Foot Vector Initializers
    r = Eigen::MatrixXf::Zero(3,4);       
    Gait_Seq << 1, 0, 1, 0;  
}

LinearDynamics::~LinearDynamics()
{
}

void LinearDynamics::StateSpace(){
    // Formulate the rotation matrix
    R << cos(phi), sin(phi),  0.0,
        -sin(phi), cos(phi),  0.0,
            0.0,      0.0,    1.0;

    // Find the body frame Inertia
    Eigen::Matrix<float, 3, 3> I_inv = I.inverse();
    Eigen::Matrix<float, 3, 3> I_body = R*I_inv*R.transpose();

    // Formulate the A Matrix
    A.block<3,3>(7,1) = R;
    A.block<3,3>(10,4) = Eye;

    // Formulate the B Matrix
    for(int i = 0; i<4; i++){
        if(Gait_Seq[i] = 1){
            Eigen::Vector<float, 3> r = p_foot - p_com;
            B.block<3,3>(6,i*3) = I_inv.cross(r); // <-- still need to get r into here (vectors from contact location to COM)
        }
    }
}

void LinearDynamics::StepLengthVector(){
    // r = v_des*ts + (v_des - v_act)*ts;
}