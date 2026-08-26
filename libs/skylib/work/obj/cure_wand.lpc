/* -*- LPC -*-
 */
inherit "/std/effects/healing/basic_cure";
inherit "/obj/wand";

void create() {
   do_setup++;
   wand::create();
   basic_cure::create();
   do_setup--;
   if ( do_setup )
      this_object()->setup();
} /* create() */
