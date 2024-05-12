const int pin = A0;
const int pad = 5;

int pos = 0;
int pos_old = 0;

int pos_val[] = {814, 563, 368, 327, 289, 183};

void setup() {
    Serial.begin(115200);
}

void loop() {
    int val = analogRead(pin);

    if (val > pad) {
        for (int p = 0; p <= 5; p++) {
            if (val >= pos_val[p] - pad and val <= pos_val[p] + pad) {
                pos = p;

                if (pos != pos_old) {
                    pos_old = pos;

                    Serial.print("Value: ");
                    Serial.print(val);
                    Serial.print(", ");
                    Serial.print("Position: ");
                    Serial.print(pos);
                    Serial.println(".");
                }
                break;
            }
        }
    }

    delay(1);
}
