// 4 tubes Nixie IN-12B · Arduino Uno · 4 x K155ID1 / SN74141 · pilotage statique
// Moniteur série à 9600 bauds, fin de ligne « Nouvelle ligne » :
//   T1435  -> horloge à 14:35        N42  -> affiche 42
//   H      -> retour à l'horloge     C    -> défilement anti-empoisonnement

// Broches Uno reliées à A, B, C, D (poids 1, 2, 4, 8) de chaque décodeur
// (carte mère : J9 = V1/V2, J12 = V3/V4, voir README.md)
const uint8_t BCD_PIN[4][4] = {
  {13, 11, 10, 12},   // V1 (à gauche)
  { 9,  7,  6,  8},   // V2
  { 5,  3,  2,  4},   // V3
  {A3, A1, A0, A2}    // V4 (à droite)
};
const uint8_t BLANK = 15;            // codes 10 à 15 : tube éteint

uint32_t clockBase;                  // millis() au moment du réglage
uint16_t clockStartMin = 12 * 60;    // 12:00 au démarrage
bool clockMode = true;
int16_t lastMin = -1;               // -1 : forcer le réaffichage
char line[12];
uint8_t len = 0;

void setTube(uint8_t t, uint8_t v) {
  for (uint8_t b = 0; b < 4; b++)
    digitalWrite(BCD_PIN[t][b], (v >> b) & 1);
}

void show(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
  setTube(0, a); setTube(1, b); setTube(2, c); setTube(3, d);
}

void showNumber(uint16_t n) {        // 0..9999, zéros de tête éteints
  const uint16_t POW10[4] = {1000, 100, 10, 1};
  bool lead = true;
  for (uint8_t i = 0; i < 4; i++) {
    uint8_t d = n / POW10[i] % 10;
    if (lead && d == 0 && i < 3) setTube(i, BLANK);
    else { lead = false; setTube(i, d); }
  }
}

// Allume chaque chiffre de chaque tube : évite l'empoisonnement des cathodes
// peu utilisées (dépôt qui finit par masquer un chiffre).
void antiPoison() {
  for (uint8_t r = 0; r < 3; r++)
    for (uint8_t d = 0; d < 10; d++) {
      show(d, (d + 3) % 10, (d + 6) % 10, (d + 9) % 10);
      delay(50);
    }
}

void command(const char *s) {
  if (s[0] == 'T' && strlen(s) == 5) {
    uint16_t hh = (s[1] - '0') * 10 + (s[2] - '0');
    uint16_t mm = (s[3] - '0') * 10 + (s[4] - '0');
    if (hh < 24 && mm < 60) {
      clockStartMin = hh * 60 + mm;
      clockBase = millis();
      clockMode = true;
      lastMin = -1;
      Serial.println(F("Heure reglee"));
    }
  } else if (s[0] == 'N') {
    clockMode = false;
    showNumber(atoi(s + 1) % 10000);
  } else if (s[0] == 'H') {
    clockMode = true;
    lastMin = -1;
  } else if (s[0] == 'C') {
    antiPoison();
  }
}

void readSerial() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      if (len) { line[len] = 0; command(line); len = 0; }
    } else if (len < sizeof(line) - 1) {
      line[len++] = toupper(c);
    }
  }
}

void setup() {
  for (uint8_t t = 0; t < 4; t++)
    for (uint8_t b = 0; b < 4; b++) pinMode(BCD_PIN[t][b], OUTPUT);
  show(BLANK, BLANK, BLANK, BLANK);
  Serial.begin(9600);
  antiPoison();                      // test des 40 chiffres au démarrage
  clockBase = millis();
}

void loop() {
  readSerial();
  if (!clockMode) return;
  uint16_t m = (clockStartMin + (millis() - clockBase) / 60000UL) % 1440;
  if ((int16_t)m != lastMin) {
    if (lastMin >= 0 && m % 10 == 0) antiPoison();   // toutes les 10 min
    lastMin = m;
    show(m / 600, m / 60 % 10, m % 60 / 10, m % 10);
  }
}
