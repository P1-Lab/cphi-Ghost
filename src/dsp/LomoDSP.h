#ifndef LOMO_DSP_H
#define LOMO_DSP_H

#include <cmath>
#include <algorithm>

/**
 * LomoDSP: Deterministic Imperfection Logic
 * Simulates Cosine-Fourth Vignetting and Lateral Chromatic Aberration.
 */
class LomoDSP {
public:
    struct Pixel { float r, g, b; };

    static void processFrame(Pixel* buffer, int width, int height) {
        float centerX = width / 2.0f;
        float centerY = height / 2.0f;
        float maxDist = std::sqrt(centerX * centerX + centerY * centerY);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int idx = y * width + x;
                
                // 1. Calculate Normalized Radial Distance
                float dx = (x - centerX) / centerX;
                float dy = (y - centerY) / centerY;
                float dist = std::sqrt(dx * dx + dy * dy);

                // 2. Cosine-Fourth Vignetting
                // Simulated falloff: intensity = cos(dist * alpha)^4
                float vignette = std::pow(std::cos(dist * 0.8f), 4.0f);
                vignette = std::clamp(vignette, 0.2f, 1.0f);

                // 3. Lateral Chromatic Aberration (Channel Shifting)
                // We sample slightly offset coordinates for R and B
                // Simplified here as a per-pixel color tint shift
                buffer[idx].r *= (1.0f + (dist * 0.05f)) * vignette;
                buffer[idx].g *= vignette;
                buffer[idx].b *= (1.0f - (dist * 0.05f)) * vignette;
            }
        }
    }
};

#endif
