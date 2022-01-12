// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "CDukiCalculations",
    products: [
        .library(
            name: "CDukiCalculations",
            targets: ["CDukiCalculations"]),
    ],
    targets: [
        .systemLibrary(name: "CDukiCalculations", pkgConfig: "./pkgConfig.pc"),
        .testTarget(
            name: "CDukiCalculationsTests",
            dependencies: ["CDukiCalculations"]),
    ]
)
