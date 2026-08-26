// FILENAME ~dark/obj/runesword.c
// A unique weapon in the mud, it acts as a standard sword, but has the
// special property of giving off light.  This makes the weapon very
// effective againest vampires.
// WRITTEN ON July 22,1995
// WRITTEN BY Gossip

#include <mudlib.h>
#include "obj.h"

inherit WEAPON ;

void create() {
        set ("author","gossip");
        set ("id", ({ "sword", "weapon", "runesword", "VampKiller" }) ) ;
        set ("short", "An ancient sword") ;
        set ("defaultshort", "An ancient sword");
        set ("long", @Endtext
It has a long blade which is mildly sharp. The blade itself seems to be
of a strange material, it's not quite metal.  The handle is made of pearl
and has 5 runes upon it.
Endtext
        ) ;
        set ("mass", 8000) ;
        set ("bulk", 500) ;
        set ("value", ({ 800, "gold" }) ) ;
        set ("weapon", 12) ;
        set ("damage", ({ 8,18 }) ) ;
        set ("name", "runesword. (glowing)") ;
        set_verbs2( ({ "attacks", "swings at", "stabs at", "slashes at" }) ) ;
        set ("second", 0) ;
        set ("nosecond",1) ;
        set ("type", "edged") ;
        set ("wield_func","rune_wield");
        set ("unwield_func","rune_unwield");
        // set ("prevent_insert",@@rune_prevent_insert); //hope this works.
}

void init()
{
// add_action("function_name","command_name");
}

void rune_wield() {
   set ("short", query("defaultshort")+" (glowing)");
   // "invisible" controls who can see this item presently the format is
   // set at: 0- everyone can see it, 1- players can't see it, 2- wizards
   // can't see it only admins can.
   set ("invisible", 1 ); // players don't see it if wielded
   say(CNAME+"'s sword disappears from view as it is wielded.\n");
   tell_object(this_player(), "As you wield it, It jumps to life, beginning to
glow, and\n"+
   "disappears from sight.  You can still feel it's presence in your hand.\n");
}

void rune_unwield() {
   set ("short", query("defaultshort"));
   // "invisible" controls who can see this item presently the format is
   // set at: 0- everyone can see it, 1- players can't see it, 2- wizards
   // can't see it only admins can.
   set ("invisible", 0 ); // players can see it again
   say(CNAME+"'s has a sword appear in their hand as it is unwielded.\n");
   tell_object(this_player(), "As you unwield it, It reappears into view, and
it's glow fades.\n");
}

int rune_prevent_insert() {
   this_player()->command("drop",this_object()); //drop this object.
   say(CNAME+"'s sword jumps from "+POSS+" hands.\n");
   tell_object(this_player(), "The runesword comes to life and jumps from your
hands.\n");
   return 1;
}

void kill_vampire() {
   tell_room(environment(this_player()), @Endtext
The runesword glows bright as a sun, and dives vicously into the vampire. It
buries itself to the hilt and explodes in a burst of flame and light.  The
vampire is quickly vanquished in flame.
Endtext
   );
}
