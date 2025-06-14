
// // // // /*
// // // //  *  This sketch demonstrates how to scan WiFi networks.
// // // //  *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
// // // //  *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
// // // //  */
// // // // #include "WiFi.h"

// // // // void setup() {
// // // //   Serial.begin(115200);

// // // //   // Set WiFi to station mode and disconnect from an AP if it was previously connected.
// // // //   WiFi.mode(WIFI_STA);
// // // //   WiFi.disconnect();
// // // //   delay(100);

// // // //   Serial.println("Setup done");
// // // // }

// // // // void loop() {
// // // //   Serial.println("Scan start");

// // // //   // WiFi.scanNetworks will return the number of networks found.
// // // //   int n = WiFi.scanNetworks();
// // // //   Serial.println("Scan done");
// // // //   if (n == 0) {
// // // //     Serial.println("no networks found");
// // // //   } else {
// // // //     Serial.print(n);
// // // //     Serial.println(" networks found");
// // // //     Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
// // // //     for (int i = 0; i < n; ++i) {
// // // //       // Print SSID and RSSI for each network found
// // // //       Serial.printf("%2d", i + 1);
// // // //       Serial.print(" | ");
// // // //       Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
// // // //       Serial.print(" | ");
// // // //       Serial.printf("%4ld", WiFi.RSSI(i));
// // // //       Serial.print(" | ");
// // // //       Serial.printf("%2ld", WiFi.channel(i));
// // // //       Serial.print(" | ");
// // // //       switch (WiFi.encryptionType(i)) {
// // // //         case WIFI_AUTH_OPEN:            Serial.print("open"); break;
// // // //         case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
// // // //         case WIFI_AUTH_WPA_PSK:         Serial.print("WPA"); break;
// // // //         case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2"); break;
// // // //         case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA+WPA2"); break;
// // // //         case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2-EAP"); break;
// // // //         case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3"); break;
// // // //         case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2+WPA3"); break;
// // // //         case WIFI_AUTH_WAPI_PSK:        Serial.print("WAPI"); break;
// // // //         default:                        Serial.print("unknown");
// // // //       }
// // // //       Serial.println();
// // // //       delay(10);
// // // //     }
// // // //   }
// // // //   Serial.println("");

// // // //   // Delete the scan result to free memory for code below.
// // // //   WiFi.scanDelete();

// // // //   // Wait a bit before scanning again.
// // // //   delay(5000);
// // // // }
// // // #include <WiFi.h>
// // // #include <WebServer.h>

// // // // Wi-Fi credentials
// // // const char* ssid = "aditi";        // Change to your Wi-Fi SSID
// // // const char* password = "123456789"; // Change to your Wi-Fi password

// // // // Create web server on port 80
// // // WebServer server(80);

// // // // Define analog sensor pins
// // // #define MQ137 34  // Sensor connected to GPIO34 (SN)
// // // #define ECG_SENSOR 35  // Sensor connected to GPIO35 (SN)
// // // #define MQ135 32  // Sensor connected to GPIO32 (SN)
// // // #define MQ7 33  // Sensor connected to GPIO33 (SN)
// // // #define MQ136   36  // ECG sensor connected to GPIO36 (SN)

// // // // Function to generate the web page
// // // void handleRoot() {
// // //     // Read sensor values
// // //     float gas1 = analogRead(MQ137);
// // //     float ecg = analogRead(ECG_SENSOR);
// // //     float gas3 = analogRead(MQ135);
// // //     float gas4 = analogRead(MQ7);
// // //     float gas2 = analogRead(MQ136);
// // //     float ecgVoltage = (ecg / 4096.0) * 3.3; // Convert raw ECG value to voltage

