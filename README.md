# blobtracker

> A computer vision engine drifting somewhere between surveillance systems, recursive perception and emotional glitch aesthetics.

---

## Overview

`blobtracker` is an experimental low-level computer vision and image processing engine written in pure C.

What started as insomnia-fueled blob detection with the simple goal of helping me on create some cool aesthetics to edit images slowly evolved through experimentation into something a bit stranger:

* part surveillance software
* part perception engine
* part aesthetic synthesizer
* part glitch-art instrument
* part emotional rendering pipeline

The project focuses on building machine perception from the lowest possible level:

* raw pixel traversal
* brightness analysis
* recursive flood-fill logic
* blob tracking
* centroid estimation
* procedural overlays
* visual distortion
* recursive image manipulation

The engine intentionally preserves instability.

Noise, failed detections, fragmented tracking and visual corruption are often treated as aesthetic material instead of technical failure.

By design, `blobtracker` explores what happens when machine vision stops trying to become perfect and instead becomes expressive.

And in my definition, that's poetry, that's a  soul bottled inside lenses, memory maps and neon light.

---

# Philosophy

Most computer vision systems attempt to eliminate ambiguity.

`blobtracker` explores the opposite direction.

Here, uncertaint it's the texture.

Machine confusion is the standard atmosphere.

Failed perception becomes visual language.

The goal is simple: "That machine can see, but can it perceive images and catch the essence of what is inside them?"

This project currently exists somewhere between:

* computer vision
* systems programming
* digital art
* surveillance imagery
* recursive rendering
* glitch aesthetics
* transfem cyber-aesthetics
* experimental perception systems

---

# Current Architecture

Through cans of monster and sleep-deprivation, that engine recently evolved from a single monolithic source file into a modular pipeline architecture, while keeping the functions i wanted it to have, i built a better version of it more modularized and with openings to expansion.

Current workflow:

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

Represents the physical image essence loaded into memory.

```c
typedef struct
{
	int	width;
	int	height;
	int	channels;
	unsigned char *data;
} Soulcatcher;
```

The `Soulcatcher` structure acts as the vessel of perception itself.

It stores:

* image dimensions
* channel information
* raw pixel data
* the material body the engine will dissect

---

## Theeye

Stores temporary perception state during traversal.

Responsibilities include:

* visitation mapping
* recursive flood-fill state
* blob statistics
* centroid accumulation
* tracking memory

Example:

```c
eye->visited
eye->b_sum_x
eye->b_sum_y
eye->b_pixels
eye->blob_count
```

Instead of scattering temporary variables across the codebase, `Theeye` centralizes the machine's nervous systems perception while traversing an image.

---

# Engine Layers

## image_devouring()

Responsible for:

* loading image data from disk
* initializing engine entities
* starting the perception pipeline
* handling image lifecycle and memory ownership

```text
disk → memory → perception
```

This is the moment the engine "opens its eyes."

---

## image_dissecting()

Acts as the orchestration layer of the engine.

Responsibilities:

* initializes visitation maps
* prepares blob tracking state
* invokes detection systems
* coordinates perception modules

Current setup:

```c
eye->visited = calloc(...)
```

This function is becoming the central coordinator for planned CV subsystems to come.

---

## nebula_detection()

Current perception layer.

Responsibilities:

* traverses every pixel
* computes brightness
* preprocesses imagery
* prepares recursive object tracking

The current implementation globally darkens the image before analysis:

```c
img->data[i] = img->data[i] / 2;
```

Originally implemented for debugging visibility, this operation slowly became part of the engine's aesthetic identity.

The result resembles surveillance footage drifting through neon haze.

---

## object_watcher()

Recursive perception layer.

Current and planned responsibilities:

* flood-fill traversal
* connected-component analysis
* recursive blob tracking
* centroid estimation
* object measurement
* object persistence

The system not only remembers what it caught, but also stores where.

This function is effectively the central nervous system of the engine.

---

## object_exhibit()

Visual manifestation layer.
[Work in progress tho]
Responsibilities:

* rendering overlays
* drawing object annotations
* creating bounding visuals
* generating surveillance-style imagery
* procedural glitch markings

This is where the engine's technical perception starts becoming visual art.

---

## essence_enacted()

Final export layer.

Responsibilities:

* generates output filenames
* preserves original names
* materializes transformed artifacts
* exports processed imagery

Example:

```text
mirror.png
→
mirror_renewed.jpg
```

The engine intentionally treats processed outputs as transformed objects rather than edited files.

---

# Current Features

* Modular engine architecture
* Raw pixel traversal
* Brightness analysis
* Recursive-ready flood-fill pipeline
* Blob tracking foundations
* Centroid accumulation
* Pixel visitation maps
* Automatic output naming
* Experimental preprocessing systems
* Recursive perception infrastructure
* Neon/magenta aesthetic foundations
* Memory-safe image loading workflow
* Multi-file processing support

---

# Planned Features

## Computer Vision Systems

* Full recursive flood fill
* Connected-component labeling
* Multi-object tracking
* Motion persistence
* Optical flow experimentation
* Realtime webcam processing
* Temporal object memory

---

## Aesthetic Systems
* Datamoshing
* CRT-inspired rendering
* Subtitles
---

## Engine Expansion

* Multi-threading
* GPU Acceleration
---

# How It Works

Current simplified pipeline:

```text
Image
→ Image loading
→ Brightness preprocessing
→ Pixel traversal
→ Recursive region detection
→ Blob measurement
→ Centroid estimation
→ Overlay rendering
→ Artifact export
```

The engine currently uses brightness-based analysis combined with flood-fill traversal to identify distinguishable regions inside the image.

While technically imperfect, those imperfections actively contribute to the atmosphere of the generated outputs.

`blobtracker` does not currently attempt perfect classification.

It attempts perception.

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
* Recursive Systems

---

# Build

## Linux / macOS

```bash
cc main.c processing.c -o blobtracker -lm
```

## Windows
```bash
Work in Progress
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
(you can put how many images you want on the execution, the software
will devour and process them separately.)
---

# About the Author

Oy there.

I'm Lyra — a transgender sleepless data analyst and data engineer currently studying software engineering at 42 São Paulo.

I like:

* low-level systems
* recursive rendering
* emotionally charged software
* glitch aesthetics
* machine perception
* weird visual pipelines
* surveillance imagery
* building tools that feel alive

`blobtracker` started as technical experimentation and slowly became a way to externalize perception itself into software.

---

# Why Build This In C?

Because sometimes the point is not efficiency or versatility, or whatever else
can be the reason to choose anyone of the billion-times easier language to do it.

Sometimes the point is intimacy with the machine.

Yes, this could have been prototyped faster in Python using high-level CV libraries.

But writing perception systems in C forces direct contact with:

* memory
* traversal
* pixel logic
* recursion
* engine structure
* computational anatomy

Every artifact becomes understandable at its lowest level.

And somehow, that changes the feeling of the software itself.

---

# Final Notes

`blobtracker` currently exists somewhere between:

* surveillance software
* perception research
* recursive systems
* glitch art
* emotional rendering
* cyber-aesthetic experimentation

And honestly?

That's exactly where it belongs.

```text
"The problem isn't that I'm going insane, but rather that I'm not.

My true euphoria comes from c codes in a black canvas and low-res
edits while i build digital flowers for a soul garden that i will
one day gift away."
```

---

# License

MIT License.

Or do whatever you want with it.

Just make something strange.

