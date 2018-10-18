# Raspberry-Pi-UPS-Hat
Protect your Raspberry Pi from power cuts with help from this UPS (and an ATTiny85)

# See video #124 at https://wwww.youtube.com/ralphbacon  
(Direct link to video:  )

Power cut? No problem!

Banggood have kindly supplied me with the Geekworm Power Pack Pro V1.1 Lithium Battery Power Source UPS HAT - a bit of a mouthful but basically it's a UPS (Uninteruptable Power Supply) for your Raspberry Pi.

I'm using a Pi Model 3B+ but it should work with any 40-pin header model. Here's the link:

https://www.banggood.com/Geekworm-Power-Pack-Pro-V1_1-Lithium-Battery-Power-Source-UPS-HAT-Expansion-Board-For-Raspberry-Pi-p-1205973.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3312
(This is an affiliate link - if you click it and order the item within 14 days I get a tiny commission!)

Now, there is a well known "issue" with this board, inasmuch that if the battery becomes depleted it will not reconnect the power to the Pi once power is restored. Oops.

But a simple ATTiny85 module and a resistor or two plus a simple NPN transistor and we have the PERFECT solution!

The simple sketch I'm using to demonstrate this board, plus a circuit diagram can all be found on my GitHub.




