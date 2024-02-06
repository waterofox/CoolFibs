QtModule {
    qtModuleName: "Network"
    Depends { name: "Qt"; submodules: ["core"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6Network"
    libNameForLinkerRelease: "Qt6Network"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Network.a"
    pluginTypes: ["networkaccess","networkinformation","tls"]
    moduleConfig: ["shared"]
    cpp.defines: ["QT_NETWORK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtNetwork"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["network"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
