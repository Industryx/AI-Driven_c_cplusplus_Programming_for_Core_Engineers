//step-1
#include <iostream>
#include <cmath>

using namespace std;
//step-2
const double g = 9.81; 

//step-3
void simulatePendulum(double theta0, double L, double timeStep, double totalTime) {
    double omega = sqrt(g / L);

    for (double t = 0; t <= totalTime; t += timeStep) {
        double theta = theta0 * cos(omega * t);  
        cout << "Time: " << t << " s, Angular Displacement: " << theta << " rad" << endl;
    }
}
//step-4 defining the main function

int main() {
    // Declare variables for user input
    double theta0, L, timeStep, totalTime;

    // Prompt user for initial angular displacement
    cout << "Enter initial angular displacement (in radians): ";
    cin >> theta0;

    // Prompt user for length of the pendulum
    cout << "Enter the length of the pendulum (in meters): ";
    cin >> L;

    // Prompt user for time step of the simulation
    cout << "Enter the time step for the simulation (in seconds): ";
    cin >> timeStep;

    // Prompt user for total simulation time
    cout << "Enter the total simulation time (in seconds): ";
    cin >> totalTime;

    // Call the simulatePendulum function with the user's inputs
    simulatePendulum(theta0, L, timeStep, totalTime);

    // Return 0 to indicate successful completion
    return 0;
}