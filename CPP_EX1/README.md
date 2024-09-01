
# Graph Algorithms Project

## Overview

This project is a C++ implementation of graph-related algorithms, including graph construction, traversal, and basic operations. The project includes several components that demonstrate the functionality of the implemented algorithms. Additionally, it includes unit tests to ensure the correctness of the code.

## File Structure

- **Algorithms.cpp**: Implementation of the graph algorithms.
- **Algorithms.hpp**: Header file for the algorithms, defining the necessary classes and functions.
- **Graph.cpp**: Contains the implementation of the graph data structure.
- **Graph.hpp**: Header file defining the graph class and its associated methods.
- **Demo.cpp**: A demo file to showcase how to use the implemented graph algorithms.
- **Test.cpp**: Unit tests for the graph algorithms using the doctest framework.
- **TestCounter.cpp**: Additional tests or utilities for counting operations in the graph algorithms.
- **doctest.h**: Header file for the doctest framework, used for writing unit tests.
- **Makefile**: The makefile to compile and link all the source files and generate the executable.

## Compilation and Execution

To compile the project, simply use the `make` command:

```bash
make
```

This command will compile all the source files and generate an executable named `Demo`. You can run the executable with the following command:

```bash
./run_demo
```

To clean the project (i.e., remove all the generated object files and executables), use the command:

```bash
make clean
```

## Testing

Unit tests are included in the `Test.cpp` file, and they use the doctest framework. After compiling the project with `make`, you can run the tests with:

```bash
./run_tests
```

This will execute all the tests and output the results in the terminal.

## Dependencies

- **C++11 or higher**: The project uses features from C++11, so make sure your compiler supports this standard or higher.
- **doctest**: The unit testing framework used in this project. The header file `doctest.h` is included in the project files.

## Contributions

If you wish to contribute to this project, feel free to fork the repository and submit a pull request. Make sure to follow the project's coding standards and include tests for any new features or bug fixes.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as you see fit.
