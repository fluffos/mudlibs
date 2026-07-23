#ifndef __ARMOR__
#define __ARMOR__

// Standard inheritable armor objects.
#define HEAD		"/std/armor/head"
#define NECK		"/std/armor/neck"
#define CLOTH		"/std/armor/cloth"
#define ARMOR		"/std/armor/armor"
// Re-enabled alongside the TYPE_ constants above (§8g): 14/10/5/5 real
// files respectively `inherit WAIST/WRISTS/SURCOAT/SHIELD` and fail
// otherwise ("unexpected L_IDENTIFIER" -- an undefined macro leaves a
// bare identifier where `inherit` expects a string).
#define SURCOAT         "/std/armor/surcoat"
#define WAIST           "/std/armor/waist"
#define WRISTS          "/std/armor/wrists"
#define SHIELD          "/std/armor/shield"
#define FINGER		"/std/armor/finger"
#define HANDS		"/std/armor/hands"
#define BOOTS		"/std/armor/boots"

// Standard armor types
#define TYPE_HEAD		"head"
#define TYPE_NECK		"neck"
#define TYPE_CLOTH		"cloth"
#define TYPE_ARMOR		"armor"
// Re-enabled per AGENTS.md §8g: std/armor/{surcoat,waist,wrists,shield}.lpc
// (and d/obj/inherit/armor/ equivalents) all reference these constants
// unconditionally -- commented out in the raw archive itself (pre-existing,
// not conversion fallout), leaving 8 files with "Undefined variable".
#define TYPE_SURCOAT    "surcoat"
#define TYPE_WAIST              "waist"
#define TYPE_WRISTS             "wrists"
#define TYPE_SHIELD             "shield"
#define TYPE_FINGER		"finger"
#define TYPE_HANDS		"hands"
#define TYPE_BOOTS		"boots"

#endif
