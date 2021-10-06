
#include "sum.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace baselib;




PYBIND11_MODULE(baselib, m) {
    m.doc() = "documentation string";


    // functions
    m.def(
        "_sum_py", &sum_py,
        py::arg("a"),
        py::arg("b")
        );

}
