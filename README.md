# Semana 03: Expresiones Oculares OLED (128x64) & Modo Debug Serial

[![Guía Maestra Web](https://img.shields.io/badge/Gu%C3%ADa%20Maestra%20Web-Cloudflare%20Edge-orange?style=for-the-badge&logo=cloudflare)](https://uets-st-portal.vgmiltonisaac.workers.dev/03-ojos-oled/)

> **Módulo:** Soporte Técnico (Sistemas Digitales e IoT) — 3° Bachillerato Técnico  
> **Institución:** Unidad Educativa Técnico Salesiano (UETS)  
> **Docentes:** Ing. Milton Velásquez / Ing. Christian Japón  
> **Ponderación Dual MIT:** 5.0 pts Código/Wokwi + 5.0 pts Screencast (4 min)  
> **Guía Interactiva:** https://uets-st-portal.vgmiltonisaac.workers.dev/03-ojos-oled/

---

## 🎯 Objetivos del Taller

1. **Modularidad en Firmware:** Abandonar los "mega scripts" y organizar el proyecto en librerías de cabecera (`logboot.h`, `eyes.h`) y un sketch principal (`main.ino`).
2. **Auto-diagnóstico POST:** Ejecutar la secuencia de arranque en el display OLED SSD1306 validando los subsistemas mediante el bus I2C (GPIO21 SDA / GPIO22 SCL).
3. **Matrices de Bitmaps en Flash:** Comprender el almacenamiento de imágenes monocromáticas de 128x64 en `PROGMEM` sin saturar la RAM dinámica (SRAM).
4. **Modo Debug Serial (Preparación para IA):** Implementar la función interactiva `debugEyesSerial()` para controlar en vivo las miradas del robot por el Monitor Serie (115200 bps) y recibir los estados emocionales que enviará la Inteligencia Artificial en el Trimestre 3.
5. **Máquina de Estados con `millis()`:** Alternar animaciones de forma fluida y no bloqueante.

---

## 🚀 Instrucciones Rápidas (Laboratorio Deep Freeze)

### 1. Configuración de Identidad en Git
Al sentarte en la computadora del laboratorio, abre una terminal y ejecuta:
```bash
git config --global user.name "TU_NOMBRE_APELLIDO"
git config --global user.email "tu_correo@ejemplo.com"
```

### 2. Fork y Clonado
1. Haz clic en **Fork** en el repositorio del docente.
2. Clona tu propio fork:
```bash
git clone https://github.com/TU_USUARIO/03-ojos-oled.git
cd 03-ojos-oled
git checkout -b entrega/nombre-apellido
```

### 3. Compilación y Simulación Wokwi
1. Abre esta carpeta en VS Code (`code .`).
2. Haz clic en el icono de **PlatformIO: Build (✔)** en la barra inferior azul.
3. Abre el archivo `diagram.json` y presiona el botón **Play (▶)** para iniciar la simulación.
4. Abre el Monitor Serie a **115200 bps** e interactúa enviando comandos (`1` a `8` o `H`, `A`, `N`).

### 4. Evaluación Automatizada
En cualquier momento puedes evaluar tu progreso con:
```bash
pnpm test
# o alternativamente:
node scripts/evaluar.js
```
*(El evaluador se sincroniza automáticamente con el repositorio oficial para que siempre tengas la última versión de los criterios).*

---

## 🥊 Retos Pedagógicos

| Reto | Descripción | Puntos |
| :--- | :--- | :---: |
| **Reto 01** | Integración de cabeceras, ejecución del POST con `runSystemPOST()` y renderizado de `eye_normal`. | **1.00 pt** |
| **Reto 02** | Modularización de expresiones reactivas (`eye_happy`, `eye_alert`). | **1.00 pt** |
| **Reto 03** | Secuencia de parpadeo (`eye_blink`) y miradas direccionales (`eye_look_left`, `eye_look_right`). | **1.50 pts** |
| **Reto 04** | Máquina de estados finitos (FSM) con `millis()` y función `debugEyesSerial()` para control con IA. | **1.50 pts** |
| **TOTAL** | **Bloque A (Circuito & Código en GitHub)** | **5.00 Puntos** |
