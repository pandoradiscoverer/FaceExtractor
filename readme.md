# Face Detection and Extraction

This project is a face detection and extraction tool built using OpenCV and dlib. It can process both images and videos, detect faces, and save the extracted faces to a specified directory. The application provides a graphical user interface (GUI) built with Qt.

## Features

- **Face Detection**: Detect faces in images and videos using dlib's frontal face detector.
- **Face Extraction**: Extract and save detected faces as individual image files.
- **Progress Logging**: Display progress of the face extraction process.
- **Threaded Processing**: Utilize threading to ensure the GUI remains responsive during face detection and extraction.

## Requirements

### Windows

- **Visual Studio**: Community or higher version with C++ development tools.
- **CMake**: Version 3.10 or higher.
- **Qt**: Version 5 or higher.
- **OpenCV**: Version 4.6.0 or higher.
- **dlib**: Latest version.

### Linux (Ubuntu)

- **g++**: Version 7.5 or higher.
- **CMake**: Version 3.10 or higher.
- **Qt**: Version 5 or higher.
- **OpenCV**: Version 4.6.0 or higher.
- **dlib**: Latest version.

## Installation

### Windows

1. **Install Visual Studio**
   - Download and install Visual Studio from [Visual Studio website](https://visualstudio.microsoft.com/).
   - During installation, select "Desktop development with C++" and "CMake tools for Windows".

2. **Install CMake**
   - Download and install CMake from [CMake website](https://cmake.org/download/).
   - Add CMake to the system PATH during installation.

3. **Install Qt**
   - Download and install Qt from [Qt website](https://www.qt.io/download).

4. **Install OpenCV**
   - Download OpenCV from [OpenCV releases](https://opencv.org/releases/) and extract it to `C:\opencv`.
   - Add `C:\opencv\build\x64\vc14\bin` to the system PATH.
   - Set `OpenCV_DIR` environment variable to `C:\opencv\build\x64\vc14\lib`.

5. **Install dlib**
   - Download dlib from [dlib GitHub](https://github.com/davisking/dlib).
   - Open `Developer Command Prompt for VS`.
   - Navigate to the dlib directory and build it using CMake:
     ```bash
     mkdir build
     cd build
     cmake .. -G "Visual Studio 16 2019" -A x64
     cmake --build . --config Release
     ```
   - Set `dlib_DIR` environment variable to the dlib build directory.

### Linux (Ubuntu)

1. **Install Dependencies**
   ```bash
   sudo apt update
   sudo apt install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
   sudo apt install libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libdc1394-22-dev
   sudo apt install qt5-default
   ```

2. **Install OpenCV**
   ```bash
   sudo apt install libopencv-dev
   ```

3. **Install dlib**
   ```bash
   git clone https://github.com/davisking/dlib.git
   cd dlib
   mkdir build
   cd build
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
   - Edit `CMakeSettings.json` to configure OpenCV and dlib paths.
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
             "name": "OpenCV_DIR",
             "value": "C:/opencv/build",
             "type": "PATH"
           },
           {
             "name": "dlib_DIR",
             "value": "C:/path/to/dlib/build",
             "type": "PATH"
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
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Application**
   ```bash
   ./FaceDetection
   ```

## Usage

1. **Select Image/Video**: Click the "Select Image/Video" button and choose the file to process.
2. **Select Output Directory**: Click the "Select Output Directory" button and choose where to save the extracted faces.
3. **Extract Faces**: Click the "Extract Faces" button to start the extraction process.
4. **Stop Extraction**: Click the "Stop Extraction" button to halt the process at any time.
5. **View Log and Progress**: Monitor the extraction progress and log messages in the provided text area.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- **dlib**: [dlib library](http://dlib.net/)
- **OpenCV**: [OpenCV library](https://opencv.org/)
- **Qt**: [Qt framework](https://www.qt.io/)
```
