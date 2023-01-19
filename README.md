# Automaton-OTA
Arduino OTA integration into Automaton framework.

The idea of this library is to keep a sketch based on Automaton cleaner. No need to place AuduinoOTA.handle() in your loop function.

## Dependencies

### Automaton

[Webite](https://github.com/tinkerspy/Automaton/wiki)

Tested with Version 1.0.2, install with Library Manager

### Automaton-Esp8266 (optional)
[Website](https://github.com/tinkerspy/Automaton-Esp8266/wiki)

In order to configure and establish a Wifi connection according to the approach
in all Automaton components.

Tested with Version 0.1.0, install with Library Manager

### ArduinoOTA

Part of ESP8266 board package.

## Example

The following sketch sets up a wifi connection and allows over the air updates.

```C++

#include <Automaton-OTA.h>
#include <Atm_esp8266.h>                 // to setup wifi

// wifi config
const char* WIFI_SSID = "myssid";        // SSID of your wifi
const char* WIFI_PASSWORD = "mywifipassword"; // and the password

// OTA config
const char* OTA_HOSTNAME = "myhostname"; // name of your controller which will be shown in your Arduino IDE
const char* OTA_PW = "mypassword";       // password you will need to enter whily updating

Atm_OTA aOTA;

void setup(){
  // initialize wifi at first
  wifi.begin(WIFI_SSID, WIFI_PASSWORD).
    start();

  // initialize OTA
  aOTA.begin( OTA_HOSTNAME, OTA_PW );
}

void loop(){
  automaton.run();
}
```

Thats it.
