#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>

//Default has generic name
//Create has custom name
//BLEMIDI_CREATE_DEFAULT_INSTANCE()
BLEMIDI_CREATE_INSTANCE("ELECTRIC_BATON", MIDI)

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  BLEMIDI.setHandleConnected(onConnected);
  BLEMIDI.setHandleDisconnected(onDisconnected);

  MIDI.begin();
}

void loop() {
  //Note, velocity, channel
  MIDI.sendNoteOn(80, 127, 1);
  delay(20);
}

//On disconnect for some reason???
void onConnected() {
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(1);
}
//On connect for some reason???
void onDisconnected() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(0);
}