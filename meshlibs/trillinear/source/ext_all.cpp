#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/buffer_info.h>
#include <omp.h>

#include "trillinear.h"

namespace py = pybind11;

template<typename Real>
void pybind_interpolatorf(py::module_& m);

template<typename Real>
void pybind_interpolatord(py::module_& m);
//void volumemerge(VolumeMerge& self, const py::buffer& full_vol, const py::buffer& split_vol, std::vector<Eigen::MatrixXf>& bboxes);
void pybind_volume_merge(py::module_& m);

void pybind_sharedmemoryheader(py::module_& m);

PYBIND11_MODULE(pyInterpolator, m) {
	pybind_interpolatord<double>(m);
	pybind_interpolatorf<float>(m);
	pybind_volume_merge(m);

	pybind_sharedmemoryheader(m);
}
//
//PYBIND11_MODULE(pyInterpolator, m) {
//    py::class_<CTrillinear> tril(m, "CTrillinear");
//
//    tril.def(py::init<>())
//        //	    .def(py::init<const MatrixXfr &, Eigen::Vector3i &, CTrillinear::Method, bool, float>())
//        .def("interpolate", &CTrillinear::interpolate, "some method interpolate")
//        .def_readwrite("_method", &CTrillinear::_method)
//        .def("debug_print", &CTrillinear::debug_print)
//        .def(py::init([](const py::buffer& b, bool bound_error, float fill_value) {
//        py::buffer_info info = b.request();
//        if (info.format != py::format_descriptor<float>::format() || info.ndim != 3) {
//            throw std::runtime_error("Incompatible buffer format!");
//        }
//        auto* v = new CTrillinear();//(info.shape[0], info.shape[1], (float*)info.ptr);
//        v->_img_array_ptr = (float*)(info.ptr);
//
//
//        for (int i = 0; i < info.ndim; i++)
//            v->img_shape(i) = info.shape[i];
//        v->_bound_error = bound_error;
//        v->_bound_value = fill_value;
//        v->step0 = v->img_shape(2);
//        v->step1 = v->img_shape(1) * v->img_shape(2);
//        //memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->rows() * v->cols()));
//
//        return v;
//            }));
//    /// Provide buffer access
////        .def_buffer([](CTrillinear &m) -> py::buffer_info {
////            return py::buffer_info(
////                m.data(),                          /* Pointer to buffer */
////                {m.rows(), m.cols()},              /* Buffer dimensions */
////                {sizeof(float) * size_t(m.cols()), /* Strides (in bytes) for each index */
////                 sizeof(float)});
////        });
//
//    py::enum_<CTrillinear::Method>(tril, "Method")
//        .value("NEAREST", CTrillinear::Method::NEAREST)
//        .value("LINEAR", CTrillinear::Method::LINEAR)
//        .export_values();
//}
