# blobtracker

> a transfem computer vision experiment somewhere between surveillance software and emotional glitch art.

## Overview

`blobtracker` is a low-level computer vision and image processing project written in C.

Originally created as an experiment in blob detection and primitive object tracking, this project slowly began to evolve into something stranger:

* part surveillance software
* part aesthetic engine
* part perception experiment
* part digital art instrument

The project combines:

* image thresholding
* centroid estimation
* primitive blob tracking
* recursive visual composition
* glitch aesthetics
* datamoshing-inspired visuals
* experimental machine perception

The current versions intentionally preserve imperfections.

Detection instability, noisy thresholds, inaccurate tracking, and visual artifacts are not always treated as flaws. Many of them actively contribute to the visual identity of the generated outputs. By my definition, this is soul bottled inside lenses and neon lights.

---

## Philosophy

Most software attempts to remove uncertainty.

`blobtracker` explores what happens when uncertainty becomes texture.

The goal is simple:

> "make a machine perceive images and catch the essence of what is inside them."

This project exists somewhere in the intersection between:

* computer vision
* systems programming
* digital art
* glitch aesthetics
* surveillance imagery
* recursive image processing
* transfem cyber-aesthetics

---

## Features

### Current Features

* Brightness-based blob detection
* Primitive region measurement
* Centroid estimation
* Bounding box rendering
* Pixel visitation maps
* Image annotation output
* Experimental visual processing pipeline
* Purple/magenta visual overlay system
* Recursive image manipulation support

### Planned Features

* Real connected-component detection
* Flood fill / BFS tracking
* Video processing
* Multi-frame tracking persistence
* Motion trails
* Optical flow experiments
* Fake confidence scores
* Temporal distortion systems
* Recursive frame degradation
* Compression artifact synthesis
* Procedural subtitle/text overlays
* Realtime webcam tracking
* GPU acceleration experiments
* Datamoshing integration
* Glitch feedback loops
(But it can go into many different ways...)

---

## Tech Stack

### Language

* C

### Libraries

* stb_image
* stb_image_write

### Paradigms / Areas

* Low-level image processing
* Computer vision
* Systems programming
* Experimental graphics
* Procedural visual generation

---

## Build

### Linux / macOS

```bash
cc blobtracker.c -o blobtracker -lm
```

### Run

```bash
./blobtracker image.png
```

Output:

```text
finished_job.jpg
```

---

## How It Works

The current pipeline roughly follows:

```text
Image
→ Brightness thresholding
→ Pixel visitation mapping
→ Primitive blob region detection
→ Centroid estimation
→ Bounding box rendering
→ Output image generation
```

At the moment, the project does not yet implement true connected-component analysis.

The tracker currently scans large local regions around bright pixels to estimate blobs. While technically imperfect, this behavior also creates unstable and fragmented detections that contribute to the project's aesthetic identity.

---

## About the Author

Hi.

I'm Lyra — a transfem data analyst and data engineer currently studying software engineering at 42 São Paulo.

I like:

* low-level programming
* weird visual systems
* machine perception
* glitch aesthetics
* digital art
* recursive image manipulation
* emotionally charged software
* building tools that feel alive

`blobtracker` started as a technical curiosity and slowly became a way to externalize my own visual language into software.

---

## Why?

Because proprietary software can imitate aesthetics.

But building your own tools means embedding your perception directly into the machine.

"The problem isn't that I'm going insane, but rather that I'm not.

My true euphoria comes from c codes in a black canvas and low-res edits while i build digital flowers for a soul garden that i will one day gift."

---

## License

MIT License

Or do whatever you want with it.

Just make something strange.