// // //     // Build the HTML response
// // //     String html = "<html><head><title>ESP32 Sensor Data</title>";
// // //     html += "<style>body { font-family: Arial; text-align: center; background-color: #f4f4f9; }";
// // //     html += "h1 { color: #333; } p { font-size: 18px; } strong { color: #555; }</style>";
// // //     html += "</head><body>";
// // //     html += "<h1>ESP32 Sensor Readings</h1>";
// // //     html += "<p><strong>Gas Sensor 1 (G34):</strong> " + String(gas1, DEC) + " PPM</p>";
// // //     html += "<p><strong>Gas Sensor 2 (G35):</strong> " + String(gas2, DEC) + " PPM</p>";
// // //     html += "<p><strong>Gas Sensor 3 (G32):</strong> " + String(gas3, DEC) + " PPM</p>";
// // //     html += "<p><strong>Gas Sensor 4 (G33):</strong> " + String(gas4, DEC) + " PPM</p>";
// // //     html += "<p><strong>ECG Sensor (G36):</strong> " + String(ecgVoltage, 2) + " V</p>";
// // //     html += "<script>setTimeout(() => { location.reload(); }, 1000);</script>"; // Auto-refresh every second
// // //     html += "</body></html>";

// // //     // Send response
// // //     server.send(200, "text/html", html);
// // // }

// // // void setup() {
// // //     Serial.begin(115200);
// // //     delay(1000);

// // //     // Connect to Wi-Fi
// // //     WiFi.begin(ssid, password);
// // //     Serial.print("Connecting to Wi-Fi...");
    
// // //     while (WiFi.status() != WL_CONNECTED) {
// // //         delay(500);
// // //         Serial.print(".");
// // //     }
    
// // //     Serial.println("\nConnected to Wi-Fi!");
// // //     Serial.print("ESP32 IP Address: ");
// // //     Serial.println(WiFi.localIP());

// // //     // Start web server
// // //     server.on("/", handleRoot);
// // //     server.begin();
// // //     Serial.println("Web server started.");
// // // }

// // // void loop() {
// // //     server.handleClient();  // Handle web requests
// // // }

// // #include <WiFi.h>

// // // Wi-Fi credentials (Optional for web server)
// // const char* ssid = "aditi";
// // const char* password = "123456789";

// // // GPIO Pins
// // #define MQ137 34   // Gas sensor 1 (CO)
// // #define MQ135 32   // Gas sensor 3 (CO2)
// // #define MQ7 33     // Gas sensor 4 (H2S)
// // #define MQ136 35   // Gas sensor 2 (NH3)
// // #define ECG_SENSOR 36 // ECG sensor
// // #define BUZZER_PIN 25 // Buzzer pin

// // // Gas limits structure
// // struct GasLimits {
// //   int safe_min;
// //   int safe_max;
// //   int stel_min;
// //   int stel_max;
// // };

// // // Define gas threshold ranges in ppm
// // GasLimits gas_thresholds[] = {
// //     {0, 50, 100, 500},   // CO
// //     {0, 5000, 7500, 30000}, // CO2
// //     {0, 10, 50, 100},    // H2S
// //     {0, 25, 30, 35}      // NH3
// // };

// // // ECG ranges (in ms)
// // int low_pr_range[] = {80, 120};
// // int normal_pr_range[] = {120, 200};
// // int elevated_pr_range[] = {200, 220};
// // int high_pr_range[] = {220, 250};

// // // Function to classify gas levels
// // bool isGasDangerous(int gasIndex, float value) {
// //   GasLimits limits = gas_thresholds[gasIndex];
// //   return (value >= limits.stel_min && value <= limits.stel_max);
// // }

// // // Function to classify ECG intervals
// // bool isECGOutOfRange(float value, int range[]) {
// //   return !(value >= range[0] && value <= range[1]);
// // }

// // // Function to trigger the buzzer
// // void triggerBuzzer(bool status) {
// //   digitalWrite(BUZZER_PIN, status ? HIGH : LOW);
// // }

// // void setup() {
// //   Serial.begin(115200);

// //   // Configure pins
// //   pinMode(BUZZER_PIN, OUTPUT);

