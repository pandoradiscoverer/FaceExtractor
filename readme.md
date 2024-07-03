# Face Detection and Extraction

This project is a face detection and extraction tool built using OpenCV, dlib, and qt5. It processes both images and videos, detects faces, and saves the extracted faces to a specified directory. The application provides a user-friendly graphical interface (GUI) built with qt5.

## Features

- **Face Detection**: Detect faces in images and videos using dlib's frontal face detector.
- **Face Extraction**: Extract and save detected faces as individual image files.
- **Progress Logging**: Real-time display of the face extraction process.
- **Threaded Processing**: Utilize multi-threading to ensure GUI responsiveness during face detection and extraction.

## Requirements

- **g++**: Version 7.5 or higher.
- **CMake**: Version 3.14 or higher.

## Installation


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
- [qt5 framework](https://www.qt.io/)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.


