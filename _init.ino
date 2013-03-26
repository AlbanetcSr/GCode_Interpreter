//#define __DEBUG__

// define the parameters of our machine

// stepper drivers
#define GRBLSHIELD
// #define REPRAP_SMD_V1 

// microstepping
#ifdef REPRAP_SMD_V1
#define MICROSTEPS 2.0
#endif

#ifdef GRBLSHIELD
#define MICROSTEPS 8.0
#endif

// steppers
#define FULL_STEPS_PER_REV 200.0

// drivetrain ratios (motor revolutions per unit travel)
//
// All-thread 1/4-20 leadscrew = 20.0
// ACME 1/4-16 single start leadscrew = 16.0
// ACME 1/4-16 four start leadscrew = 4.0
// XL belt with 10T pulley = 0.5
//
#define X_REV_PER_INCH 0.5
#define Y_REV_PER_INCH 0.5
#define Z_REV_PER_INCH 20.0

// these are calculated from the above, but can be overriden
#define X_STEPS_PER_INCH (FULL_STEPS_PER_REV * MICROSTEPS * X_REV_PER_INCH)
#define X_STEPS_PER_MM   (X_STEPS_PER_INCH / 25.4)

#define Y_STEPS_PER_INCH (FULL_STEPS_PER_REV * MICROSTEPS * Y_REV_PER_INCH)
#define Y_STEPS_PER_MM   (Y_STEPS_PER_INCH / 25.4)

#define Z_STEPS_PER_INCH (FULL_STEPS_PER_REV * MICROSTEPS * Z_REV_PER_INCH)
#define Z_STEPS_PER_MM   (Z_STEPS_PER_INCH / 25.4)

// maximum stepper RPM (for G0 command)
#define MAX_STEPPER_RPM_XY 300.0
#define MAX_STEPPER_RPM_Z 300.0

// our maximum feedrates in units/minute
// calculated from the above but can be overriden
#define FAST_XY_FEEDRATE_INCH (MAX_STEPPER_RPM_XY / X_REV_PER_INCH)
#define FAST_Z_FEEDRATE_INCH  (MAX_STEPPER_RPM_Z / Z_REV_PER_INCH)
#define FAST_XY_FEEDRATE_MM (FAST_XY_FEEDRATE_INCH * 25.4)
#define FAST_Z_FEEDRATE_MM  (FAST_Z_FEEDRATE_INCH * 25.4)

// Maximum acceleration in units/minute/second
// E.g. for 300.0 machine would accelerate to 150 units/minute in 0.5sec etc.
#define MAX_ACCEL_INCH 2000.0 //100.0 - screw //1000.0 - belt
#define MAX_ACCEL_MM (MAX_ACCEL_INCH * 25.4)

// Maximum change in velocity per axis - if the change in velocity at the start
// of the next move is greater than this for at least one axis, we will decelerate
// to a stop before commencing the move, otherwise we will keep going
// value is units/minute
#define MAX_DELTA_V_INCH 50.0
#define MAX_DELTA_V_MM (MAX_DELTA_V_INCH * 25.4)

// Set to one if endstop outputs are inverting (ie: 1 means open, 0 means closed)
// RepRap opto endstops are *not* inverting. Contraptor endstops are.
#define ENDSTOPS_INVERTING 1

// Optionally disable max endstops to save pins or wiring
#define ENDSTOPS_MIN_ENABLED 0
#define ENDSTOPS_MAX_ENABLED 0

// How many temperature samples to take.  each sample takes about 100 usecs.
#define TEMPERATURE_SAMPLES 5

// The *_ENABLE_PIN signals are active high as default. Define this
// to one if they should be active low instead (e.g. if you're using different
// stepper boards).
// RepRap stepper boards are *not* inverting. GrblShield is.
#ifdef REPRAP_SMD_V1
#define INVERT_ENABLE_PINS 0
#endif

#ifdef GRBLSHIELD
#define INVERT_ENABLE_PINS 1
#endif

// If you use this firmware on a cartesian platform where the
// stepper direction pins are inverted, set these defines to 1
// for the axes which should be inverted.
// RepRap stepper boards are *not* inverting.
#define INVERT_DIR 1 // CHANGED CM - ONLY ONE FOR ALL AXES

#define STEPPERS_ALWAYS_ON 0


/****************************************************************************************
* digital i/o pin assignment
*
* this uses the undocumented feature of Arduino - pins 14-19 correspond to analog 0-5
****************************************************************************************/

//cartesian bot pins

// Reprap SMD v1.x drivers

#ifdef REPRAP_SMD_V1

#define X_STEP_PIN 2
#define X_DIR_PIN 3
#define X_ENABLE_PIN 4
#define X_MIN_PIN 5
#define X_MAX_PIN 6

#define Y_STEP_PIN 8
#define Y_DIR_PIN 9
#define Y_ENABLE_PIN 10
#define Y_MIN_PIN 11
#define Y_MAX_PIN 12

#define Z_STEP_PIN 14
#define Z_DIR_PIN 15
#define Z_ENABLE_PIN 16
#define Z_MIN_PIN 17
#define Z_MAX_PIN 18

#endif

#ifdef GRBLSHIELD

#define X_STEP_PIN 2
#define X_DIR_PIN 5
#define X_ENABLE_PIN 8
#define X_MIN_PIN 14
#define X_MAX_PIN 15

#define Y_STEP_PIN 3
#define Y_DIR_PIN 6
#define Y_ENABLE_PIN 8
#define Y_MIN_PIN 16
#define Y_MAX_PIN 17

#define Z_STEP_PIN 4
#define Z_DIR_PIN 7
#define Z_ENABLE_PIN 8
#define Z_MIN_PIN 18
#define Z_MAX_PIN 19

#endif

//servo pins
#define SERVO_PWM_PIN 11

//extruder pins
// NOTE - USING Timer1 FOR STEPPER TIMER SO CAN'T USER PINS 9 OR 10 FOR PWM
// OUTPUT (EXTRUDER_MOTOR_SPEED_PIN, EXTRUDER_HEATER_PIN, OR EXTRUDER_FAN_PIN)
#define EXTRUDER_MOTOR_SPEED_PIN   19
#define EXTRUDER_MOTOR_DIR_PIN     19
#define EXTRUDER_HEATER_PIN        19
#define EXTRUDER_FAN_PIN           19
#define EXTRUDER_THERMISTOR_PIN    -1  //a -1 disables thermistor readings
#define EXTRUDER_THERMOCOUPLE_PIN  -1 //a -1 disables thermocouple readings
