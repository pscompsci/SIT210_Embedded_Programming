
#define LUM_PIN          A3
#define LED_PIN          D3
#define CAL_BTN          D4

// Delay times
#define CAL_SLEEP        30000 // At end of calibration (time to position device)
#define READ_DELAY       1000  // 1 second between readings
#define LED_BLINK        500

int  calibrated_sun;           // Stored value for direct sun
int  luminance;                // Current reading

bool calibrated;               // Are we calibrated?
bool sun;                      // Are we currently in sun?

// Declare functions
void calibrate();

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(CAL_BTN, INPUT);
    pinMode(LUM_PIN, INPUT);
    
    sun        = false;
    calibrated = false;
}

void loop() {
    luminance = analogRead(LUM_PIN);
    
    if (!calibrated && digitalRead(CAL_BTN) == HIGH) {
            calibrate();
    } else if (calibrated) {
        digitalWrite(LED_PIN, HIGH);
        
        if (luminance >= calibrated_sun && !sun) {
            Particle.publish("Light_Status", "Sun");
            sun = true;
        }
        else if (luminance < calibrated_sun && sun) {
            Particle.publish("Light_Status", "Shade");
            sun = false;
        }
    }
    
    delay(READ_DELAY);
}

void calibrate() {
    calibrated = true;
    calibrated_sun = 100000;
    
    for (int i = 0; i < 30; i++) {
        luminance = analogRead(LUM_PIN);
        if (calibrated_sun > luminance) {
            calibrated_sun = luminance;
        }
        digitalWrite(LED_PIN, HIGH);
        delay(LED_BLINK);
        digitalWrite(LED_PIN, LOW);
        delay(LED_BLINK);
    }
    
    Particle.publish("Light_Status", "Calibrated OK");
    delay(CAL_SLEEP);
}