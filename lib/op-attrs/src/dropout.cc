#include "op-attrs/ops/dropout.h"
#include "utils/visitable_funcs.h"

namespace FlexFlow {

bool operator==(DropoutAttrs const &lhs, DropoutAttrs const &rhs) {
  return visit_eq(lhs, rhs);
}

bool operator<(DropoutAttrs const &lhs, DropoutAttrs const &rhs) {
  return visit_lt(lhs, rhs);
}

}

namespace std {
using ::FlexFlow::DropoutAttrs;

size_t hash<DropoutAttrs>::operator()(
    DropoutAttrs const &params) const {
  return visit_hash(params);
} 
}
