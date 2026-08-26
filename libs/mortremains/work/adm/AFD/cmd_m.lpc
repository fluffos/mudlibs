// cmd_m.c
// This file is inherited by all commands.
// It insures that they have euid privileges and can't be shadowed,
// and makes them go away when unused.
// If you see a command that doesn't inherit it, you should alter that command
// to inherit it.
// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(Jan 19, 1991)
// Modifed by Buddha(2-18-92)
// Modified by Shard(May 28, 1992)

#include <config.h>

// This is there because I noticed /bin modules weren't going away...

void clean_up() { destruct(this_object()); }

// This gets used a lot.

void create() { seteuid(getuid(this_object())); }

// This is necessary to maintain security
// - Shard
int query_prevent_shadow() { return (1); }

/* EOF */
