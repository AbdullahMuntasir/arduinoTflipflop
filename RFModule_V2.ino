// Define input pins
const int inputPins[] = {2, 3, 4, 5};

// Define output pins
const int outputPins[] = {6, 7, 8, 9};

// Variables to track the current state of each output pin
bool outputStates[] = {HIGH, HIGH, HIGH, HIGH};

// Variables to track the previous state of each input pin
bool previousInputStates[] = {LOW, LOW, LOW, LOW};

void setup() {
  // Initialize input pins as INPUT
  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT);
  }

  // Initialize output pins as OUTPUT and set default state to HIGH
  for (int i = 0; i < 4; i++) {
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins[i], HIGH); // Set default state to HIGH
  }
}

void loop() {
  // Check each input-output pair
  for (int i = 0; i < 4; i++) {
    bool currentInputState = digitalRead(inputPins[i]); // Read the current state of the input pin

    // Check if the input pin has transitioned from LOW to HIGH
    if (currentInputState == HIGH && previousInputStates[i] == LOW) {
      outputStates[i] = !outputStates[i]; // Toggle the corresponding output state
      digitalWrite(outputPins[i], outputStates[i]); // Update the output pin
    }

    // Update the previous input state for the next loop iteration
    previousInputStates[i] = currentInputState;
  }
}
