### Notes on Simulation and Modelling

#### 1. Introduction to Simulation and Modelling

**Simulation** is the process of creating a model of a real-world system and using it to study the system's behavior under different conditions. It helps in predicting outcomes, understanding complex systems, and testing hypotheses without directly interacting with the real system.

**Modelling** is the process of creating a mathematical representation of a system. Models are used in simulations to describe the system's dynamics, inputs, outputs, and relationships.

**Applications of Simulation and Modelling:**
- Weather forecasting
- Traffic flow analysis
- Mechanical system design
- Financial modeling

#### 2. Simple Simulation Techniques

**Monte Carlo Simulation:**
This technique uses random sampling to simulate complex systems. It is often used in risk analysis, decision-making, and systems with a high degree of uncertainty.

**Example:** Estimating the value of Pi by randomly placing points on a square and counting how many fall within a quarter-circle inside the square.

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int points = 1000000; // Number of random points
    int insideCircle = 0;

    for (int i = 0; i < points; i++) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;
        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }

    double pi = 4.0 * insideCircle / points;
    std::cout << "Estimated value of Pi: " << pi << std::endl;
    return 0;
}
```

#### 3. Modelling Mechanical Systems: The Spring-Mass-Damper System

The **Spring-Mass-Damper** system is a classic example used to demonstrate mechanical systems' behavior. This system consists of:
- A mass (m) attached to a spring with stiffness (k).
- A damper that resists the motion of the mass with damping coefficient (c).

**Real-Life Example:** Car suspension systems, where the spring represents the car's suspension, the mass is the car's body, and the damper reduces vibrations for a smoother ride.

**Mathematical Model:**

The equation of motion for a Spring-Mass-Damper system can be described by a second-order differential equation:

$$
m \frac{d^2x}{dt^2} + c \frac{dx}{dt} + kx = F(t)
$$

Where:
- x is the displacement of the mass.
- d²x/dt² is the acceleration.
- dx/dt is the velocity.
- F(t) is an external force applied to the system.

#### 4. C++ Implementation of the Spring-Mass-Damper System

To simulate the behavior of the Spring-Mass-Damper system, we can discretize the differential equation using numerical integration techniques such as the **Euler method**.

```cpp
#include <iostream>
#include <vector>

struct SpringMassDamper {
    double mass;       // Mass (m)
    double damping;    // Damping coefficient (c)
    double stiffness;  // Spring stiffness (k)
    double force;      // External force (F)

    // Method to calculate acceleration
    double acceleration(double displacement, double velocity) {
        return (force - damping * velocity - stiffness * displacement) / mass;
    }
};

int main() {
    SpringMassDamper system = {5.0, 0.5, 10.0, 1.0}; // Initialize system parameters
    double dt = 0.01;  // Time step for simulation
    int steps = 1000;  // Number of steps to simulate

    // Initial conditions
    double displacement = 0.0;  // Initial displacement (x)
    double velocity = 0.0;      // Initial velocity (dx/dt)

    // Vectors to store simulation results
    std::vector<double> displacements;
    std::vector<double> velocities;

    // Simulation loop
    for (int i = 0; i < steps; i++) {
        double accel = system.acceleration(displacement, velocity);
        velocity += accel * dt;                 // Update velocity using Euler method
        displacement += velocity * dt;          // Update displacement using Euler method

        displacements.push_back(displacement);  // Store results
        velocities.push_back(velocity);
    }

    // Display the results
    std::cout << "Displacement at the final step: " << displacements.back() << std::endl;
    std::cout << "Velocity at the final step: " << velocities.back() << std::endl;

    return 0;
}
```

#### 5. Conclusion

Simulation and modeling are powerful tools in engineering and other fields to analyze and predict system behavior. The simple techniques like Monte Carlo simulations and modeling of mechanical systems like the Spring-Mass-Damper system provide a foundational understanding of how different components interact under various conditions. Using C++ and numerical methods such as the Euler method, these simulations can be effectively implemented to solve real-world problems.