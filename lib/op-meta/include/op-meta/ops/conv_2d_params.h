#ifndef _FLEXFLOW_CONV_2D_PARAMS_H
#define _FLEXFLOW_CONV_2D_PARAMS_H

#include "op-meta/parallel_tensor_shape.h"

namespace FlexFlow {

struct Conv2DParams {
public:
  bool is_valid(ParallelTensorShape const &input) const;

  ParallelTensorShape calculate_output_shape(ParallelTensorShape const &input_shape) const;
  ParallelTensorShape calculate_kernel_shape(ParallelTensorShape const &input_shape) const;
  ParallelTensorShape calculate_bias_shape(ParallelTensorShape const &input_shape) const;

  using AsConstTuple = std::tuple<int, int, int, int, int, int, int, int, ActiMode, bool>;
  AsConstTuple as_tuple() const;
public:
  int out_channels, kernel_h, kernel_w, stride_h, stride_w, padding_h,
      padding_w, groups;
  ActiMode activation;
  bool use_bias;

};

bool operator==(Conv2DParams const &, Conv2DParams const &);
bool operator<(Conv2DParams const &, Conv2DParams const &);

} 

namespace std {
template <>
struct hash<FlexFlow::Conv2DParams> {
  size_t operator()(FlexFlow::Conv2DParams const &) const;
};
}

#endif // _FLEXFLOW_CONV_2D_PARAMS_H