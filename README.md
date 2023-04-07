# dual_AS5600
Just a simple coordinates display for a manual Dobson

To help point with my manual Dobson I added two AS5600 encoders on Azimuth and Altitude axis.
Directly mounted on the axes withour demultiplication the accuracy is in the range of 5.27 arc minutes.
The whole thing is not meant to be really precise but just hep to point objects more easily.

During first setup one has to calibrate sensor position so that telescope hozizontal shows 0° altitude
and north position shows 0° north.

Then during telescope setup in the night, just cebter a known object (I use Polaris) and adjust the coordinate display
to the real coordinates of the object.
In such a way it calibrated the position.

To make things easy and simple I just used all three i2c interfaces of the Blackpil (STM32F411CEU6) so that I could connect
both AS5600 (they have fixed address)
and the SSD1306 Oled, each on a dedicated i2c interface.

Thats it
stupid but helpfull

Hardware needed:
1 x BlackPill
2 x AS5600   
1 x OLED SSD1306 0,96" i2c version
4 x push buttons


