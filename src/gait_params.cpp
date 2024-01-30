// This is where all the predefined parameters are set

class GaitParams
{
public:
    // Time Parameters
    float const Horizon_Time = 1.5;     // seconds
    float const Gait_Time = 0.3;        // gait cycle time
    float const Stance_Time = 0.1;      // for the entire gait cycle
    float Curr_Gait_Time = 0;           // current time in gait cycle
    static const int Nodes = 25;

    // Weighting functions and gains
    // Objective Function Positions Error Values
    int const Qpx = 0;
    int const Qpy = 0;
    int const Qpz = 0;
    int const Qrx = 0;
    int const Qry = 0;
    int const Qrz = 0;

    // Objective Function Velocity Error Values
    int const Qvx = 0;
    int const Qvy = 0;
    int const Qvz = 0;
    int const Qwx = 0;
    int const Qwy = 0;
    int const Qwz = 0;

    // Objective Function Control Input Values 
    int const Rx = 0;
    int const Ry = 0;
    int const Rz = 0;

    // Toe Operational Space Gains
    int const Kpx = 0;
    int const Kpy = 0;
    int const Kpz = 0;

    // Calculated Values
    const float Swing_Time = Gait_Time - Stance_Time;
    const float Horizon_dt = Horizon_Time/(Nodes-1);
};