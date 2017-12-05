#ifndef _SERIAL_EIGEN_HPP_
#define _SERIAL_EIGEN_HPP_

#include "cereal/archives/binary.hpp"

#include <Eigen/Dense>

namespace cereal {

template <class Archive, class _Scalar, int _Rows, int _Cols,
        int _Options, int _MaxRows, int _MaxCols> inline
void save(Archive& archive, const Eigen::Array<_Scalar, _Rows, _Cols,
        _Options, _MaxRows, _MaxCols>& array) {
    archive(array.x());
    archive(array.y());
}

template <class Archive, class _Scalar, int _Rows, int _Cols,
        int _Options, int _MaxRows, int _MaxCols> inline
void load(Archive& archive, Eigen::Array<_Scalar, _Rows, _Cols,
        _Options, _MaxRows, _MaxCols>& array) {
    _Scalar x, y;

    archive(x);
    archive(y);

    array.x() = x;
    array.y() = y;
}

template <class Archive, class _Scalar, int _Rows, int _Cols,
        int _Options, int _MaxRows, int _MaxCols> inline
void save(Archive& archive, const Eigen::Matrix<_Scalar, _Rows, _Cols,
        _Options, _MaxRows, _MaxCols>& matrix) {
    int rows = matrix.rows();
    int cols = matrix.cols();

    archive(rows);
    archive(cols);
    archive(binary_data(matrix.data(), rows * cols * sizeof(_Scalar)));
}

template <class Archive, class _Scalar, int _Rows, int _Cols,
        int _Options, int _MaxRows, int _MaxCols> inline
void load(Archive& archive, Eigen::Matrix<_Scalar, _Rows, _Cols,
        _Options, _MaxRows, _MaxCols>& matrix) {
    int rows, cols;

    archive(rows);
    archive(cols);

    matrix.resize(rows, cols);
    archive(binary_data(matrix.data(),
            static_cast<std::size_t>(rows * cols * sizeof(_Scalar))));
}

}  // namespace cereal

#endif  // _SERIAL_EIGEN_HPP_
