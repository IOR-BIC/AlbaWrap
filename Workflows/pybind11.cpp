
#include "workflows.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace albaWrap;




PYBIND11_MODULE(albaWrap, m) {
    m.doc() = "documentation string";


    // functions
    m.def(
        "albaAnsysCDBtoVTK", &albaAnsysCDBtoVTK,
        py::arg("cdb_file_in"),
        py::arg("vtk_file_out")
        );

}
