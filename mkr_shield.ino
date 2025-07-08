
#include <Dynamixel2Arduino.h>

#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = A6; // DYNAMIXEL Shield(MKR Serise) DIR PIN
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:

  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  dxl.ping(DXL_ID);

  // Turn on the LED on DYNAMIXEL
  dxl.ledOn(DXL_ID);
  delay(500);
  // Turn off the LED on DYNAMIXEL
  dxl.ledOff(DXL_ID);
  delay(500);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  dxl.torqueOn(DXL_ID);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t key_input;
  DEBUG_SERIAL.println("Select Profile Type :");
  DEBUG_SERIAL.println("[1] Low Accel / High Vel");
  DEBUG_SERIAL.println("[2] Max Accel / Low Vel");
  DEBUG_SERIAL.println("[3] Max Accel / Max Vel");

  while (DEBUG_SERIAL.available() == 0);
  key_input = DEBUG_SERIAL.read();

  switch (key_input) {
    case '1':
      // Low Profile Acceleration, High Profile Velocity
      // Refer to API documentation for available parameters
      // http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/#dynamixelshieldv010-or-above
      dxl.writeControlTableItem(PROFILE_ACCELERATION, DXL_ID, 50);
      dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID, 300);
      break;
    case '2':
      // Max Profile Acceleration, Low Profile Velocity
      dxl.writeControlTableItem(PROFILE_ACCELERATION, DXL_ID, 0);
      dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID, 100);
      break;
    case '3':
      // Max Profile Acceleration, Max Profile Velocity
      // WARNING : Please BE AWARE that this option will make a vibrant motion for PRO(A) or PRO+ series that requires high current supply.
      dxl.writeControlTableItem(PROFILE_ACCELERATION, DXL_ID, 0);
      dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID, 0);
      break;
    default:
      break;
  }

  // Set Goal Position in RAW value
  dxl.setGoalPosition(DXL_ID, 0);
  delay(500);
  // Check if DYNAMIXEL is in motion
  while (dxl.readControlTableItem(MOVING, DXL_ID));

  // Set Goal Position in angle(degree)
  dxl.setGoalPosition(DXL_ID, 179.0, UNIT_DEGREE);
  delay(500);
  // Check if DYNAMIXEL is in motion
  while (dxl.readControlTableItem(MOVING, DXL_ID));
}
