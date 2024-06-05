// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/l1_regularizer_attrs.struct.toml
/* proj-data
{
  "generated_from": "50968fb8a3d43395d0eab7594f4935c0"
}
*/

#include "op-attrs/l1_regularizer_attrs.dtg.h"

#include <sstream>

namespace FlexFlow {
L1RegularizerAttrs::L1RegularizerAttrs(float const &lambda) : lambda(lambda) {}
bool L1RegularizerAttrs::operator==(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) == std::tie(other.lambda);
}
bool L1RegularizerAttrs::operator!=(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) != std::tie(other.lambda);
}
bool L1RegularizerAttrs::operator<(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) < std::tie(other.lambda);
}
bool L1RegularizerAttrs::operator>(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) > std::tie(other.lambda);
}
bool L1RegularizerAttrs::operator<=(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) <= std::tie(other.lambda);
}
bool L1RegularizerAttrs::operator>=(L1RegularizerAttrs const &other) const {
  return std::tie(this->lambda) >= std::tie(other.lambda);
}
} // namespace FlexFlow

namespace std {
size_t hash<FlexFlow::L1RegularizerAttrs>::operator()(
    FlexFlow::L1RegularizerAttrs const &x) const {
  size_t result = 0;
  result ^=
      std::hash<float>{}(x.lambda) + 0x9e3779b9 + (result << 6) + (result >> 2);
  return result;
}
} // namespace std

namespace nlohmann {
FlexFlow::L1RegularizerAttrs
    adl_serializer<FlexFlow::L1RegularizerAttrs>::from_json(json const &j) {
  return {j.at("lambda").template get<float>()};
}
void adl_serializer<FlexFlow::L1RegularizerAttrs>::to_json(
    json &j, FlexFlow::L1RegularizerAttrs const &v) {
  j["__type"] = "L1RegularizerAttrs";
  j["lambda"] = v.lambda;
}
} // namespace nlohmann

namespace rc {
Gen<FlexFlow::L1RegularizerAttrs>
    Arbitrary<FlexFlow::L1RegularizerAttrs>::arbitrary() {
  return gen::construct<FlexFlow::L1RegularizerAttrs>(gen::arbitrary<float>());
}
} // namespace rc

namespace FlexFlow {
std::string format_as(L1RegularizerAttrs const &x) {
  std::ostringstream oss;
  oss << "<L1RegularizerAttrs";
  oss << " lambda=" << x.lambda;
  oss << ">";
  return oss.str();
}
std::ostream &operator<<(std::ostream &s, L1RegularizerAttrs const &x) {
  return s << fmt::to_string(x);
}
} // namespace FlexFlow
