/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2014 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include <alloy/hir/block.h>

#include <alloy/hir/instr.h>

using namespace alloy;
using namespace alloy::hir;


void Block::AssertNoCycles() {
  Instr* hare = instr_head;
  Instr* tortoise = instr_head;
  if (!hare) {
    return;
  }
  while (hare = hare->next) {
    if (hare == tortoise) {
      // Cycle!
      XEASSERTALWAYS();
    }
    hare = hare->next;
    if (hare == tortoise) {
      // Cycle!
      XEASSERTALWAYS();
    }
    tortoise = tortoise->next;
    if (!hare || !tortoise) {
      return;
    }
  }
}
