// This borrows code from Examples->EEPROM->eeprom_write

int endAddr;

void state2Setup() {
  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
  
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  //modified to take the ambient variable's value and write it to memory
  endAddr = min(ambient.length(), EEPROMSIZE); //prox set from Main loop
  for (int i = 0; i < endAddr; i++) {
    EEPROM.write(i, ambient[i]);
  }

  Serial.println("String committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
