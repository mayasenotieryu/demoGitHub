#include <Arduino.h>
SemaphoreHandle_t mutex;
void tache1(void *parametres)
{
    int i = 0;
    mutex = xSemaphoreCreateMutex();
    while (1)
    {
        if (xSemaphoreTake(mutex, INFINITY))
        {
            ok = xSemaphoreGive(mutex);
        }
        Serial.printf("Dans la tâche 1 : ");
        delay(1);
        Serial.printf("%d\n", i);
        i++;
        delay(1000);
    }
}
void tache2(void *parametres)
{
    int i = 100;
    mutex = xSemaphoreCreateMutex();
    while (1)
    {
        if (xSemaphoreTake(mutex, INFINITY))
        {
            ok = xSemaphoreGive(mutex);
        }
        Serial.printf("Dans la tâche 2 : ");
        delay(1);
        Serial.printf("%d\n", i);
        i++;
        delay(1000);
    }
}
void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.printf("Départ\n");

    // mutex = xSemaphoreCreateMutex();

    xTaskCreate(
        tache1,    /* Fonction de la tâche. */
        "Tâche 1", /* Nom de la tâche. */
        10000,     /* Taille de la pile de la tâche */
        NULL,      /* Paramètres de la tâche, NULL si pas de paramètre */
        1,         /* Priorité de la tâche */
        NULL);     /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
    xTaskCreate(
        tache2,    /* Fonction de la tâche. */
        "Tâche 2", /* Nom de la tâche. */
        10000,     /* Taille de la pile de la tâche */
        NULL,      /* Paramètres de la tâche, NULL si pas de paramètre */
        1,         /* Priorité de la tâche */
        NULL);     /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
    vTaskDelete(NULL);
}
void loop()
{
    // Ne s'exécute pas
}
