#include <Arduino.h>
void maTache(void *parametres)
{
 while (1) // boucle infinie
 {
 Serial.printf("%s %08X\n", pcTaskGetName(NULL),
 (int)xTaskGetCurrentTaskHandle());
 delay(500);
 }
}
void setup()
{
 Serial.begin(115200);
 while (!Serial);
 Serial.printf("Départ\n");
 xTaskCreate(
 maTache, /* Fonction de la tâche. */
 "Ma tâche", /* Nom de la tâche. */
 10000, /* Taille de la pile de la tâche */
 NULL, /* Paramètres de la tâche, NULL si pas de paramètre */
 1, /* Priorité de la tâche */
 NULL); /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
}
void loop()
{
 Serial.printf("%s %08X\n", pcTaskGetName(NULL),
 (int)xTaskGetCurrentTaskHandle());
 delay(1000); 
}