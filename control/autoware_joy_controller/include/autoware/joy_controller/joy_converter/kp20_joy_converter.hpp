// Copyright 2022 Leo Drive Teknoloji A.Ş., Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef JOY_CONTROLLER__JOY_CONVERTER__KP20_JOY_CONVERTER_HPP_
#define JOY_CONTROLLER__JOY_CONVERTER__KP20_JOY_CONVERTER_HPP_

#include "autoware/joy_controller/joy_converter/joy_converter_base.hpp"

#include <algorithm>

namespace joy_controller
{
class KP20_JoyConverter : public JoyConverterBase
{
public:
  explicit KP20_JoyConverter(const sensor_msgs::msg::Joy & j) : j_(j) {}

  float accel() const { return std::max(0.0f, -((RT_Long() - 1.0f) / 2.0f)); }

  float brake() const { return std::max(0.0f, -((LT_Long() - 1.0f) / 2.0f)); }

  float steer() const { return RStickLeftRight(); }

  bool shift_up() const { return CursorUpDown() == 1.0f; }
  bool shift_down() const { return CursorUpDown() == -1.0f; }
  bool shift_drive() const { return CursorLeftRight() == 1.0f; }
  bool shift_reverse() const { return CursorLeftRight() == -1.0f; }

  bool turn_signal_left() const { return LB(); }
  bool turn_signal_right() const { return RB(); }
  bool clear_turn_signal() const { return X(); }

  bool gate_mode() const { return A(); }

  bool emergency_stop() const { return Back(); }
  bool clear_emergency_stop() const { return Start(); }

  bool autoware_engage() const { return B(); }
  bool autoware_disengage() const { return Y(); }

  bool vehicle_engage() const { return M2(); }
  bool vehicle_disengage() const { return M1(); }

private:
  float LStickLeftRight() const { return j_.axes.at(0); }
  float LStickUpDown() const { return j_.axes.at(1); }
  float RStickLeftRight() const { return j_.axes.at(2); }
  float RStickUpDown() const { return j_.axes.at(3); }
  float RT_Long() const { return j_.axes.at(4); }
  float LT_Long() const { return j_.axes.at(5); }
  float CursorLeftRight() const { return j_.axes.at(6); }
  float CursorUpDown() const { return j_.axes.at(7); }


  bool A() const { return j_.buttons.at(0); }
  bool B() const { return j_.buttons.at(1); }
  bool X() const { return j_.buttons.at(3); }
  bool Y() const { return j_.buttons.at(4); }
  bool LB() const { return j_.buttons.at(6); }
  bool RB() const { return j_.buttons.at(7); }
  bool LT_Trigger() const { return j_.buttons.at(8); }
  bool RT_Trigger() const { return j_.buttons.at(9); }
  bool Back() const { return j_.buttons.at(10); }
  bool Start() const { return j_.buttons.at(11); }
  bool Home() const { return j_.buttons.at(12); }
  bool M2() const {return j_.buttons.at(13); }
  bool M1() const {return j_.buttons.at(14); }


  const sensor_msgs::msg::Joy j_;
};
}  // namespace joy_controller

#endif  // JOY_CONTROLLER__JOY_CONVERTER__KP20_JOY_CONVERTER_HPP_
