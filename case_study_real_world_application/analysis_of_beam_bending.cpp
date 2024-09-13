#include <iostream>
#include <iomanip> 
using namespace std;

const double E = 210e9;  // Young's Modulus (Pascals)
const double I = 1e-6;   // Moment of Inertia (m^4)

// Function to get beam parameters from user input
void getBeamParameters(double &L, double &P, double &a) {
    // Prompt user for the length of the beam
    cout << "Enter the length of the beam (in meters): ";
    cin >> L;

    // Prompt user for the magnitude of the point load
    cout << "Enter the magnitude of the point load (in Newtons): ";
    cin >> P;

    // Prompt user for the position of the point load from the left end
    cout << "Enter the position of the point load from the left end (in meters): ";
    cin >> a;
}
double shearForce(double x, double P, double a) {
    if (x < a) {
        return P;   // Shear force is P if x is less than a
    } else if (x == a) {
        return 0;   // Shear force is 0 at the point load position
    } else {
        return -P;  // Shear force is -P if x is greater than a
    }
}
double bendingMoment(double x, double P, double a) {
    if (x <= a) {
        return P * (a - x);  // Bending moment for x less than or equal to a
    } else {
        return 0;  // Bending moment is 0 for x greater than a
    }
}

double deflection(double x, double P, double a, double L, double E, double I) {
    return (P * x * (a - x) * (L * L - x * x - a * a)) / (6 * E * I);
}


void displayResults(double L, double P, double a, double E, double I) {
    // Output header for the analysis
    cout << fixed << setprecision(2);  // Set precision for floating-point numbers
    cout << "Beam Bending Analysis\n";
    cout << "Position (x) | Shear Force (N) | Bending Moment (Nm) | Deflection (m)\n";
    cout << "---------------------------------------------------------------\n";

    // Loop through positions from 0 to L in increments of 0.1
    for (double x = 0; x <= L; x += 0.1) {
        double shear = shearForce(x, P, a);
        double moment = bendingMoment(x, P, a);
        double defl = deflection(x, P, a, L, E, I);

        // Print the results in a formatted table
        cout << setw(12) << x
             << " | " << setw(16) << shear
             << " | " << setw(18) << moment
             << " | " << setw(14) << defl
             << endl;
    }
}

int main() {
    double L, P, a;  // Declare variables for beam length, point load, and load position

    // Get beam parameters from the user
    getBeamParameters(L, P, a);

    // Call the function to display the analysis of the beam bending
    displayResults(L, P, a, E, I);

    // Return 0 to indicate successful completion
    return 0;
}