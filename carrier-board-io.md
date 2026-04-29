<h1>Carrier Board I/O: The Ghost Slot and Physical Firewalls</h1>

<p>
The cphi-Ghost carrier board is the central nervous system that bridges the Rockchip RK3588 SoM to the physical world.
It is designed with Forensic Isolation—ensuring that hardware remains subservient to the user’s physical commands,
regardless of software state.
</p>

<h2>1. The Ghost Slot (M.2 Key-B)</h2>

<p>
The cellular modem is isolated on a modular M.2 Key-B interface (typically 3042 or 3052 form factor).
This prevents the baseband processor from having direct memory access (DMA) to the main CPU,
a common vulnerability in standard smartphones.
</p>

<h3>Critical Pinout (75-Position Connector)</h3>

<p><strong>Power Rails:</strong></p>
<p>
Pins 2, 4, 70, 72, 74 — 3.3V supply to modem
</p>

<p><strong>Ground:</strong></p>
<p>
Pins 1, 3, 5, 11, 27, 33 (and others) — Ground plane
</p>

<p><strong>Control Signals:</strong></p>

<p>
W_DISABLE# (Pins 6 &amp; 8): Hardware airplane mode. Logic LOW disables RF radio.
</p>

<p>
RESET# (Pin 67): Hardware reset for modem
</p>

<p><strong>Data Path:</strong></p>
<p>
USB 2.0 / USB 3.0 interface between RK3588 and modem
</p>

<h2>2. Physical Trace-Break Firewalls</h2>

<p>
The Ghost features three heavy-duty SPST toggle switches.
These are not software requests—they are physical circuit breakers.
</p>

<table>
<tr>
<th>Switch</th>
<th>Component</th>
<th>Circuit Intervention</th>
<th>Effect</th>
</tr>

<tr>
<td>MIC_KILL</td>
<td>MEMS Microphone Array</td>
<td>Interrupts 3.3V VDD</td>
<td>Total acoustic silence. No signal reaches ADC.</td>
</tr>

<tr>
<td>CAM_KILL</td>
<td>50MP Sony IMX Sensor</td>
<td>Interrupts CSI clock / power</td>
<td>Sensor cannot initialize. OS reports device not found.</td>
</tr>

<tr>
<td>MODEM_KILL</td>
<td>M.2 Key-B Slot</td>
<td>Interrupts 3.3V main rail</td>
<td>Total RF invisibility. Full hardware shutdown.</td>
</tr>
</table>

<h2>3. VGL-1 and Lomo Control Logic</h2>

<p>
These controls use high-reliability slide and Hall-effect sensors
to trigger vitrification logic in the ghost-daemon.
</p>

<h3>VGL-1 Mode Switch (3-Position Slide)</h3>

<p>
Connected to RK3588 GPIO Bank 1 (GPIO1_D0 and GPIO1_D1).
</p>

<p>
Logic mapping:
</p>

<p>
GPIO 56 (1_D0): High = Clinical / Low = U47 Mode<br>
GPIO 57 (1_D1): High = Clinical / Low = 4038 Mode
</p>

<h3>Lomo Sled Detection</h3>

<p>
Sensor: Sub-miniature Hall-effect sensor (digital output)
</p>

<p>
GPIO 58 (1_D2): Triggered by neodymium magnet on lens carriage
</p>

<p>
Action: Logic LOW triggers LomoDSP pipeline (vignetting + chromatic aberration)
</p>

<h2>4. Expansion Header (Sovereign Utility)</h2>

<p>
For field research, a 10-pin header provides direct access to the RK3588:
</p>

<ul>
<li>UART (TX/RX): Serial console access</li>
<li>I2C: External environmental sensors</li>
<li>5V / 3.3V / GND: Peripheral power supply</li>
</ul>

<blockquote>
A = A.<br>
The circuit is the law.
</blockquote>
