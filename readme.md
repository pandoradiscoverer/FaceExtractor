```markdown
# Face Detection and Extraction

This project is a face detection and extraction tool built using OpenCV, dlib, and wxWidgets. It processes both images and videos, detects faces, and saves the extracted faces to a specified directory. The application provides a user-friendly graphical interface (GUI) built with wxWidgets.

## Features

- **Face Detection**: Detect faces in images and videos using dlib's frontal face detector.
- **Face Extraction**: Extract and save detected faces as individual image files.
- **Progress Logging**: Real-time display of the face extraction process.
- **Threaded Processing**: Utilize multi-threading to ensure GUI responsiveness during face detection and extraction.
- **Cross-platform Support**: Works on Windows and Linux (Ubuntu).

## Requirements

### Windows

- **Visual Studio**: 2019 or later with C++ development tools.
- **CMake**: Version 3.14 or higher.
- **vcpkg**: Package manager for C++ libraries.

### Linux (Ubuntu)

- **g++**: Version 7.5 or higher.
- **CMake**: Version 3.14 or higher.

## Installation

### Windows

1. **Install Visual Studio**
   - Download and install Visual Studio from the [Visual Studio website](https://visualstudio.microsoft.com/).
   - During installation, select "Desktop development with C++" and "CMake tools for Windows".

2. **Install CMake**
   - Download and install CMake from the [CMake website](https://cmake.org/download/).
   - Add CMake to the system PATH during installation.

3. **Install vcpkg**
   - Clone the vcpkg repository:
     ```
     git clone https://github.com/Microsoft/vcpkg.git
     ```
   - Run the bootstrap script:
     ```
     .\vcpkg\bootstrap-vcpkg.bat
     ```
   - Add the vcpkg directory to your system PATH.

4. **Install Dependencies using vcpkg**
   ```
   vcpkg install opencv:x64-windows
   vcpkg install dlib:x64-windows
   vcpkg install wxwidgets:x64-windows
   ```

5. **Integrate vcpkg with Visual Studio**
   ```
   vcpkg integrate install
   ```

### Linux (Ubuntu)

1. **Install Dependencies**
   ```bash
   sudo apt update
   sudo apt install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
   sudo apt install libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libdc1394-22-dev
   sudo apt install libopencv-dev
   sudo apt install libwxgtk3.0-gtk3-dev
   ```

2. **Install dlib**
   ```bash
   git clone https://github.com/davisking/dlib.git
   cd dlib
   mkdir build && cd build
   cmake ..
   cmake --build .
   sudo make install
   sudo ldconfig
   ```

## Build and Run

### Windows

1. **Open Project in Visual Studio**
   - Open Visual Studio and select "Open a Local Folder".
   - Choose the project directory.

2. **Configure CMake**
   - Edit `CMakeSettings.json` to use vcpkg:
   ```json
   {
     "configurations": [
       {
         "name": "x64-Release",
         "generator": "Ninja",
         "configurationType": "Release",
         "inheritEnvironments": [ "msvc_x64_x64" ],
         "buildRoot": "${projectDir}\\out\\build\\${name}",
         "installRoot": "${projectDir}\\out\\install\\${name}",
         "cmakeCommandArgs": "",
         "buildCommandArgs": "",
         "ctestCommandArgs": "",
         "variables": [
           {
             "name": "CMAKE_TOOLCHAIN_FILE",
             "value": "${env.VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake",
             "type": "STRING"
           }
         ]
       }
     ]
   }
   ```

3. **Build and Run**
   - Build the project by selecting "Build > Build All".
   - Run the application by selecting "Debug > Start Without Debugging".

### Linux (Ubuntu)

1. **Clone the Repository**
   ```bash
   git clone <repository_url>
   cd FaceDetection
   ```

2. **Build the Project**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Run the Application**
   ```bash
   ./FaceDetection
   ```

## Usage

1. **Select Image/Video**: Click "Select Image/Video" and choose the file to process.
2. **Select Output Directory**: Click "Select Output Directory" and choose where to save the extracted faces.
3. **Extract Faces**: Click "Extract Faces" to start the extraction process.
4. **Stop Extraction**: Click "Stop Extraction" to halt the process at any time.
5. **View Log and Progress**: Monitor the extraction progress and log messages in the provided text area.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [dlib library](http://dlib.net/)
- [OpenCV library](https://opencv.org/)
- [wxWidgets framework](https://www.wxwidgets.org/)
- [vcpkg package manager](https://github.com/microsoft/vcpkg)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
```

