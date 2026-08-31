
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit SPELL;

void setup()
{
   set_name("conjure ale");
   set_category("conjuration");
   set_targets(TARGET_ROOM);
   set_level(0);
   set_description("This spell conjures a small amount of ale, typically on the floor.");
}

void cast_spell(object ob, object reagent, int success)
{
   object ale;
   this_body()->simple_action("A streak of ale appears at the wave of $p hand.");
   ale = new ("domains/std/ale");
   ale->move(environment(this_body()));
}
