workspace "GE_Test"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug", "Release", "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GE_Test"
    location "GE_Test"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")

    files
    {
        "{prj.name}/src/**.h", "{prj.name}/src/**.cpp" 
    }


    includedirs
    {
        "%{prj.name}/3p/spdlog/include"
    }
 
    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GETEST_PLATFORM_WINDOWS",
            "GETEST_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "Debug"
        defines { "GETEST_DEBUG" }
        symbols "on"

    filter "Release"
        defines { "GETEST_RELEASE" }
        optimize "on"

    filter "Dist"
        defines { "GETEST_DIST" }
        optimize "on"
    
    -- fiter "configurations:Release"
    --     defines "GETEST_RELEASE"
    --     optimize "on"

    -- fiter "configurations:Dist"
    --     defines "GETEST_DIST"
    --     optimize "on"


project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/".. outputdir .. "/%{prj.name}")
        objdir ("bin-int/".. outputdir .. "/%{prj.name}")

    files
    {
        "{prj.name}/src/**.h", "{prj.name}/src/**.cpp" 
    }


    includedirs
    {
        "%{prj.name}/3p/spdlog/include",
        "GE_Test/src"
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
            "GETEST_PLATFORM_WINDOWS"
        }

    
    filter "Debug"
        defines { "GETEST_DEBUG" }
        symbols "on"

    filter "Release"
        defines { "GETEST_RELEASE" }
        optimize "on"

    filter "Dist"
        defines { "GETEST_DIST" }
        optimize "on"

    -- fiter "configurations:Debug"
    --     defines "GETEST_DEBUG"
    --     symbols "on"
    
    -- fiter "configurations:Release"
    --     defines "GETEST_RELEASE"
    --     optimize "on"

    -- fiter "configurations:Dist"
    --     defines "GETEST_DIST"
    --     optimize "on"