#include <xtensor/xmath.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xcomplex.hpp>
#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xreducer.hpp>
#include <xtensor/xrandom.hpp>
#include <xtensor/xaxis_iterator.hpp>
#include <xtensor/xaxis_slice_iterator.hpp>
#include <xtensor/xadapt.hpp>
#include <xtensor/xsort.hpp>
#include <xtensor/xindex_view.hpp>

// copy/assignement from Eigen expression
#define XTENSOR_EXPR_CTOR(ctorName, Class, Base, ExprType) \
template <typename Derived>\
ctorName(const ExprType<Derived> &m): Base(m) {}\
template<typename Derived>\
Class & operator=(const ExprType<Derived> &m)\
{\
    this->Base::operator=(m);\
    return *this;\
}

namespace anallat{

  // tensor types
  template <typename Derived>
  using TensorExpr = xt::xexpression<Derived>;
  
  //tensor types
  template<typename T, size_t ndimension>
    using Tensor = xt::xtensor<T, ndimension>;
  
  //run-time tensor dimension types
  template<typename T>
    using uTensor = xt::xarray<T>;

  template<typename T>
    using Mat = Tensor<T, 2>;

  using DMat = Mat<double>;
  using IMat = Mat<int>;
  using CDMat = Mat<std::complex<double>>;
  using CIMat = Mat<std::complex<int>>;

  // vector types
  template <typename T>
    using Vec = Tensor<T, 1>;

  using DVec = Vec<double>;

  using IVec = Vec<int>;
  using CDVec = Vec<std::complex<double>>;
  using CIVec = Vec<std::complex<int>>;

  #define FOR_VEC(vec, i)  for (size_t i = 0; i < (vec).size(); ++i)

}
