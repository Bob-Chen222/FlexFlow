#ifndef _FLEXFLOW_COMPILER_INCLUDE_COMPILER_FFI_COMPILER_H
#define _FLEXFLOW_COMPILER_INCLUDE_COMPILER_FFI_COMPILER_H

#include "flexflow/utils.h"

FLEXFLOW_FFI_BEGIN()

typedef enum {
  FLEXFLOW_COMPILER_STATUS_OK,
  FLEXFLOW_COMPILER_ERROR_UNKNOWN
} flexflow_compiler_error_t;

FLEXFLOW_FFI_END()

#endif