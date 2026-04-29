<h1>Software Stack: Sovereign Linux &amp; PipeWire Vitrification</h1>

<p>
The cphi-Ghost rejects the Android/AOSP model. Android is a surveillance-first OS
designed to abstract the user away from the iron.
The Ghost runs PostmarketOS, a true mainline Linux distribution that treats the terminal
as a workstation, not a mobile data-harvesting node.
</p>

<h2>1. The Core: PostmarketOS (Edge)</h2>

<p>
We utilize the mainline Linux kernel (v6.x+) compiled for the Rockchip RK3588.
</p>

<p><strong>Init System:</strong> OpenRC (fast, lightweight, no systemd bloat)</p>

<p><strong>UI Environment:</strong> Phosh (GNOME-based) or Sxmo for minimalist forensic operation</p>

<p><strong>Storage:</strong> Full disk encryption (LUKS) on /home partition</p>

<p>
Encryption is tied to either a hardware-backed key or boot-time passphrase.
</p>

<h2>2. Audio Architecture: PipeWire &amp; VGL-1</h2>

<p>
Standard cellular audio codecs (AMR-WB / EVS) optimize for bandwidth, not fidelity.
The Ghost uses PipeWire to intercept the full audio graph and apply vitrification
before the signal leaves the device.
</p>

<h3>The PipeWire Filter Chain</h3>

<p>
The ghost-daemon manages a dynamic filter graph using LADSPA plugins:
</p>

<ul>
<li><strong>Source:</strong> Hardware MEMS microphone (raw I2S)</li>
<li><strong>Filter Node:</strong> ghost_vgl1_filter</li>
<li><strong>Output Sink:</strong> VoIP client (Signal / Matrix) or ModemManager voice port</li>
</ul>

<p><strong>Mode Logic:</strong></p>

<ul>
<li>Switch Position 1 → U47 mode (soft-knee tube saturation, 5kHz shelf)</li>
<li>Switch Position 2 → 4038 mode (12kHz low-pass filter, 200Hz Gaussian bloom)</li>
</ul>

<h2>3. Imaging: The Lomo Pipeline</h2>

<p>
The 50MP Sony sensor produces sterile, hyper-sharpened computational imagery.
The Lomo philosophy enforces deterministic imperfection.
</p>

<p>
Driver: v4l2 (Video4Linux2)
</p>

<p>
When the Hall sensor detects the mechanical Lomo sled, the LomoDSP module
intercepts the raw frame buffer.
</p>

<p>
Processing applies a pixel-shader simulation of:
</p>

<ul>
<li>Cosine-fourth vignetting (light falloff toward corners)</li>
<li>Chromatic aberration (red/blue fringing)</li>
</ul>

<p>
Result: imagery that resists facial recognition pipelines while preserving
the perceptual "weight" of the moment.
</p>

<h2>4. Telephony: ModemManager</h2>

<p>
The Ghost treats the cellular modem as a standard M.2 peripheral.
</p>

<p><strong>Backend:</strong> ModemManager + NetworkManager</p>

<p>
Voice is routed via DBus interfaces.
</p>

<p>
When MODEM_KILL is engaged, the OS registers a simple disconnected peripheral event.
No software "airplane mode" abstraction is required.
</p>

<h2>5. Security &amp; Maintenance</h2>

<ul>
<li><strong>No App Store:</strong> Software managed via apk (Alpine Package Keeper)</li>
<li><strong>Forensic Audit:</strong> All processes visible via htop; no hidden telemetry</li>
<li><strong>Recovery:</strong> Physical microSD slot enables clean emergency boot environment</li>
</ul>

<blockquote>
A = A.<br>
The software serves the hardware.
</blockquote>
