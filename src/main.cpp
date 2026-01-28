#include <Arduino.h>
#define Pin_sortie 15

void maTache1(void *parametres)
{
 int v1 = 0;
 static int v2 = 0;
 while (1) // boucle infinie
 {
 Serial.printf("%s : v1=%d v2=%d\n", pcTaskGetName(NULL), v1, v2);
 v1++;
 v2++;
 delay(500);
 }
}

void maTache2(void *parametres)
{
 int v1 = 0;
 static int v2 = 0;
 while (1) // boucle infinie
 {
 Serial.printf("%s : v1=%d v2=%d\n", pcTaskGetName(NULL), v1, v2);
 v1++;
 v2++;
 delay(500);
 }
}

void setup()
{
 Serial.begin(115200);
 Serial.printf("Initialisation\n");
 // Création de la tâche périodique
 xTaskCreate(maTache1, "Tâche 1", 10000, NULL, 2, NULL);
 xTaskCreate(maTache2, "Tâche 2", 10000, NULL, 2, NULL);
    pinMode(Pin_sortie, OUTPUT);
}
void loop()
{
    Serial.printf("1");
 static int i = 0;
 Serial.printf("Boucle principale : %d\n", i++);
 delay(1000);
 digitalWrite(Pin_sortie, LOW);
}