// //   // Initialize Wi-Fi (optional for web monitoring)
// //   WiFi.begin(ssid, password);
// //   Serial.print("Connecting to Wi-Fi...");
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(500);
// //     Serial.print(".");
// //   }
// //   Serial.println("\nWi-Fi Connected!");

// //   Serial.println("System initialized. Monitoring started.");
// // }

// // void loop() {
// //   // Read analog values from sensors
// //   float gas1 = analogRead(MQ137);  // CO
// //   float gas3 = analogRead(MQ135); // CO2
// //   float gas4 = analogRead(MQ7);   // H2S
// //   float gas2 = analogRead(MQ136); // NH3
// //   float ecg = analogRead(ECG_SENSOR);

// //   // Normalize ECG values to voltage and calculate intervals
// //   float ecgVoltage = (ecg / 4096.0) * 3.3;
// //   float derived_pr = map(ecgVoltage, 0.5, 3.0, 100, 250); // Example mapping for PR interval
// //   float derived_qt = map(ecgVoltage, 0.5, 3.0, 300, 500); // Example mapping for QT interval
// //   float derived_st = map(ecgVoltage, 0.5, 3.0, 60, 160);  // Example mapping for ST segment

// //   // Check for gas and ECG thresholds
// //   bool gasAlert = isGasDangerous(0, gas1) || isGasDangerous(1, gas3) ||
// //                   isGasDangerous(2, gas4) || isGasDangerous(3, gas2);
// //   bool ecgAlert = isECGOutOfRange(derived_pr, normal_pr_range) ||
// //                   isECGOutOfRange(derived_qt, normal_pr_range) ||
// //                   isECGOutOfRange(derived_st, normal_pr_range);

// //   // Trigger buzzer if any alert is detected
// //   if (gasAlert || ecgAlert) {
// //     triggerBuzzer(true);
// //     Serial.println("ALERT: Dangerous condition detected!");
// //   } else {
// //     triggerBuzzer(false);
// //     Serial.println("All readings normal.");
// //   }

// //   // Print sensor readings
// //   Serial.printf("Gas1 (CO): %.2f ppm\n", gas1);
// //   Serial.printf("Gas2 (NH3): %.2f ppm\n", gas2);
// //   Serial.printf("Gas3 (CO2): %.2f ppm\n", gas3);
// //   Serial.printf("Gas4 (H2S): %.2f ppm\n", gas4);
// //   Serial.printf("ECG Voltage: %.2f V\n", ecgVoltage);
// //   Serial.printf("PR: %.2f ms, QT: %.2f ms, ST: %.2f ms\n", derived_pr, derived_qt, derived_st);

// //   delay(1000); // Loop delay
// // }


// #include <WiFi.h>
// #include <WebServer.h>

// // Wi-Fi credentials
// const char* ssid = "aditi";
// const char* password = "123456789";

// // GPIO Pins
// #define MQ137 34   // Gas sensor 1 (CO)
// #define MQ135 32   // Gas sensor 3 (CO2)
// #define MQ7 33     // Gas sensor 4 (H2S)
// #define MQ136 35   // Gas sensor 2 (NH3)
// #define ECG_SENSOR 36 // ECG sensor
// #define BUZZER_PIN 25 // Buzzer pin

// // Create web server on port 80
// WebServer server(80);

// // Gas limits structure
// struct GasLimits {
//   int safe_min;
//   int safe_max;
//   int stel_min;
//   int stel_max;
// };

// // Define gas threshold ranges in ppm
// GasLimits gas_thresholds[] = {
//     {0, 50, 100, 500},   // CO
//     {0, 5000, 7500, 30000}, // CO2
//     {0, 10, 50, 100},    // H2S
//     {0, 25, 30, 35}      // NH3
// };

// // Function to classify gas levels
// bool isGasDangerous(int gasIndex, float value) {
//   GasLimits limits = gas_thresholds[gasIndex];
//   return (value >= limits.stel_min && value <= limits.stel_max);
// }

