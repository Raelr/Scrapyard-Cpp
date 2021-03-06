workspace "Scrapyard-C"
   architecture "x64"
   startproject "Sandbox"
    configurations { 
       "Debug", 
       "Release",
       "Dist"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Scrapyard/libs/GLFW/GLFW/include"
include "Scrapyard/libs/GLFW/"
    
project "Scrapyard"
   location "Scrapyard"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
   
   pchheader "scypch.h"
   pchsource "Scrapyard/src/scypch.cpp"

   files {
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/src/**.h",
   }

   includedirs {
      "%{prj.name}/src",
      "%{prj.name}/libs/spdlog/include",
      "%{IncludeDir.GLFW}",
   }

   links {
      "GLFW"
   }

   filter "configurations:Debug"
      defines { "SCY_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "SCY_RELEASE" }
      optimize "On"
   
   filter "configurations:Dist"
      defines { "SCY_DIST" }
      optimize "On"
   
   filter "system:macosx"
      systemversion "latest"
      staticruntime "on"

      links {
        "Cocoa.framework",
        "IOKit.framework",
        "CoreFoundation.framework",
      }

project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files {
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/src/**.h",
   }

   includedirs {
      "Scrapyard/src/",
      "Scrapyard/libs/spdlog/include",
   }

   links {
      "Scrapyard",
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "system:macosx"
      systemversion "latest"
      staticruntime "on"

      links {
        "Cocoa.framework",
        "IOKit.framework",
        "CoreFoundation.framework",
        "GLFW"
      }
