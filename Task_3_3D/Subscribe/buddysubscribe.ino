const int WAVE_PIN    = D7;
const int WAVE_BLINKS = 3;
const int WAVE_TIME   = 1000;

const int PAT_PIN     = D6;
const int PAT_BLINKS  = 5;
const int PAT_TIME    = 300;

const char *RECEIVED_EVENT = "Deakin_RIOT_SIT210_Photon_Buddy";
const char *RESPONSE_EVENT = "Deakin_RIOT_SIT210_Argon_Buddy";

// Function declarations
void subscriptionHandler(const char *event, const char *data);
void blinkLED(int led, int blinks, int delayTime);

void setup() {
    pinMode(WAVE_PIN, OUTPUT);
    pinMode(PAT_PIN, OUTPUT);
	Particle.subscribe(RECEIVED_EVENT, subscriptionHandler);
}

void loop() {
    // Nothing to do. Handled in subscriptionHandler
}

void subscriptionHandler(const char *event, const char *data) {
    if (strcmp(data, "wave") == 0) {
	    blinkLED(WAVE_PIN, WAVE_BLINKS, WAVE_TIME);
	} else if (strcmp(data, "pat") == 0) {
	    blinkLED(PAT_PIN, PAT_BLINKS, PAT_TIME);
	}
	String message = String::format("Completed: %s event", data);
	Particle.publish(RESPONSE_EVENT, message);
}

void blinkLED(int led, int blinks, int delayTime) {
    for(int i = 0; i < blinks; i++) {
        digitalWrite(led, HIGH);
        delay(delayTime);
        digitalWrite(led, LOW);
        delay(delayTime);
    }
}