// // Function to trigger the buzzer
// void triggerBuzzer(bool status) {
//   digitalWrite(BUZZER_PIN, status ? HIGH : LOW);
// }

// // Function to handle the root web page
// void handleRoot() {
//   // Read analog values from sensors
//   float gas1 = analogRead(MQ137);  // CO
//   float gas3 = analogRead(MQ135); // CO2
//   float gas4 = analogRead(MQ7);   // H2S
//   float gas2 = analogRead(MQ136); // NH3
//   float ecg = analogRead(ECG_SENSOR);

//   // Normalize ECG values to voltage
//   float ecgVoltage = (ecg / 4096.0) * 3.3;

//   // Build the HTML response
//   String html = "<html><head><title>ESP32 Sensor Data</title>";
//   html += "<style>body { font-family: Arial; text-align: center; background-color: #f4f4f9; }";
//   html += "h1 { color: #333; } p { font-size: 18px; } strong { color: #555; }</style>";
//   html += "</head><body>";
//   html += "<h1>ESP32 Sensor Readings</h1>";
//   html += "<p><strong>Gas Sensor 1 (G34):</strong> " + String(gas1, DEC) + " PPM</p>";
//   html += "<p><strong>Gas Sensor 2 (G35):</strong> " + String(gas2, DEC) + " PPM</p>";
//   html += "<p><strong>Gas Sensor 3 (G32):</strong> " + String(gas3, DEC) + " PPM</p>";
//   html += "<p><strong>Gas Sensor 4 (G33):</strong> " + String(gas4, DEC) + " PPM</p>";
//   html += "<p><strong>ECG Sensor (G36):</strong> " + String(ecgVoltage, 2) + " V</p>";
//   html += "<script>setTimeout(() => { location.reload(); }, 1000);</script>"; // Auto-refresh every second
//   html += "</body></html>";

//   // Send the response
//   server.send(200, "text/html", html);
// }

// void setup() {
//   Serial.begin(115200);

//   // Configure pins
//   pinMode(BUZZER_PIN, OUTPUT);

//   // Initialize Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wi-Fi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nConnected to Wi-Fi!");
//   Serial.print("ESP32 Web Server IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Start the web server
//   server.on("/", handleRoot);
//   server.begin();
//   Serial.println("Web server started.");
// }

// void loop() {
//   // Read analog values from sensors
//   float gas1 = analogRead(MQ137);  // CO
//   float gas3 = analogRead(MQ135); // CO2
//   float gas4 = analogRead(MQ7);   // H2S
//   float gas2 = analogRead(MQ136); // NH3

//   // Check for dangerous gas levels
//   bool gasAlert = isGasDangerous(0, gas1) || isGasDangerous(1, gas3) ||
//                   isGasDangerous(2, gas4) || isGasDangerous(3, gas2);

//   // Trigger the buzzer if any gas sensor reading is dangerous
//   triggerBuzzer(gasAlert);

//   // Handle web requests
//   server.handleClient();

//   // Delay for stability
//   delay(1000);
// }


#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <math.h>

// Wi-Fi credentials
const char* ssid = "aditi";
const char* password = "123456789";

// Remote ML server URL
const String SERVER_URL = "https://97b9-34-75-94-122.ngrok-free.app/predict";

// GPIO Pins
#define MQ137 34   // CO
#define MQ135 32   // CO2
#define MQ7 33     // H2S
#define MQ136 35   // NH3
#define ECG_SENSOR 36
#define BUZZER_PIN 25

// Create web server
WebServer server(80);

// Anomaly status (global)
bool anomalyDetected = false;

// Conversion functions
float convertCO(float voltage) {
  return 1538.46 * pow(voltage, -1.78);
}

float convertCO2(float voltage) {
  return 116.6020682 * pow(voltage, -2.769034857);
}

float convertH2S(float voltage) {
  return pow(10, ((log10(voltage) - 0.72) / -1.3));
}

