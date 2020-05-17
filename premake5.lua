workspace "Scrapyard-C"
   architecture "x64"
    configurations { 
       "Debug", 
       "Release",
       "Dist"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
project "Scrapyard"
   location "Scrapyard"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files {
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/src/**.h",
      "%{prj.name}/**.h"
   }

   includedirs {
      "%{prj.name}",
      "%{prj.name}/libs/spdlog/include"
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
      "Scrapyard",
      "Scrapyard/libs/spdlog/include"
   }

   links {
      "Scrapyard"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "system:macosx"
      systemversion "latest"
