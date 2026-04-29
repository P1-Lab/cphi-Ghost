<h1>Known Challenges: The Sovereign Reality Check</h1>

<p>
The cphi-Ghost is a forensic instrument, not a mass-market consumer product.
Fulfilling the "A=A" philosophy requires acknowledging the friction inherent in building
a 10-year, repairable Linux terminal in 2026.
This document is a clinical assessment of the rough edges.
</p>

<h2>1. PostmarketOS &amp; RK3588 Maturity</h2>

<p>
While the Rockchip RK3588 has seen significant mainline Linux progress by 2026,
it remains an enthusiast-grade platform.
</p>

<h3>ISP &amp; Camera Stack</h3>
<p>
Driving a 50MP Sony sensor through the RK3588 internal ISP in mainline Linux is non-trivial.
Initial releases may lack advanced features such as Phase Detection Auto Focus (PDAF)
or high-speed video encoding.
</p>

<h3>GPU Acceleration</h3>
<p>
While 2D and 3D acceleration is stable, video hardware decoding and encoding in browser
environments often requires specific patching and can lead to thermal spikes.
</p>

<h2>2. Telephony &amp; ModemManager</h2>

<p>
The Ghost utilizes ModemManager on an M.2 module. This is the Sovereign Path,
but it is clunky compared to the mature proprietary RIL stack used in Android.
</p>

<h3>Handover Issues</h3>
<p>
Moving between LTE and WiFi Calling may require manual daemon restarts
in some forensic environments.
</p>

<h3>Voice Routing</h3>
<p>
Ensuring PipeWire, ALSA, and the M.2 modem handshake correctly for voice calls
requires precise latency tuning. If the audio buffer is not vitrified correctly,
the VGL-1 effect may stutter.
</p>

<h2>3. Thermal &amp; Power Profiles</h2>

<h3>The Warm Brick Effect</h3>
<p>
Because the CNC chassis is the heatsink, it will become warm to the touch
(up to 45°C) during sustained VGL-1 processing or 4G data tethering.
This is by design, but may feel unusual to users accustomed to plastic-insulated phones.
</p>

<h3>Power Management</h3>
<p>
A 10,000mAh battery provides major field life, but current PostmarketOS suspend and resume
behavior on RK3588 still consumes more idle power than flagship Android devices.
Expect 48 to 72 hours of standby, not weeks.
</p>

<h2>4. Mechanical &amp; Industrial Thickness</h2>

<h3>Ergonomics</h3>
<p>
At 20mm, the Ghost does not fit in tight pockets.
It is designed for holsters, field jackets, or tactical gear.
</p>

<h3>Optical Sled Wear</h3>
<p>
The mechanical Lomo sled uses a sub-miniature rail system.
While repairable, it is a moving part prone to dust ingress.
Periodic cleaning with compressed air is a required maintenance ritual.
</p>

<h2>5. Software UX (The Anti-Walled Garden)</h2>

<h3>App Availability</h3>
<p>
There is no App Store. If you need a specific tool, you must check Alpine apk repositories
or compile from source.
</p>

<h3>Complexity</h3>
<p>
This terminal assumes the user has basic knowledge of the Linux command line.
If you are looking for a plug-and-play appliance, the Ghost is not for you.
</p>

<blockquote>
A = A.<br>
Sovereignty is a skill, not a service.
</blockquote>
