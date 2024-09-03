# **Dual Fixed-Voltage Power Supply with V,I Readout**
![Complete PS](./Pictures/IMG_3282.JPG)
## Background
The motivation behind this project was that in the past I have come across a need for a portable fixed-voltage 3.3V and 5V supplies. Specifically, I needed a supply that didn’t require me to set up a variable lab power supply while also being portable and rugged so that I could take it on the go.
Why did it end up taking on this *”polished”* look? I was looking to gain more SMD soldering experience and further my experience in PCB layout and schematic documentation. So, I approached this project in a more methodical, thorough-engineering manner than what I do typically for other personal projects of mine.
## Design and Construction
The main and display PCBs were captured and routed in KiCad, while the back and front enclosure panels were designed in Fusion 360. The code was, and is, written using the Arduino IDE and framework thanks only to the existence of the megaTinyCore library for 2-series attiny chips.
## Result
As seen in the picture above, the resulting power supply is certainly an *aesthetic*, but it is functional which is the most important thing. It took two PCB revisions of the main board because of wrong footprints for two resistors, and ~1 month of daily effort. There were many hours spent at my bench with an oscilloscope debugging my own oversights in the first PCB revision but I enjoyed every minute. The approach I took paid off since I've gained a lot of knowledge and experience where I wanted to, and the result is something I'm proud to share.
