workspace "SortingAlgorithms"
    architecture "x86_64"
    startproject "Demo"

    outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    configurations 
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

project "Demo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

    files {
        "src/demo.cpp",
        "%{wks.location}/inlcude/**.h",
        "%{wks.location}/inlcude/**.cpp"
    }

    includedirs 
    {
        "%{wks.location}/include/"
    }
    filter "system:windows"
        systemversion "latest"
    
        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"