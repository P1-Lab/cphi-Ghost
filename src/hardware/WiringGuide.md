<h1>Hardware Wiring Guide: Physical Implementation</h1>

<p>
This guide details the precision soldering required to bridge the physical switches
to the RK3588 carrier board.
</p>

<h2>1. Power Firewalls (The Kill Switches)</h2>

<p>
These switches interrupt the actual voltage traces.
Do not use GPIO for these functions; they must be physical.
</p>

<h3>MIC_KILL</h3>
<p>
Locate the 3.3V VCC trace leading to the MEMS microphone array.
Cut the trace and solder an SPST toggle switch in series.
</p>

<h3>CAM_KILL</h3>
<p>
Locate the 1.8V / 2.8V VDD trace for the Sony IMX sensor.
Cut the trace and solder an SPST toggle switch in series.
</p>

<h3>MODEM_KILL</h3>
<p>
Locate the 3.3V rail feeding the M.2 Key-B slot.
Interrupt it with a high-current SPST toggle switch rated for a minimum of 1A.
</p>

<h2>2. Logic Switches (VGL-1 &amp; Lomo)</h2>

<p>
These pins utilize internal pull-up resistors configured in ghost-daemon.cpp.
</p>

<table>
<tr>
<th>Component</th>
<th>Switch Pin</th>
<th>Ground Pin</th>
<th>RK3588 GPIO</th>
</tr>

<tr>
<td>U47 Mode</td>
<td>Slide Pos 1</td>
<td>Common GND</td>
<td>GPIO1_D0 (Pin 56)</td>
</tr>

<tr>
<td>4038 Mode</td>
<td>Slide Pos 2</td>
<td>Common GND</td>
<td>GPIO1_D1 (Pin 57)</td>
</tr>

<tr>
<td>Lomo Sled</td>
<td>Hall V-Out</td>
<td>Common GND</td>
<td>GPIO1_D2 (Pin 58)</td>
</tr>
</table>

<h2>3. Battery Terminals</h2>

<p>
The dual 21700 cells are wired in parallel to achieve 10,000mAh at 3.7V nominal.
</p>

<p>
Use 18AWG silicone wire for the main power bus.
</p>

<p>
The stainless steel compression plate ensures physical contact.
However, we recommend spot-welding nickel tabs to the cells and bolting those tabs
to the carrier board terminals for maximum vibration resistance.
</p>
