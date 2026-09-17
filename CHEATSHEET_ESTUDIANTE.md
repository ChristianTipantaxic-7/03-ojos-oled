# Cheatsheet Estudiantil — Semana 03: Bitmaps OLED y FSM No Bloqueante

> **Guía Técnica de Consulta Rápida — Soporte Técnico UETS**

---

## 1. ¿Cómo se almacena un Bitmap de 128x64 en el ESP32?

Una pantalla OLED SSD1306 de 128x64 píxeles cuenta con:
$$\text{Total de Píxeles} = 128 \times 64 = 8192\text{ píxeles}$$

Dado que cada píxel es monocromático (encendido o apagado), se representa con **1 bit**:
$$\text{Tamaño en Bytes} = \frac{8192\text{ bits}}{8\text{ bits/byte}} = 1024\text{ bytes}$$

### ¿Por qué usamos `PROGMEM`?
Si guardamos 8 bitmaps en variables normales, consumirían $8 \times 1024\text{ B} = 8192\text{ B}$ de memoria RAM dinámica (SRAM). Al utilizar el modificador `PROGMEM` de Arduino:
```arduino
const unsigned char eye_normal[] PROGMEM = { ... };
```
Los datos se guardan en la memoria **Flash de 4 MB** del ESP32, dejando la memoria RAM 100% libre para el sistema operativo y futuras conexiones de red con la IA.

---

## 2. Dibujar un Bitmap en Pantalla

La librería Adafruit GFX proporciona el método `drawBitmap`:
```arduino
display.clearDisplay();
// drawBitmap(X, Y, puntero_bitmap, ancho, alto, color);
display.drawBitmap(0, 0, eye_happy, 128, 64, SSD1306_WHITE);
display.display();
```

---

## 3. Protocolo de Depuración Serial (Debug para IA)

Para que el robot reaccione a órdenes externas sin bloquear el procesador:
```arduino
void debugEyesSerial() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'H' || cmd == '2') {
      drawEyeExpression(display, eye_happy);
    }
  }
}
```

---

## 4. Temporización No Bloqueante con `millis()`

NUNCA uses `delay(2500)` en el loop principal, porque congelaría la lectura de comandos Serial y sensores. En su lugar:
```arduino
unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= INTERVALO_ANIMACION) {
  previousMillis = currentMillis;
  ejecutarSecuenciaAutonoma();
}
```
