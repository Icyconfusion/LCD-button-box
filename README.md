# LCD-button-box
A DIY stream deck style button box using a 3.5" LCD, tact switches and an ESP32 Devkit V1.

The button box uses an LCD seated at the bottom of the case. Above that, a PCB is suspended, containing the necessary tact switches. The PCB has square cutout holes to show the LCD image through. To press the buttons, there is a 3d printed stand on each set of 4 switches (one button), holding a clear acrylic square. Through this mechanism, the LCD is visible, and pressing the acylic presses the tact switches, registering a keypress. The bottom right button functions as a change layer button, where pressing that will cycle the button box to a new 'layer', with different icons and key outputs. 

The case is made using two parts, a base and a top. The base has 4 'legs' inside it to hold the lcd. 
 <img width="1064" height="716" alt="image" src="https://github.com/user-attachments/assets/e1abcdd4-b85d-4c9a-97ed-e44cf9c83d92" />
Above that, there is a perimeter ledge for the PCB to sit on. 
<img width="750" height="635" alt="image" src="https://github.com/user-attachments/assets/e1de9ddc-bfbc-4ddc-9f5b-400af2e83f53" />
The top attaches to the base using 4xM3 heatset inserts. 

<img width="895" height="626" alt="image" src="https://github.com/user-attachments/assets/dd8d1a24-f1cc-477b-8ffe-d7a231795a47" />

The ESP32 and switches are soldered to the PCB, and headers are soldered in place of the LCD. Jumper wires connect these headers down, underneath the LCD and into the pins on the bottom of the LCD.

<img width="994" height="562" alt="image" src="https://github.com/user-attachments/assets/a16796c4-287b-4a3e-a356-fafdde8b323f" />

The button box connects to devices by bluetooth, but requires a micro usb power source. The button box outputs macros using a combination of CTRL, SHIFT, ALT and F14+ keys to ensure unique macros.

Bill of materials
1x ESP32 Devkit V1
24x Tactile switch 6x6x5mm
1x 3.5" TFT 480x320 LCD screen
1x 40 pin male headers
20x Female - female jumper wires
3d printed parts
PCB


