---
name: colour-coding
description: Oxidus true colour system reference. Consult when writing or modifying output strings that use colour codes, or when choosing colours for new content.
---

# Oxidus Colour Code Reference

Oxidus uses a true colour system based on hexadecimal RGB values enclosed in double braces. It supports full 24-bit colour as well as the 256-colour ANSI palette.

**Core files:**
- `adm/daemons/colour.lpc` — colour daemon (COLOUR_D)
- `adm/simul_efun/colour.lpc` — simul_efun utilities (e.g., `gradient_hex()`)
- `include/colour.h` — regex patterns and system colour constants
- `cmds/std/colour.lpc` — player colour command
- `adm/simul_efun/string.lpc` — `colourp()`, `no_ansi()`

## Basic Syntax

| Syntax | Purpose |
|---|---|
| `{{RRGGBB}}` | Foreground colour (6-digit hex) |
| `{{RGB}}` | Foreground colour (3-digit shorthand) |
| `^^RRGGBB^^` | Background colour (6-digit hex) |
| `^^RGB^^` | Background colour (3-digit shorthand) |
| `{{res}}` or `{{RES}}` | Reset all formatting and colour to default |

Examples:
- `{{FF0000}}` — red foreground
- `{{F00}}` — red foreground (shorthand)
- `^^0000FF^^` — blue background
- `^^00F^^` — blue background (shorthand)
- `{{FFFFFF}}^^FF0000^^` — white text on red background

Unlike Pinkfish-style codes, you do not need to reset between colour changes — the system simply switches colours. Use `{{res}}` when you want to return to default. `{{res}}` resets both foreground and background.

## Text Formatting Codes

Formatting attributes use `{{XY}}` where X is the attribute and Y is `1` (on) or `0` (off):

| Code | Function |
|---|---|
| `{{bl0}}` / `{{bl1}}` | Bold off / on |
| `{{di0}}` / `{{di1}}` | Dim off / on |
| `{{it0}}` / `{{it1}}` | Italic off / on |
| `{{ul0}}` / `{{ul1}}` | Underline off / on |
| `{{fl0}}` / `{{fl1}}` | Flash/blink off / on |
| `{{re0}}` / `{{re1}}` | Reverse video off / on |
| `{{st0}}` / `{{st1}}` | Strikethrough off / on |
| `{{ol0}}` / `{{ol1}}` | Overline off / on |

## System Colour Constants

Defined in `include/colour.h` for consistent use across game systems:

| Constant | Hex | Colour | Use |
|---|---|---|---|
| `SYSTEM_OK` | `{{009966}}` | Green | Success messages |
| `SYSTEM_ERROR` | `{{CC0000}}` | Red | Error messages |
| `SYSTEM_WARNING` | `{{FF9900}}` | Orange | Warning messages |
| `SYSTEM_INFO` | `{{FFFF66}}` | Yellow | Informational messages |
| `SYSTEM_QUERY` | `{{0066FF}}` | Blue | Query/prompt messages |
| `SYSTEM_DEBUG` | `{{CC00CC}}` | Magenta | Debug messages |

## ANSI Escape Sequences

The colour daemon converts hex codes to 24-bit true colour ANSI sequences:

- Foreground: `\e[38;2;R;G;Bm` (from `{{RRGGBB}}`)
- Background: `\e[48;2;R;G;Bm` (from `^^RRGGBB^^`)

For example, `{{FF0000}}` becomes `\e[38;2;255;0;0m` and `^^0000FF^^` becomes `\e[48;2;0;0;255m`.

## Daemon Functions

Key public functions on `COLOUR_D`:

| Function | Purpose |
|---|---|
| `substituteColour(text, mode)` | Parse and replace colour codes. Mode `"on"` converts to ANSI, `"plain"`/`"off"` strips them |
| `hexToRgb(hex)` | Convert hex string to `({ r, g, b })` array |
| `rgbToHex(rgb)` | Convert `({ r, g, b })` array to hex string |
| `rgbToSequence(rgb, mode)` | Convert RGB to ANSI escape sequence |
| `hextToSequence(hex, mode)` | Convert hex to ANSI escape sequence |
| `colourToRgb(code)` | Convert 256-colour code to RGB array |
| `rgbToColour(r, g, b)` | Convert RGB to 256-colour code |
| `colourToGreyscale(code)` | Convert colour to greyscale |
| `wrap(str, wrap_at, indent_at)` | Text wrapping that preserves colour |
| `get_colour_list()` | Display all available colours |

## Simul_efun Functions

| Function | Location | Purpose |
|---|---|---|
| `gradient_hex(hex, step)` | `adm/simul_efun/colour.lpc` | Create colour gradients |
| `colourp(str)` | `adm/simul_efun/string.lpc` | Check if string contains colour codes |
| `no_ansi(str)` | `adm/simul_efun/string.lpc` | Strip all colour codes (uses `substituteColour(str, "plain")`) |

## Accessibility

- **Luminance checking** — `getLuminance()` and `getAccessibleLuminanceMultiplier()` ensure minimum readability
- **Dark colour substitution** — `substituteTooDark()` brightens colours below readability threshold
- **Greyscale conversion** — `colourToGreyscale()` for accessibility needs

## User Preferences

Players can configure:
- `colour` — `"on"` or `"off"` to enable/disable colours
- `highlight_colour` — preferred highlight colour
- `highlight` — `"on"` or `"off"` for keyword highlighting
- `combat_hit_colour` — colour for combat hit messages
- `combat_miss_colour` — colour for combat miss messages

## Usage Examples

```lpc
// Simple coloured short description
set_short("a {{fc3}}massive hammer{{res}}");

// 3-digit and 6-digit hex in descriptions
set_short("A little {{070}}green dragon{{RES}}");
set_long("Its scales shimmer with {{0F0}}emerald green light{{RES}}.");

// Background colours
tell(caller, "^^FF0000^^{{FFFFFF}} WARNING {{res}}");  // white on red
tell(caller, "^^003366^^{{FFCC00}}highlighted text{{res}}");

// Combined foreground and background
set_short("a {{FFFFFF}}^^CC0000^^danger sign{{res}}");

// Using system constants
printf("%sError: %s%s\n", SYSTEM_ERROR, message, "{{res}}");

// Dynamic colour building
colour = "{{" + hex_value + "}}";
bg_colour = "^^" + hex_value + "^^";
```
