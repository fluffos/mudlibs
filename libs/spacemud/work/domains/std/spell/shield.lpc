/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit SPELL;

void setup()
{
   set_name("shield");
   set_category("abjuration");
   set_targets(TARGET_ROOM);
   extra_reflex_cost(1);
   set_description("This spell creates a semi-transparent blue shield in front of the caster protecting against "
                   "incoming bludgeoning attacks.");
}

void cast_spell(object ob, object reagent, int success)
{
   this_body()->simple_action("A semi-transparent blue shield materializes in front of $n.");
   transient("shield", 1, 10, "A shimmering, protective shield envelops $n.")->move(this_body());
}