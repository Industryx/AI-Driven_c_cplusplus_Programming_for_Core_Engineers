# Project 1: Simulation of Pendulum
**Prompt 1: Including Libraries**
   ```plaintext
   Write only the necessary code to include the input/output stream library, the cmath library for mathematical functions, and declare the `std` namespace. Avoid including the main() function.
   ```

**Prompt 2: Defining Constants and Variables**
   ```plaintext
   Write code to define two constant variables, `g` and `pi`, with values for acceleration due to gravity and the value of pi, respectively. Then declare four variables for simulation purposes: `theta0` (initial angular displacement in radians), `L` (length of the pendulum in meters), `timeStep` (time step for simulation in seconds), and `totalTime` (total simulation time in seconds). Do not include the main() function.
   ```

**Prompt 3: Pendulum Simulation Function**
   ```plaintext
   Write a function named `simulatePendulum` that simulates pendulum motion. The function should take four parameters: `theta0` (initial angular displacement in radians), `L` (length of the pendulum in meters), `timeStep` (time step for simulation in seconds), and `totalTime` (total simulation time in seconds). Inside the function, calculate the angular frequency (omega) using the formula `sqrt(g / L)` where `g` is the acceleration due to gravity. Use a loop to iterate through each time step from 0 to `totalTime` incrementing by `timeStep`. For each time step, calculate the angular displacement `theta` using `theta0 * cos(omega * t)` and output the time and angular displacement. Include comments explaining each step of the process.
   ```

**Prompt 4: Main Function for Pendulum Simulation**
   ```plaintext
   Write a main function that performs the following tasks: Prompt the user to input values for `theta0` (initial angular displacement in radians), `L` (length of the pendulum in meters), `timeStep` (time step for simulation in seconds), and `totalTime` (total simulation time in seconds). Use `cout` for output and `cin` for input. Call the `simulatePendulum` function with the input values. Return 0 from the function. Include comments to explain each step of the process.
   ```

# Project 2: Analysis of Beam Bending
**Prompt 1: Beam Analysis - Defining Constants and Parameters**
   ```plaintext
   Write code to define two constant variables: `E` (Young's Modulus) with a value of 210e9 Pascals and `I` (Moment of Inertia) with a value of 1e-6 m^4. Then write a function named `getBeamParameters` that takes three reference parameters: `L` (length of the beam in meters), `P` (magnitude of the point load in Newtons), and `a` (position of the point load from the left end in meters). The function should prompt the user to input these values and store the inputs in the provided parameters. Do not include the main() function.
   ```

**Prompt 2: Beam Analysis - Shear Force and Bending Moment Functions**
   ```plaintext
   Write a function named `shearForce` that calculates the shear force at a point `x` along a beam given a point load `P` and its position `a`. The function should return `P` if `x` is less than `a`, `0` if `x` equals `a`, and `-P` if `x` is greater than `a`. Do not include the main() function.

   Write a function named `bendingMoment` that calculates the bending moment at a point `x` along a beam given a point load `P` and its position `a`. The function should return `P * (a - x)` if `x` is less than or equal to `a` and `0` if `x` is greater than `a`. Do not include the main() function.
   ```

**Prompt 3: Beam Analysis - Deflection Function**
   ```plaintext
   Write a function named `deflection` that calculates the deflection at a point `x` along a beam given a point load `P`, its position `a`, the length of the beam `L`, and the point `x`. The function should use the formula `(P * x * (a - x) * (pow(L, 2) - pow(x, 2) - pow(a, 2))) / (6 * E * I)`. Do not include the main() function, any constant values, or any `<cmath>` library imports.
   ```

**Prompt 4: Beam Analysis - Displaying Results Function**
   ```plaintext
   Write a function named `displayResults` that takes three parameters: `L` (length of the beam), `P` (magnitude of the point load), and `a` (position of the point load). The function should output a header for the analysis of beam bending and then loop through positions `x` from 0 to `L` in increments of 0.1. For each position, calculate the shear force, bending moment, and deflection using the functions `shearForce`, `bendingMoment`, and `deflection`. Print the position, shear force, bending moment, and deflection in a formatted table.
   ```

**Prompt 5: Main Function for Beam Analysis**
   ```plaintext
   Write a main function that declares the variables `L`, `P`, and `a`. Then call the function `getBeamParameters` to get the values for these variables from the user. After that, call the `displayResults` function to display the analysis of the beam bending. Finally, return 0. The code should match exactly as provided.
   ```
