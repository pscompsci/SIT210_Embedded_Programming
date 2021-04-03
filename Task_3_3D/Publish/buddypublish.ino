const int WAVE_PIN   = D1;
const int PAT_PIN    = D2;

const int WAVE_INTERVAL = 60;
const int PAT_INTERVAL = 75;

const char *EVENT_NAME = "Deakin_RIOT_SIT210_Photon_Buddy";

const int PUBLISH_DELAY = 5;

int counter;

int waveState;
int patState;

bool waved;
bool patted;

int waveDelay;
int patDelay;

// Function declarations
void publish(const char *data);
void delayAction(bool &action, int &delay);

void setup() {
    counter = 0;
    
    waveState = 0;
    patState = 0;
    
    waved = false;
    patted = false;
    
    waveDelay = 5;
    patDelay  = 5;
    
    pinMode(WAVE_PIN, INPUT);
    pinMode(PAT_PIN, INPUT);
}

void loop() {
    waveState = digitalRead(WAVE_PIN);
    patState = digitalRead(PAT_PIN);
    
    if ((!waved && waveState == HIGH) || (counter % WAVE_INTERVAL == 0)) {
        waved = true;
        publish("wave");
    } else if ((!patted && patState == HIGH) || (counter % PAT_INTERVAL == 0)) {
        patted = true;
        publish("pat");
    }
    
    if (waved) delayAction(waved, waveDelay);
    if (patted) delayAction(patted, patDelay);
    
    counter++;
    delay(1000);
}

void publish(const char *data) {
    Particle.publish(EVENT_NAME, data);
}

void delayAction(bool &action, int &delay) {
    if (delay > 0)
        delay--;
    else {
        delay = PUBLISH_DELAY;
        action = false;
    }
}