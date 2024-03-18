#include <Eigen/Dense>
#include <nanobind/nanobind.h>
#include <nanobind/eigen/dense.h>
#include <iostream>

namespace nb = nanobind;

using namespace nb::literals;

Eigen::Vector3d zero_pivot = Eigen::Matrix<double, 3, 1>(0.0, 0.0, 0.0);

NB_MODULE(nanobind_example_ext, m) {
    // Does not work
    m.def("add_rotation", [](double angle, Eigen::Vector3d axis, Eigen::Vector3d pivot, bool also_at_rest_post){
        std::cout << "pivot: " << pivot << std::endl;
    }, "angle_deg"_a, "axis"_a, "pivot"_a = Eigen::Vector3d(0.0, 0.0, 0.0), "also_at_rest_pose"_a = true);

	// Does not work
    // m.def("add_rotation", [](double angle, Eigen::Vector3d axis, Eigen::Vector3d pivot, bool also_at_rest_post){
    //     std::cout << "pivot: " << pivot << std::endl;
    // }, "angle_deg"_a, "axis"_a, nb::arg("pivot") = zero_pivot, "also_at_rest_pose"_a = true);
    
    // Works
    // m.def("add_rotation", [](double angle, Eigen::Vector3d axis, Eigen::Vector3d pivot, bool also_at_rest_post){
    //     std::cout << "pivot: " << pivot << std::endl;
    // }, "angle_deg"_a, "axis"_a, "pivot"_a, "also_at_rest_pose"_a = true);

}
