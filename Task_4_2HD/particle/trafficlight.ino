#define R_LED D4
#define Y_LED D3
#define G_LED D2

// Declare functions
void reset_leds();
int change_light(String color);

void setup() {
    pinMode(R_LED, OUTPUT);
    pinMode(Y_LED, OUTPUT);
    pinMode(G_LED, OUTPUT);
    
    Particle.function("traffic_light", change_light);
}

void loop() {

}

void reset_leds() {
    digitalWrite(R_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(G_LED, LOW);
}

int change_light(String color) {
    reset_leds();
    
    Particle.publish("LightChange", color);
    
    if (color.equals("red")) {
        digitalWrite(R_LED, HIGH);
        return 1;
    } else if (color.equals("yellow")) {
        digitalWrite(Y_LED, HIGH);
        return 1;
    } else if (color.equals("green")) {
        digitalWrite(G_LED, HIGH);
        return 1;
    } else if (color.equals("off")) {
        return 1;
    }
    return -1;
}