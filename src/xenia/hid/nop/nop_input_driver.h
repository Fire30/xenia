/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_HID_NOP_NOP_INPUT_DRIVER_H_
#define XENIA_HID_NOP_NOP_INPUT_DRIVER_H_

#include <xenia/core.h>

#include <xenia/hid/input_driver.h>
#include <xenia/hid/nop/nop_hid-private.h>


namespace xe {
namespace hid {
namespace nop {


class NopInputDriver : public InputDriver {
public:
  NopInputDriver(InputSystem* input_system);
  virtual ~NopInputDriver();

  virtual X_STATUS Setup();

  virtual X_RESULT GetCapabilities(
      uint32_t user_index, uint32_t flags, X_INPUT_CAPABILITIES& out_caps);
  virtual X_RESULT GetState(
      uint32_t user_index, X_INPUT_STATE& out_state);
  virtual X_RESULT SetState(
      uint32_t user_index, X_INPUT_VIBRATION& vibration);
  virtual X_RESULT GetKeystroke(
      uint32_t user_index, uint32_t flags, X_INPUT_KEYSTROKE& out_keystroke);

protected:
};


}  // namespace nop
}  // namespace hid
}  // namespace xe


#endif  // XENIA_HID_NOP_NOP_INPUT_DRIVER_H_
