# Last sketch in Nano n3

Es el ejemplo de la libreria nepixel con cambio en num led
**C:\Users\josec\OneDrive\Documentos\03_MAKER\MK_PROJECTS\Pnpx8_32\strandtest_59_b50**

# Last HW connectiosn and configuration in Nano n3

Nano_l = MCU Nano n3 + tira 59 led 5volt con resistencia 470 ohm ( cutre) , (es la que tenia roto primer led)

# Last sketch in esp32 dev kit c v4

Es el ejemplo de la libreria neopixel con cambio en num led y pin 5
**C:\Users\josec\OneDrive\Documentos\03_MAKER\MK_PROJECTS\Pnpx8_32\strandtest_59_b50**

# HW connection and configuration in esp32 dev kit c v4#

ESP32_l = ESP32 dev kitc v4 + tira 59 led 5volt con resistencia 470 ohm ( cutre) , (es la que tenia roto primer led) DI = GPIO5, alimentación 5 volt

# HW connection and configuration in esp32 dev kit c v4

ESP32WK_l = ESP32 WIFI KIT WITH OLED DISPLAY + tira 59 led 5volt con resistencia 470 ohm ( cutre) , (es la que tenia roto primer led) DI = GPI12, alimentación 5 volt

| Date       | Date Step | Target                                            | mc prog   | HW config | Step actions & Result | Step Pending   | Step Comments & Links                                           |
|:----------:|:---------:|:-------------------------------------------------:|:---------:|:---------:|:---------------------:|:--------------:|:---------------------------------------------------------------:|
| 16-12-2022 | 1         | basic test with 59 neopixel strip                 | Nano_l    | Arduino   | OK                    | no             | Arduino IDE, Bright not too high see wiki                       |
| 17-12-2022 | 1         | basic test with 59 neopixel strip in 3.3 volt mcu | ESP32_l   | Arduino   | OK                    | no             | Arduino IDE, strandtest pin 5, bright 25, mcu=esp32 dev kitc v4 |
| 18-12-2022 | 2         | basic test in micropython                         | ESP32WK_L | upython   | OK                    | test a rainbow | works well with 5 or 3.3 volt                                   |
