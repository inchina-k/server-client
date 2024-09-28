# TCP server-client application

A TCP server-client application written in C++. The server is represented by an in-memory key-value storage and supports two types of requests: read and write.

## Prerequisites

- Microsoft Visual Studio (project was created using Visual Studio 2022) with CMake tools installed.
- Boost.Asio.
	The project assumes that `boost_1_86_0` is installed to the following location: `C:`.
	If the location or the boost version is different, the following lines in the `CMakeLists.txt` file should be modified:
 
    ```
    set(BOOST_ROOT "C:/boost_1_86_0")
    set(BOOST_INCLUDEDIR "C:/boost_1_86_0/boost")
    set(BOOST_LIBRARYDIR "C:/boost_1_86_0/stage/lib")
    ```

    Boost for the project was built using the following commands:

    ```
    cd C:/boost_1_86_0
    ./bootstrap.bat
    ./b2 --with-system toolset=msvc
    ```

## Instructions

### How to build

After the `server-client` project folder is opened in Visual Studio with CMake tools already installed, the IDE automatically detects the `CMakeLists.txt` file and configures the project according to the selected options in the top toolbar: build configuration (e.g., Debug, Release) and the platform (e.g., x64, x86).

When the project is configured, in order to build it the following key combination should be used:

```
Ctrl + Shift + B
```

This will create two executable files: server and client.

### How to run

#### Server

The server.exe is now located in the `server-client\out\build\x64-debug\server` or `server-client\out\build\x64-release\server` directory.

Open a terminal window:
```
Ctrl + `
```

Go to the directory where .exe file is stored:
```
'cd out\build\x64-debug\server' for debug
'cd out\build\x64-release\server' for release
```

Run the file:
```
./server
```

The server should now be listening on port 8080.

#### Client

The client.exe is now located in the `server-client\out\build\x64-debug\client` or ``server-client\out\build\x64-release\client`` directory.

Open a NEW terminal window:
```
Ctrl + `
```

Go to the directory where .exe file is stored:
```
'cd out\build\x64-debug\client' for debug
'cd out\build\x64-release\client' for release
```

Run the file providing two arguments <host> and <port>, e.g:
```
./client 127.0.0.1 8080
```

The client is now connected to the running server.