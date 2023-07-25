//
//  VMAArch64ExecutionEngine.cpp
//  test_arm64
//
//  Created by songruiwang on 2023/7/19.
//
#include <capstone/capstone.h>
#include "VMAArch64ExecutionEngine.hpp"

#define GET_INSTRINFO_ENUM
#include "../arch/AArch64/AArch64GenInstrInfo.inc"

#define VM_AARCH64_INVALID_OP_REG_INDEX 32

class VMAArch64ExecutionEngine {
public:
  
  void Visit(cs_insn *insnPtr, size_t count) {
    for (size_t i = 0; i < count; i++) {
      Visit(&insnPtr[i]);
    }
  }
  
  void Visit(cs_insn *ins) {
    switch (ins->mc_opcode) {
      case AArch64_ADDXrs:
        VisitAdd(ins);
        break;
      default:
        break;
    }
    
    
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

  unsigned GetOpRegIndex(cs_arm64_op *op) {
    switch (op->reg) {
      case ARM64_REG_B0:
      case ARM64_REG_D0:
      case ARM64_REG_H0:
        return 0;
        break;
        
      default:
        return VM_AARCH64_INVALID_OP_REG_INDEX;
    }
  }

  void VisitAdd(cs_insn *ins) {
    cs_arm64 *arm64 = &(ins->detail->arm64);
    
    cs_arm64_op *op0 = &(arm64->operands[0]);
    cs_arm64_op *op1 = &(arm64->operands[1]);
    cs_arm64_op *op2 = &(arm64->operands[2]);
    
    GetOpRegIndex(op0);
    GetOpRegIndex(op1);
    GetOpRegIndex(op2);
    
    if (op2->shift.type) {
      op2->shift.value;
    }
    
    
    
    
    // op2 need shift
    
    printf("0x%" PRIx64 ":\t%s\t%s\n", ins->address, ins->mnemonic, ins->op_str);
    printf("\top count: %u %u\n", arm64->op_count, ins->mc_opcode);
  }
};

void VMAArch64ExecutionEngineVisitInsn(cs_insn *insn, size_t count) {
  VMAArch64ExecutionEngine engine;
  engine.Visit(insn, count);
}
