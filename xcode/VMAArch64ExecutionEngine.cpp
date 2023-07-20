//
//  VMAArch64ExecutionEngine.cpp
//  test_arm64
//
//  Created by songruiwang on 2023/7/19.
//
#include <capstone/capstone.h>
#include "VMAArch64ExecutionEngine.hpp"

class VMAArch64ExecutionEngine {
public:
  
  void Visit(cs_insn *insnPtr, size_t count) {
    for (size_t i = 0; i < count; i++) {
      Visit(&insnPtr[i]);
    }
  }
  
  void Visit(cs_insn *ins) {
    cs_arm64 *arm64;
    int i;
    cs_regs regs_read, regs_write;
    unsigned char regs_read_count, regs_write_count;
    unsigned char access;

    // detail can be NULL if SKIPDATA option is turned ON
    if (ins->detail == NULL)
      return;

    arm64 = &(ins->detail->arm64);
    if (arm64->op_count)
      
    
      printf("\id : %u\n", ins->id);
    switch (ins->id) {
      case ARM64_INS_ADD:
        VisitAdd(ins);
        break;
        
      default:
        break;
    }
  }
  
  void VisitAdd(cs_insn *ins) {
    cs_arm64 *arm64 = &(ins->detail->arm64);
    
    cs_arm64_op *op0 = &(arm64->operands[0]);
    cs_arm64_op *op1 = &(arm64->operands[1]);
    cs_arm64_op *op2 = &(arm64->operands[2]);
    
    // op2 need shift
    
    printf("0x%" PRIx64 ":\t%s\t%s\n", ins->address, ins->mnemonic, ins->op_str);
    printf("\top count: %u\n", arm64->op_count);
  }
};

void VMAArch64ExecutionEngineVisitInsn(cs_insn *insn, size_t count) {
  VMAArch64ExecutionEngine engine;
  engine.Visit(insn, count);
}
