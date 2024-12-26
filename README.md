# arduinoTflipflop

### Detailed Explanation of the Code:

This code sets up an Arduino to independently toggle the state of four output pins (D6, D7, D8, D9) in response to HIGH signals from four input pins (D2, D3, D4, D5). The outputs start in a default state of `HIGH`.

---

### **Key Components of the Code**

#### **1. Pin Definitions**
```cpp
const int inputPins[] = {2, 3, 4, 5};
const int outputPins[] = {6, 7, 8, 9};
```
- **`inputPins[]`:** An array storing the input pin numbers (D2, D3, D4, D5). These pins receive the HIGH signals.
- **`outputPins[]`:** An array storing the output pin numbers (D6, D7, D8, D9). These pins toggle between HIGH and LOW states based on input signals.

---

#### **2. State Tracking Variables**
```cpp
bool outputStates[] = {HIGH, HIGH, HIGH, HIGH};
bool previousInputStates[] = {LOW, LOW, LOW, LOW};
```
- **`outputStates[]`:** Tracks the current state (HIGH or LOW) of each output pin. Initially, all outputs are set to `HIGH`.
- **`previousInputStates[]`:** Tracks the previous state of each input pin to detect when the input changes from LOW to HIGH (rising edge).

---

#### **3. `setup()` Function**
```cpp
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT);                // Set input pins as INPUT
    pinMode(outputPins[i], OUTPUT);             // Set output pins as OUTPUT
    digitalWrite(outputPins[i], HIGH);          // Initialize all outputs to HIGH
  }
}
```
- **Input Pins:** Configured as `INPUT` to read external signals.
- **Output Pins:** Configured as `OUTPUT` to control external devices (e.g., LEDs).
- **Default State:** All output pins are set to `HIGH` at the start.

---

#### **4. `loop()` Function**

The `loop()` continuously monitors input pins and toggles the corresponding output pins based on their states.

---

##### **4.1 Detecting Input Transitions**
```cpp
bool currentInputState = digitalRead(inputPins[i]); // Read the input pin
if (currentInputState == HIGH && previousInputStates[i] == LOW) {
  outputStates[i] = !outputStates[i];             // Toggle the output state
  digitalWrite(outputPins[i], outputStates[i]);   // Update the output pin
}
```
- **`digitalRead()`:** Reads the current state of each input pin.
- **Transition Detection:** Checks if the input pin's state has changed from `LOW` to `HIGH`:
  - `currentInputState == HIGH`: The input pin is HIGH now.
  - `previousInputStates[i] == LOW`: The input pin was LOW previously.
  - If both conditions are true, the input has transitioned from LOW to HIGH.

---

##### **4.2 Toggling Output State**
```cpp
outputStates[i] = !outputStates[i];
```
- Toggles the state of the corresponding output pin:
  - If the output is `HIGH`, it changes to `LOW`.
  - If the output is `LOW`, it changes to `HIGH`.

---

##### **4.3 Updating the Output Pin**
```cpp
digitalWrite(outputPins[i], outputStates[i]);
```
- Updates the output pin to reflect the new state stored in `outputStates[]`.

---

##### **4.4 Updating Input History**
```cpp
previousInputStates[i] = currentInputState;
```
- Stores the current input state as the previous state for the next iteration of the loop.

---

### **How It Works**

1. **Default State:** All output pins are initialized to `HIGH`.
2. **Signal Detection:**
   - The Arduino continuously reads the input pins.
   - If an input pin changes from LOW to HIGH, it toggles the corresponding output pin.
3. **Independent Behavior:**
   - Each input-output pair is independent of the others.
   - The state of one pair does not affect the state of other pairs.

---

### **Example Scenario**
- At startup:
  - **D6, D7, D8, D9** are all HIGH.
- If **D2** receives a HIGH signal:
  - **D6** toggles to LOW, while **D7, D8, D9** remain HIGH.
- If **D3** then receives a HIGH signal:
  - **D7** toggles to LOW, while **D6, D8, D9** remain in their current states.
- The same logic applies to **D4 → D8** and **D5 → D9**.

---

### **Key Features**
- **Default State:** All outputs start in the HIGH state.
- **Independent Pairs:** Each input-output pair operates independently.
- **Edge Detection:** Outputs change state only when an input pin transitions from LOW to HIGH, preventing repeated toggling from a continuous HIGH input.

This code is efficient and ensures proper toggling behavior without affecting other input-output pairs.
