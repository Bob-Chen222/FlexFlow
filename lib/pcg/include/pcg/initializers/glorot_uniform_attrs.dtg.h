// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/pcg/include/pcg/initializers/glorot_uniform_attrs.struct.toml
/* proj-data
{
  "generated_from": "a268b411b6d378faa11e60c8517d7be5"
}
*/

#ifndef _FLEXFLOW_LIB_PCG_INCLUDE_PCG_INITIALIZERS_GLOROT_UNIFORM_ATTRS_DTG_H
#define _FLEXFLOW_LIB_PCG_INCLUDE_PCG_INITIALIZERS_GLOROT_UNIFORM_ATTRS_DTG_H

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "rapidcheck.h"
#include <functional>
#include <ostream>
#include <tuple>

namespace FlexFlow {
struct GlorotUniformAttrs {
  GlorotUniformAttrs() = delete;
  GlorotUniformAttrs(int const &seed);

  bool operator==(GlorotUniformAttrs const &) const;
  bool operator!=(GlorotUniformAttrs const &) const;
  bool operator<(GlorotUniformAttrs const &) const;
  bool operator>(GlorotUniformAttrs const &) const;
  bool operator<=(GlorotUniformAttrs const &) const;
  bool operator>=(GlorotUniformAttrs const &) const;
  int seed;
};
} // namespace FlexFlow

namespace std {
template <>
struct hash<FlexFlow::GlorotUniformAttrs> {
  size_t operator()(FlexFlow::GlorotUniformAttrs const &) const;
};
} // namespace std

namespace nlohmann {
template <>
struct adl_serializer<FlexFlow::GlorotUniformAttrs> {
  static FlexFlow::GlorotUniformAttrs from_json(json const &);
  static void to_json(json &, FlexFlow::GlorotUniformAttrs const &);
};
} // namespace nlohmann

namespace rc {
template <>
struct Arbitrary<FlexFlow::GlorotUniformAttrs> {
  static Gen<FlexFlow::GlorotUniformAttrs> arbitrary();
};
} // namespace rc

namespace FlexFlow {
std::string format_as(GlorotUniformAttrs const &);
std::ostream &operator<<(std::ostream &, GlorotUniformAttrs const &);
} // namespace FlexFlow

#endif // _FLEXFLOW_LIB_PCG_INCLUDE_PCG_INITIALIZERS_GLOROT_UNIFORM_ATTRS_DTG_H
