import qbs
import QbsUtl

Product
{
    type: "application"
    consoleApplication: true

    Depends{name: "cpp"}
    Depends{name: "SharedLib"}
    Depends{name: "Yaml"}
    Depends{ name: "Qt"; submodules: ["core","network","sql"]}

    cpp.defines: project.cppDefines
    cpp.cxxLanguageVersion: project.cxxLanguageVersion

    cpp.systemIncludePaths: Qt.core.cpp.includePaths

    files:[
        "main.cpp"
    ]
}
