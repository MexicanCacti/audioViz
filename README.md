# YourProject

This project uses GLFW for window creation and input handling.

## Requirements

- CMake (version 3.10 or higher)
- A C++17 compatible compiler
- Ninja
- GLFW (the library is included in the `libs/glfw/lib` directory)
- GLAD (Included in `libs/glfw/include` directory)

## Setup Instructions

1. Clone the repository:
    ```bash
    git clone https://github.com/MexicanCacti/audioViz.git
    cd audioViz
    ```

2. Create a build directory:
    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to generate the build system:
    ```bash
    cmake -G "Ninja" ..
    ```

4. Build the project:
    ```bash
    ninja
    ```

5. Run the executable:
    ```bash
    ./audioViz
    ```

## Building GLFW from Source (Optional)

If you need to build GLFW yourself, run the following commands:

1. Clone GLFW:
    ```bash
    git clone https://github.com/glfw/glfw.git
    cd glfw
    ```

2. Create a build directory:
    ```bash
    mkdir build
    cd build
    ```

3. Build GLFW using Ninja:
    ```bash
    cmake -G "Ninja" ..
    ninja
    ```

4. Copy the `libglfw3.dll.a` and `glfw3.dll` files to the `libs/glfw/lib` directory in this project.
