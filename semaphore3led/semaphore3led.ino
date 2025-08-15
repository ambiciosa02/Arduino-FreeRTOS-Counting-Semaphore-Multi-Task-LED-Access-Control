#include <Arduino_FreeRTOS.h>
#include <semphr.h>

const int ledPins[] = {8, 9, 10};
//Déclaration d’un pointeur vers un sémaphore de type compteur
SemaphoreHandle_t resourceSemaphore;

void setup() {
  //Configuration des 3 broches des LEDs en sortie.
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);

  // Créer un sémaphore compteur avec 3 ressources disponibles
  resourceSemaphore = xSemaphoreCreateCounting(3, 3);

  // Créer 5 tâches qui veulent utiliser les LEDs
  for (int i = 0; i < 5; i++) {
    xTaskCreate(userTask, "UserTask", 128, (void*)i, 1, NULL);
  }
}

void loop() {
  // Rien ici
}

void userTask(void *pvParameters) {
  int taskNumber = (int) pvParameters;
  for (;;) {
    if (xSemaphoreTake(resourceSemaphore, portMAX_DELAY) == pdTRUE) {
      int led = taskNumber % 3;
      digitalWrite(ledPins[led], HIGH);
      Serial.print("Tâche ");
      Serial.print(taskNumber);
      Serial.println(" utilise une LED.");

      vTaskDelay(1000 / portTICK_PERIOD_MS);

      digitalWrite(ledPins[led], LOW);
      xSemaphoreGive(resourceSemaphore);
      Serial.print("Tâche ");
      Serial.print(taskNumber);
      Serial.println(" libère une LED.");

      vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
  }
}
