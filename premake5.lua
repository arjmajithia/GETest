workspace "GE_Test"
  architecture "x64"
  startproject "Sandbox"
  configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "GE_Test/3p/glfw/include"
-- IncludeDir["GLFWsrc"] = "$(SolutionDir)%{prj.name}/3p/glfw/src"
include "GE_Test/3p/glfw"

project "GE_Test"
  location "GE_Test"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/".. outputdir .. "/%{prj.name}")
  objdir ("bin-int/".. outputdir .. "/%{prj.name}")

  pchheader "getpch.h"
  pchsource "%{prj.name}/src/getpch.cpp"

  files
  {
    "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"
  }

 -- "$(SolutionDir)%{prj.name}/3p/spdlog/include"
  includedirs
  {
    "%{prj.name}/src", "%{IncludeDir.GLFW}", 
    "$(SolutionDir)%{prj.name}/3p/spdlog/include"
  }

  links
  {
    "glfw",
    "opengl32.lib"
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines 
    {
        "GETEST_PLATFORM_WINDOWS", "GETEST_BUILD_DLL", "_WINDLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
    }

  filter "configurations:Debug"
    defines { "GETEST_DEBUG" }
    symbols "On"
  
  filter "configurations:Release"
    defines { "GETEST_RELEASE" }
    optimize "On"
    
  filter "configurations:Dist"
    defines { "GETEST_DIST" }
    optimize "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/".. outputdir .. "/%{prj.name}")
  objdir ("bin-int/".. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "$(SolutionDir)GE_Test/3p/spdlog/include", "GE_Test/src"
  }

  links
  {
    "GE_Test"
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "GETEST_PLATFORM_WINDOWS", "_MBCS"
    }

  filter "configurations:Debug"
    defines { "GETEST_DEBUG" }
    symbols "On"
  
  filter "configurations:Release"
    defines { "GETEST_RELEASE" }
    optimize "On"
    
  filter "configurations:Dist"
    defines { "GETEST_DIST" }
    optimize "On"