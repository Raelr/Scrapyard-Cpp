# Scrapyard-Cpp

Scrapyard-C is intended to be a small 2D game engine written in C++. The purpose of the project is to both learn C++ and build up knowledge on how game engines can be designed. The engine in question is going to be based off TheCherno's game engine: [Hazel](https://github.com/TheCherno/Hazel). The primary difference is that I aim to try and handle all rendering using [Vulkan](https://www.khronos.org/vulkan/), rather than OpenGL. As such I'll be following most of the architecture laid out by Hazel, but will be branching off on my own once the rendering stage has been reached. 

Scrapyard is intended to be a learning exercise, it is NOT intended to be used further than this. Scrapyard-C is also intended to be the C++ version of [Scrapyard](https://github.com/Raelr/scrapyard_engine) which was written in Rust. The intention is to use Scrapyard-C as a learning tool to hopefully allow further development of the Rust-based engine. 
 
## Current State:

Scrapyard-C is currently in the extreme infant stages of development. A suitable build system has been chosen ([{Premake](https://github.com/premake/premake-core)), and now the focus has moved to basic window management and cross-platform support. Scrapyard can now compile on both Windows and Mac (Windows requires the use of Visual Studio to work!). The focus now is to try and slowly integrate the windowing system on both platforms. Once both are done, the focus will shift toward Vulkan. 

## Build Guide

### MACOSX

Currently Scrapyard-C is compilable on both MacOSX and Windows. There are two method for building the project - the manual method and the automated method. 

#### Manual

You can use the manual method to gain more control over how the project can be build. This involved manually calling the build commands. 

Premake allows you to build the project for a range of IDEs and build systems. For this example, we'll build the project using the `gmake2` configuration.

To start, lets run the premake command from the project directory:

```
$ premake/premake5 gmake2
```

This command will generate a set of makefiles across the project which should handle the build process for us. To actually build the project, run the following terminal commmand:

```bash
$ make config=debug all
```

You should see output like the following:

```bash
==== Building Scrapyard (debug) ====
==== Building Sandbox (debug) ====
SandboxApp.cpp
Creating ../bin/Debug-macosx-x86_64/Sandbox
Linking Sandbox
```

The project has now been successfully built! This should now create an executable in our output directory. In this case, the output directory has been set to a directory which has the following convention:

> bin / <BUILD_CONFIGURATION> - <PLATFORM> - <ARCHITECTURE> - <PROJECT>

So for this example, the project was built to the following directory:

> bin/Debug-macosx-x86_64/Sandbox

Now all we need to do is run the project. To do this you can either navigate to the directory and click on the application, or run the project from the terminal using the command:

```bash
$ ./<EXECUTABLE_DIRECTORY>/Sandbox
```

So in our case we'd run:

```
$ ./bin/Debug-macosx-x86_64/Sandbox/Sandbox
```

You should see the following output: 

```bash
[2020-05-17 08:58:29.433] [info] Running Scrapyard with MacOSX build
[2020-05-17 08:58:29.434] [info] Running Scrapyard...
...
```

If you see this then congratulations! You successfully built Scrapyard-C!

Please note that currently the program runs a simple infinite loop to test the functionality. To exit just stop the process or use the keyboard shortcut: `^C`.

#### Automatic

The project has two bash scripts attached which should allow us to automate the process. Please note that these automatically use gmake2 to build the project. 

To run the builds script, use the following command from the project diretory:

```bash
$ ./BuildGmake.sh
```

You should get a similar output as before: 

```
Building configurations...
Running action 'gmake2'...
Done (46ms).
==== Building Scrapyard (debug) ====
==== Building Sandbox (debug) ====
```

Then simply run the RunProject script:

```bash
$ ./RunProject.sh

[2020-05-17 09:03:01.354] [info] Running Scrapyard with MacOSX build
[2020-05-17 09:03:01.355] [info] Running Scrapyard...
```

The project should now be successfully built!

### Running the project with Xcode

You can use premake to generate xcode files so that you can run it within the Xcode IDE. To do that, just run the premake command using the `xcode4` parameter:

```
$ premake/premake5 xcode4
```

This should generate the project files for xcode!

To find more information about Premake build configurations, please refer to their [official repository.](https://github.com/premake/premake-core/wiki/Using-Premake).

### WINDOWS

The recommended approach for building Scrapyard on Windows is via Visual Studio. Running the appropriate Premake command will generate the relevant project files on Visual Studio and make them available for building. The command for generating this is:

```
[From project directory]
premake\premake5.exe vs2019
```

This should generate the appropriate Visual Studio project files. Once this has been done, simply open the project in Visual Studio and build the solution! 
