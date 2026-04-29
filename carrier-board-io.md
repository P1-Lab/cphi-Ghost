<B>Carrier Board I/O: The Ghost Slot and Physical Firewalls</b><P>
The cphi-Ghost carrier board is the central nervous system that bridges the Rockchip RK3588 SoM to the physical world. It is designed with Forensic Isolation—ensuring that hardware remains subservient to the user’s physical commands, regardless of software state.
<P></P>
<b>1. The Ghost Slot (M.2 Key-B)</b><BR>
The cellular modem is isolated on a modular M.2 Key-B interface (typically 3042 or 3052 form factor). This prevents the baseband processor from having Direct Memory Access (DMA) to the main CPU, a common vulnerability in standard smartphones.<P></P>
<b>Critical Pinout (75-Position Connector):</b><P></P>
<UL><LI>Pins 2, 4, 70, 72, 74 (3.3V): Power rail for the modem.
<LI>Pins 1, 3, 5, 11, 27, 33, etc. (GND): Ground plane.
<LI>Pins 6 & 8 (W_DISABLE#): Hardware Airplane Mode. Logic LOW disables the RF radio.
<LI>Pins 67 (RESET#): Hardware reset for the modem.
<LI>USB 2.0/3.0 Interface: The primary data path between the RK3588 and the Modem.</UL>
<P></P>
<B>2. Physical Trace-Break Firewalls</B>
Mechanical Circuit Interventions
The Ghost features three heavy-duty SPST (Single Pole Single Throw) toggle switches. These are not "request buttons" for the OS; they are physical circuit breakers.
<P></P>
<B> MIC_KILL (Acoustic Firewall)</B><BR>

<UL><LI>Component: MEMS Microphone Array</LI>
<LI>Circuit Intervention: Interrupts VDD (3.3V)</LI>
<LI>Effect: Total acoustic silence. No signal can reach the ADC.</LI></UL>

<B>CAM_KILL (Optical Firewall)</b><BR>

<UL> <LI>Component: 50MP Sony IMX Module</LI>
<LI>Circuit Intervention: Interrupts CSI Clock / Power</LI>
<LI>Effect: The sensor cannot initialize. The OS sees "Device Not Found."</LI>
</UL>
<b>MODEM_KILL (RF Firewall)</b><BR>
<UL>
<LI>Component: M.2 Key-B Slot</LI>
<LI>Circuit Intervention: Interrupts 3.3V Main Rail</LI>
<LI>Effect: The modem is completely depowered. Total RF invisibility.</LI></ul>
<P></P>

<b>3. VGL-1 and Lomo Control Logic</b><BR>
These controls use high-reliability slide and hall-effect sensors to trigger the vitrification logic in the ghost-daemon.<P>
<b>VGL-1 Mode Switch (3-Position Slide)</b>
Connected to the RK3588 GPIO Bank 1 (GPIO1_D0 and GPIO1_D1).
<UL><LI>Logic Calculation: pin = bank * 32 + (group * 8 + X)
<LI>GPIO 56 (1_D0): High = Clinical / Low = U47 Mode.</LI>
<LI>GPIO 57 (1_D1): High = Clinical / Low = 4038 Mode.</LI></UL><P>
<b>Lomo Sled Detection</b><BR>
<UL><LI>Sensor: Sub-miniature Hall Effect Sensor (Digital Output).</LI>
<LI>GPIO 58 (1_D2): Triggered by the neodymium magnet on the lens carriage.</LI>
<LI>Action: Logic LOW triggers the LomoDSP image pipeline to engage vignetting and chromatic aberration filters.</LI></UL>
<P></P>
<b>4. Expansion Header (Sovereign Utility)</b><BR>
For field research, a 10-pin header provides direct access to the RK3588:
UART (TX/RX): For serial console access.
I2C: For external environmental sensors.
5V / 3.3V / GND: External power for peripherals.<P></P><BR>
A=A. The circuit is the law.

