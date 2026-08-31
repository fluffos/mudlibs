#ifndef __KEEP_H__
#define __KEEP_H__
// Reconstructed for FluffOS conversion (AGENTS.md): the original keep.h
// shipped by wizards/whit/keep/ was missing from the source archive (not
// present anywhere in the raw tree), leaving every one of its ~68 room/
// mob/object files unable to compile ("Cannot #include keep.h", plus the
// cascading "Undefined variable 'GARDEN'/'GARDEN_SERVER'" from files that
// got far enough to reference the missing macros). All four macro values
// below are unambiguously derivable from the surviving directory layout
// and match this codebase's own convention for virtual-room domains (see
// include/domains/tundra.h's SERVER/ROOMS pair for the same shape) --
// wizards/whit/keep/rooms/garden/server.lpc already exists on disk and is
// exactly what GARDEN_SERVER must point at.
#define ROOMS "/wizards/whit/keep/rooms/"
#define GARDEN "/wizards/whit/keep/rooms/garden/"
#define GARDEN_SERVER "/wizards/whit/keep/rooms/garden/server"
#define WEP "/wizards/whit/keep/wep/"
#endif
