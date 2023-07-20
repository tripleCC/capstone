//
//  VMAArch64ExecutionEngine.hpp
//  test_arm64
//
//  Created by songruiwang on 2023/7/19.
//

#ifndef VMAArch64ExecutionEngine_hpp
#define VMAArch64ExecutionEngine_hpp

#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif

void VMAArch64ExecutionEngineVisitInsn(cs_insn *insn, size_t count);

#ifdef __cplusplus
}
#endif
#endif /* VMAArch64ExecutionEngine_hpp */
