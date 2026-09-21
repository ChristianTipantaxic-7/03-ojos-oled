#ifndef LOGO_H
#define LOGO_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Bitmap del logo
const unsigned char epd_bitmap_descarga[] PROGMEM = {
  // PEGA AQUÍ TODOS LOS BYTES DEL BITMAP 148x148
};

// Dimensiones originales del bitmap
#define LOGO_WIDTH 148
#define LOGO_HEIGHT 148

// Mostrar el logo centrado, recortando los bordes
inline void drawLogo(Adafruit_SSD1306 &display) {
  display.clearDisplay();

  // La OLED es 128x64, por eso se muestra
  // solamente la parte central del logo.
  display.drawBitmap(
    -10,
    -42,
    epd_bitmap_descarga,
    LOGO_WIDTH,
    LOGO_HEIGHT,
    SSD1306_WHITE
  );

  display.display();
}

#endif