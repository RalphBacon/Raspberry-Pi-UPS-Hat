/*
   Raspberry Pi rebooter. If the RasPi has power but is not running
   (determined by inspecting one of its GPIO pins that should be HIGH)
   then after 30 seconds (in case the Pi is in the process of booting)
   we pull the UPS switch LOW for 5 seconds then release it. That should
   allow power to flow to the Pi.

   Just to be safe, the switch on the UPS is brought low using a tranny
   (I'm using a 2N3904 or similar) to prevent 5v being presented to the UPS switch.
   When the pin goes HIGH (thereby grounding the UPS switch) it will conduct
   and ground the UPS pin.

   On the Pi, edit the RC.local file and enter the following lines. Note
   you must edit the file in SUDO mode like this:

   OUPS_Pin a Terminal Window on your RasPi and enter:
   cd /etc
   sudo nano RC.local

   Once in the editor add the following lines just before the exit 0
   # We want to use GPIO pin 26 please
   echo 26 > /sys/class/gpio/export

   # The pin mode of this pin is an OUTPUT pin
   echo out > /sys/class/gpio/gpio26/direction

   # Send the pin value to HIGH (=1)
   echo 1 > /sys/class/gpio/gpio26/value

*/
#define PiHi 0
#define UPS_Pin 1

// Demo LED to show we're going to reboot the Pi
#define Indicator 2

// ------------------------------------------------------------------
// Simple setup routine to read the PI's GPIO pin, set the output etc
// ------------------------------------------------------------------
void setup() {
  pinMode(PiHi, INPUT);

  // Set the 'reset' pin LOW before the mode to avoid glitches
  // Remember this pin is connected via a NPN transistor to 
  // the UPS switch
  digitalWrite(UPS_Pin, LOW);
  pinMode(UPS_Pin, OUTPUT);

  // Just for debugging and demo purposes show the LED status
  pinMode(Indicator, OUTPUT);
  digitalWrite(Indicator, LOW);
}

// ------------------------------------------------------------------
// This loop check to make sure Pi is UP
// ------------------------------------------------------------------
void loop() {
  static unsigned int loopDelay = 0;

  // Read the RasPi's output pin - should be HIGH if running
  if (digitalRead(PiHi) == 0) {

    // Only do something if the Pi has not had this pin HIGH for X seconds
    // to allow it time to boot up or we could be constantly resetting it!
    if (loopDelay > 29) {
      digitalWrite(UPS_Pin, HIGH);
      digitalWrite(Indicator, LOW);
      delay(5000);
      digitalWrite(UPS_Pin, LOW);
      loopDelay = 0;
    }
    else {
      // Start the countdown to a reset
      digitalWrite(Indicator, HIGH);
      loopDelay++;
    }
  }
  else {
    // Reset any part-delay we've counted
    loopDelay = 0;
    digitalWrite(Indicator, LOW);
  }

  // Loops every second, fine for demo
  delay(1000);
}
