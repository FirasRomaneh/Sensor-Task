load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_library(
    name = "local",
    hdrs = ["local.h"],
)

cc_library(
    name = "Sensor",
    srcs = ["Sensor.hpp"],
    deps = ["local"],
)

cc_library(
    name = "Lidar",
    srcs = ["Lidar.hpp"],
    deps = ["local", "Sensor"],
)

cc_library(
    name = "Image",
    srcs = ["Image.hpp"],
    deps = ["local", "Sensor"],
)

cc_library(
    name = "GPS",
    srcs = ["GPS.hpp"],
    deps = ["local", "Sensor"],
)

cc_library(
    name = "IMU",
    srcs = ["IMU.hpp"],
    deps = ["local", "Sensor"],
)

cc_binary(
    name = "Driver",
    srcs = ["Driver.cpp"],
    deps = ["local", "Sensor", "Lidar", "Image", "GPS", "IMU"],
)