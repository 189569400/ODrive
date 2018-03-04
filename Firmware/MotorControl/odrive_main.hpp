#ifndef __ODRIVE_MAIN_HPP
#define __ODRIVE_MAIN_HPP

// stdlib includes
#include <functional>

// System includes
#include <cmsis_os.h>

// STM specific includes
#include <stm32f4xx_hal.h>  // Sets up the correct chip specifc defines required by arm_math
#define ARM_MATH_CM4 // TODO: might change in future board versions
#include <arm_math.h>

// Hardware configuration
#if HW_VERSION_MAJOR == 3
#include <board_config_v3.h>
#else
#error "unknown board version"
#endif

class Axis;

//default timeout waiting for phase measurement signals
#define PH_CURRENT_MEAS_TIMEOUT 2 // [ms]

static const float current_meas_period = CURRENT_MEAS_PERIOD;
static const int current_meas_hz = CURRENT_MEAS_HZ;
extern float vbus_voltage;
extern float brake_resistance;     // [ohm]
extern const float elec_rad_per_enc;

constexpr size_t AXIS_COUNT = 2;
extern Axis *axes[AXIS_COUNT];


// ODrive specific includes
#include <utils.h>
#include <low_level.h>
#include <encoder.hpp>
#include <sensorless_estimator.hpp>
#include <controller.hpp>
#include <motor.hpp>
#include <axis.hpp>

#endif /* __ODRIVE_MAIN_HPP */