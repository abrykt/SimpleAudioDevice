#include <stdio.h>

#include "MyBooleanControl.h"
#include "os/log.h"

#define Log(fmt, ...) os_log(OS_LOG_DEFAULT, fmt "\n", ##__VA_ARGS__)


kern_return_t MyBooleanControl::HandleChangeControlValue(const bool in_control_value) {
  Log("in_control_value: %{public}d", in_control_value);

  const auto result = SetControlValue(in_control_value);
  Log("SetControlValue returned: %{public}d", result);

  const auto value = GetControlValue();
  Log("GetControlValue returned: %{public}d", value);

  Log("--------------------------------");
  return result;
}
