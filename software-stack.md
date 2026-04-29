<b>Software Stack: Sovereign Linux & PipeWire Vitrification</b><BR>
The cphi-Ghost rejects the Android/AOSP model. Android is a surveillance-first OS designed to abstract the user away from the iron. The Ghost runs PostmarketOS, a true mainline Linux distribution that treats the terminal as a workstation, not a mobile data-harvesting node.
<P></P>
<b>1. The Core: PostmarketOS (Edge)</b>
We utilize the mainline Linux kernel (v6.x+) specifically compiled for the Rockchip RK3588. <P></P>                                                                                 
<UL><LI>Init System: OpenRC (Fast, lightweight, no systemd bloat).</LI>
<LI>UI Environment: Phosh (Phone Shell based on GNOME) or Sxmo (Simple X Mobile) for the minimalist/forensic user.</LI>
<LI>Storage: Full Disk Encryption (LUKS) is mandatory on the /home partition, tied to a hardware-backed key or a boot-time passphrase.</LI>
</UL><P></P>
<B>2. Audio Architecture: PipeWire & VGL-1</B>
Standard cellular audio is handled by the carrier's AMR-WB/EVS codecs, which are designed to save bandwidth, not preserve truth. The Ghost uses PipeWire to intercept the audio graph and apply vitrification before the signal leaves the device.<P></P>
<b>The PipeWire Filter Chain</b><BR>
The ghost-daemon manages a dynamic filter graph using LADSPA plugins:<p>
<UL><LI>Source: Hardware MEMS Mic (Raw I2S).</LI>
<LI>Filter Node: ghost_vgl1_filter.</LI>
<LI>If Switch = Pos 1: Engages U47 (Soft-knee tube saturation + 5kHz shelf).</LI>
<LI>If Switch = Pos 2: Engages 4038 (12kHz LPF + 200Hz Gaussian Bloom).</LI>
<LI>Sink: VoIP Client (Signal/Matrix) or ModemManager Voice Port.</LI></UL>
<P></P>
<B>3. Imaging: The Lomo Pipeline</B>
The 50MP Sony sensor produces sterile, hyper-sharpened data. The Lomo philosophy requires a return to "deterministic imperfection."<P></P>
<UL><LI>Driver: v4l2 (Video4Linux2).</LI>
<LI>Processing: When the Hall sensor detects the mechanical Lomo Sled, the LomoDSP module intercepts the raw frame buffer.</LI>
<LI>Application: It applies a pixel-shader to simulate Cosine-Fourth Vignetting (light falloff toward corners) and Chromatic Aberration (red/blue fringing). This makes the image "useless" for facial recognition databases while preserving the aesthetic "soul" of the moment.</LI></UL>
<P></P>
<B>4. Telephony: ModemManager</B>
The Ghost treats the cellular modem as a standard M.2 peripheral, similar to a laptop modem.<P></P>
<UL> <LI>Backend: ModemManager + NetworkManager.</LI>
<LI>Voice: Routed via the DBus interface.</LI>
<LI>Privacy Protocol: The modem is isolated. It has no access to the OS memory. When the MODEM_KILL switch is flipped, the OS simply sees a "Disconnected Peripheral" event. No "Airplane Mode" software handshake is required.</LI></UL>
<P></P>
<B>5. Security & Maintenance</B>
<UL><LI>No App Store: Software is managed via apk (Alpine Package Keeper).</LI>
<LI>Forensic Audit: Every running process is visible via htop. There are no "hidden" Google Play Services or background telemetry daemons.</LI>
<LI>Recovery: A physical microSD slot allows for an "Emergency Boot" into a clean forensic environment if the internal eMMC is compromised.</LI></UL>
<P></P>A=A. The software serves the hardware.

