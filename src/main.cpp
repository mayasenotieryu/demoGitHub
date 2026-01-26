#include <Arduino.h>

TaskHandle_t hmaTache1 = NULL;
TaskHandle_t hmaTache2 = NULL;

void maTache1(void *parametres)
{
    int i = 0;
    while (1) // boucle infinie
    {
        Serial.printf("maTache1 %4d\n", i++);
        delay(500);
        if (i = 5)
            vTaskSuspend(hmaTache1);
    }
}
void maTache2(void *parametres)
{
    int i = 0;
    while (1) // boucle infinie
    {
        Serial.printf("maTache2 %4d\n", i++);
        delay(2000);
        if (i >= 10)
            vTaskDelete(hmaTache2);
    }
}
void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.printf("Départ\n");
    xTaskCreate(
        maTache1,     /* Fonction de la tâche. */
        "Ma tâche 1", /* Nom de la tâche. */
        10000,        /* Taille de la pile de la tâche */
        NULL,         /* Paramètres de la tâche, NULL si pas de paramètre */
        1,            /* Priorité de la tâche */
        NULL);        /* Pointeur pour récupérer le « handle » de la tâche,
              optionnel */
    xTaskCreate(
        maTache2,     /* Fonction de la tâche. */
        "Ma tâche 2", /* Nom de la tâche. */
        10000,        /* Taille de la pile de la tâche */
        NULL,         /* Paramètres de la tâche, NULL si pas de paramètre */
        1,            /* Priorité de la tâche */
        NULL);        /* Pointeur pour récupérer le « handle » de la tâche,
              optionnel */
}
void loop()
{
    static int i = 0;
    Serial.printf("Loop %4d\n", i++);
    delay(1000);
    if (i >= 15)
        vTaskResume(hmaTache1);
}