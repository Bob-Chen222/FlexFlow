// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/replica_parallel_dim.struct.toml
/* proj-data
{
  "generated_from": "f501393070c8d55a05c43dd73a81a8d7"
}
*/

#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_REPLICA_PARALLEL_DIM_DTG_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_REPLICA_PARALLEL_DIM_DTG_H

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "op-attrs/replica_type.dtg.h"
#include "rapidcheck.h"
#include <functional>
#include <ostream>
#include <tuple>

namespace FlexFlow {
struct ReplicaParallelDim {
  ReplicaParallelDim() = delete;
  ReplicaParallelDim(int const &degree,
                     ::FlexFlow::ReplicaType const &replica_type);

  bool operator==(ReplicaParallelDim const &) const;
  bool operator!=(ReplicaParallelDim const &) const;
  bool operator<(ReplicaParallelDim const &) const;
  bool operator>(ReplicaParallelDim const &) const;
  bool operator<=(ReplicaParallelDim const &) const;
  bool operator>=(ReplicaParallelDim const &) const;
  int degree;
  ::FlexFlow::ReplicaType replica_type;
};
} // namespace FlexFlow

namespace std {
template <>
struct hash<FlexFlow::ReplicaParallelDim> {
  size_t operator()(FlexFlow::ReplicaParallelDim const &) const;
};
} // namespace std

namespace nlohmann {
template <>
struct adl_serializer<FlexFlow::ReplicaParallelDim> {
  static FlexFlow::ReplicaParallelDim from_json(json const &);
  static void to_json(json &, FlexFlow::ReplicaParallelDim const &);
};
} // namespace nlohmann

namespace rc {
template <>
struct Arbitrary<FlexFlow::ReplicaParallelDim> {
  static Gen<FlexFlow::ReplicaParallelDim> arbitrary();
};
} // namespace rc

namespace FlexFlow {
std::string format_as(ReplicaParallelDim const &);
std::ostream &operator<<(std::ostream &, ReplicaParallelDim const &);
} // namespace FlexFlow

#endif // _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_REPLICA_PARALLEL_DIM_DTG_H