float convertNH3(float voltage) {
  return pow(10, ((log10(voltage) - 1.47) / -1.67));
}

// ECG Feature Extraction Approximations
float calculatePR(float voltage) {
  return voltage * 120.0;
}

float calculateQT(float voltage) {
  return voltage * 200.0;
}

float calculateST(float voltage) {
  return voltage * 80.0;
}

float calculateHRV(float voltage) {
  return (60000.0 / (voltage * 150.0));
}

// Send sensor data to ML server
bool sendToMLServer(float co, float co2, float h2s, float nh3, float pr, float qt, float st, float hrv) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(SERVER_URL);
    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument doc(1024);
    doc["data"]["CO"] = co;
    doc["data"]["CO2"] = co2;
    doc["data"]["H2S"] = h2s;
    doc["data"]["NH3"] = nh3;
    doc["data"]["PR"] = pr;
    doc["data"]["QT"] = qt;
    doc["data"]["ST"] = st;
    doc["data"]["HRV"] = hrv;

    String payload;
    serializeJson(doc, payload);

    int httpCode = http.POST(payload);
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Server Response: " + response);

      DynamicJsonDocument responseDoc(1024);
      deserializeJson(responseDoc, response);

      if (responseDoc.containsKey("Final_Anomaly")) {
        return responseDoc["Final_Anomaly"];
      }
    } else {
      Serial.println("HTTP Error");
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  return false; // Default to safe
}

// HTML Page
void handleRoot() {
  // Sensor Readings
  float vCO = (analogRead(MQ137) / 4095.0) * 3.3;
  float vCO2 = (analogRead(MQ135) / 4095.0) * 3.3;
  float vH2S = (analogRead(MQ7) / 4095.0) * 3.3;
  float vNH3 = (analogRead(MQ136) / 4095.0) * 3.3;
  float vECG = (analogRead(ECG_SENSOR) / 4095.0) * 3.3;

  float co =  (convertCO(vCO)/30000)*50;
  float co2 = (convertCO2(vCO2)/40000)*5000;
  float h2s = convertH2S(vH2S);
  float nh3 = convertNH3(vNH3);

  float pr = (calculatePR(vECG)/450)*200;
  float qt = (calculateQT(vECG)/780)*450;
  float st = calculateST(vECG)/2;
  float hrv = (calculateHRV(vECG)/160)*45;

  anomalyDetected = sendToMLServer(co, co2, h2s, nh3, pr, qt, st, hrv);
  digitalWrite(BUZZER_PIN, anomalyDetected ? HIGH : LOW);

  String html = "<html><head><title>ESP32 Sensor Dashboard</title>";
  html += "<style>body{font-family:Arial;text-align:center;background:#f0f0f0;}h1{color:#222;}p{font-size:18px;}strong{color:#444;}</style>";
  html += "<meta http-equiv='refresh' content='5'/>";
  html += "</head><body>";
  html += "<h1>Real-Time Sensor Data</h1>";
  html += "<p><strong>CO:</strong> " + String(co, 2) + " ppm</p>";
  html += "<p><strong>CO2:</strong> " + String(co2, 2) + " ppm</p>";
  html += "<p><strong>H2S:</strong> " + String(h2s, 2) + " ppm</p>";
  html += "<p><strong>NH3:</strong> " + String(nh3, 2) + " ppm</p>";
  html += "<p><strong>PR:</strong> " + String(pr, 2) + " ms</p>";
  html += "<p><strong>QT:</strong> " + String(qt, 2) + " ms</p>";
  html += "<p><strong>ST:</strong> " + String(st, 2) + " ms</p>";
  html += "<p><strong>HRV:</strong> " + String(hrv, 2) + " ms</p>";
  html += "<h2>Status: " + String(anomalyDetected ?  " Normal" : "!!! Anomaly Detected !!!") + "</h2>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP: "); Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
}
