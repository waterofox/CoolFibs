import qbs
import "project_base.qbs" as ProjectBase
ProjectBase
{
    name: "CoolFibs";
    references:[
        "src/shared/shared.qbs",
        "src/yaml/yaml.qbs",
        "src/CoolFibs/CoolFibs.qbs"
    ]
}
