#include <Eigen/Dense>

// This version does not pull info from the xml files, that will be included in the next itteration
// This is where all the predefined parameters are set
class RobotParams
{

public:
    // Variables
    const float trunk_m = 4.713;
    const float hip_m = 0.696; 
    const float thigh_m = 1.013; 
    const float calf_m = 0.226;

    // Dynamic Properties
    float robot_m;
    Eigen::Matrix<float, 3, 3> I;         // Inertial Tensor - Body Frame

    // Functions
    const Eigen::MatrixXf GetInertia(){return I;}
    const float GetMass(){return robot_m;}
};

RobotParams::RobotParams(){
    I << 0.0158533, -3.66e-05, -6.11e-05, 
         -2.75e-05, 0.0377999, -2.75e-05, 
         -6.11e-05, -3.66e-05, 0.0456542;  
    
    robot_m = trunk_m + 4*hip_m + 4*thigh_m + 4*calf_m;
}

RobotParams::~RobotParams(){}

