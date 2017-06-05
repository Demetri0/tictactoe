import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    profile: "c++11"
    consoleApplication: true
    files: [
        "abstractplayer.h",
        "board.cpp",
        "board.h",
        "consoledrawer.cpp",
        "consoledrawer.h",
        "game.cpp",
        "game.h",
        "localplayer.cpp",
        "localplayer.h",
        "main.cpp",
        "randomplayer.cpp",
        "randomplayer.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
    cpp.cxxLanguageVersion: "c++11"
}

