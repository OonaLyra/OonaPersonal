# blobtracker

> a low-level computer vision engine drifting somewhere between surveillance systems, recursive perception and emotional glitch aesthetics.

---

## Overview

`blobtracker` is an experimental computer vision project written in pure C.

The project started as a simple blob detection experiment during a sleepless night and slowly evolved into a modular perception engine capable of dissecting images, identifying regions of interest and transforming them into annotated visual artifacts.

The engine currently focuses on:

* low-level image processing
* brightness analysis
* primitive object detection
* blob region tracking
* recursive visual experimentation
* glitch aesthetics
* perception-oriented rendering pipelines

The current architecture is being actively rewritten into modular engine layers to support future expansion into:

* real-time surveillance systems
* motion analysis
* experimental CV pipelines
* recursive visual synthesis
* datamoshing-assisted rendering
* aesthetic-driven machine vision

---

# Current Architecture

The project has recently transitioned from a single monolithic source file into a modularized engine structure.

Current pipeline:

```text
main()
    ↓
image_devouring()
    ↓
image_dissecting()
    ↓
nebula_detection()
    ↓
object_watcher()
    ↓
object_exhibit()
    ↓
essence_enacted()
```

---

# Core Structures

## Soulcatcher

Represents the loaded image entity.

```c
typedef struct
{
	int	width;
	int	height;
	int	channels;
	unsigned char *data;
} Soulcatcher;
```

This structure acts as the physical vessel of the image inside the engine.

It stores:

* dimensions
* channel information
* raw pixel data

---

## Theeye

Stores temporary perception state during image traversal.

Current responsibilities include:

* visitation mapping
* blob statistics
* temporary tracking state

Example usage:

```c
eye->visited
eye->b_sum_x
eye->b_sum_y
eye->b_pixels
```

The structure exists to centralize machine perception state instead of scattering temporary variables across the entire codebase.

---

# Engine Layers

## image_devouring()

Responsible for:

* loading the image
* initializing engine entities
* starting the processing pipeline
* controlling memory lifecycle

```text
disk → memory → perception pipeline
```

---

## image_dissecting()

Acts as the orchestration layer.

Responsibilities:

* initializes perception maps
* prepares tracking state
* invokes detection systems

Current setup:

```c
eye->visited = calloc(...)
```

This function is becoming the central coordinator for future CV systems.

---

## nebula_detection()

Current perception layer.

Responsibilities:

* traverses every pixel
* computes brightness values
* applies preprocessing
* prepares blob detection

The current implementation intentionally darkens the image globally before analysis to exaggerate highlighted regions and future overlays.

```c
img->data[i] = img->data[i] / 2;
```

This preprocessing stage already contributes heavily to the engine's visual identity.

---

## object_watcher()

Planned flood-fill based blob tracker.

Future responsibilities:

* connected-component analysis
* recursive flood fill
* centroid calculation
* object size estimation
* object persistence tracking

This layer will eventually become the heart of the detection engine.

---

## object_exhibit()

Visual annotation layer.

Planned responsibilities:

* bounding box rendering
* overlay drawing
* connection lines
* object labeling
* glitch overlays
* tracking visualization

This is where surveillance imagery and digital art begin merging together.

---

## essence_enacted()

Final output layer.

Responsibilities:

* generates output filename
* preserves original filename
* exports processed image

Example:

```text
mirror.png
→
mirror_renewed.jpg
```

The engine intentionally treats rendered outputs as transformed artifacts instead of simple exports.

---

# Current Features

* Modular engine architecture(not modular enough yet, but you just wait.)
* Brightness analysis
* Pixel traversal
* Image preprocessing
* Automatic output naming
* Memory-safe image loading pipeline
* Experimental CV framework
* Recursive-ready architecture
* Object visitation mapping
* Future flood-fill integration support

---

# Planned Features

## Computer Vision

* Recursive flood fill
* Connected-component labeling
* Motion tracking
* Temporal tracking persistence
* Real-time webcam processing
* Video dissection pipelines

---

## Aesthetic Systems

* Datamoshing overlays
* Recursive frame degradation
* Compression artifact synthesis
* CRT-inspired overlays
* Subtitle systems
* Surveillance UI rendering
* Procedural visual noise
* Multi-layer recursive compositions
* Neon/magenta rendering pipelines

---

## Engine Expansion

* GPU acceleration experiments
* Multi-threading

---

# Philosophy

Most computer vision systems attempt to remove ambiguity.

`blobtracker` explores the opposite direction.

Noise is useful texture.
Detection instability becomes style.
Machine's failled attempts atmosphere.

The engine intentionally preserves imperfect detections because imperfect perception often creates more emotionally charged imagery than perfect classification ever could.


```text
"The problem isn't that I'm going insane, but rather that I'm not.

My true euphoria comes from c codes in a black canvas and low-res edits while i build digital flowers for a soul garden that i will one day gift away."
```

---

# Tech Stack

## Language

* C

## Libraries

* stb_image
* stb_image_write

## Areas

* Computer Vision
* Systems Programming
* Experimental Graphics
* Image Processing
* Procedural Rendering

---

# Build

## Linux / macOS

```bash
cc main.c processing.c -o blobtracker -lm
```

---

# Run

```bash
./blobtracker image.png
```

---

# Output

```text
image_renewed.jpg
```

---

# About the Author

Hi.

I'm Lyra — a transgender data analyst and data engineer currently studying software engineering at 42 São Paulo.

I like:

* low-level systems
* machine perception
* weird rendering pipelines
* emotionally charged software
* glitch aesthetics
* recursive image manipulation
* surveillance imagery

`blobtracker` started as insomnia-fueled experimentation and slowly became a way to externalize perception itself into code.

---

# Why Build This In C?

Because sometimes the point is not efficiency.

Sometimes the point is intimacy with the machine.

Yes, this could have been prototyped faster in Python using high-level CV libraries.

But writing perception systems in C forces direct contact with:

* memory
* traversal
* pixel logic
* engine structure
* computational anatomy

Every artifact becomes understandable at its lowest level.

And somehow, that changes the feeling of the software itself.

---

# Final Notes

`blobtracker` currently exists in a strange place between:

* surveillance software
* perception research
* systems programming
* glitch art
* emotional rendering
* cyber-aesthetic experimentation

And honestly?

That's just exactly where it belongs.

---

# License

MIT License.

Or do whatever you want with it.

Just make something strange.
