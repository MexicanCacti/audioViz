# audioViz

For .wav files contained in the "musicSources" folder, this project will analyze its contents and use its data to display graphics to the screen.

## Requirements

- CMake (version 3.10 or higher)
- A C++17 compatible compiler
- Ninja

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
