#include <std.h>

inherit SPELL;

#define tp this_player()
void create()
{
 ::create();
 set_properties( ([ "req_class"    : ({ "mage" }),
                    "req_subclass" : ({ "conjurer" }),
                    "req_level"    : 30,
                    "set_level"    : 1, // spell level (none)
                    "req_mp"       : 200, // required mp
                    "min_mp"       : 550, // minimum mp taken away
                    "req_skills"   :
               ([   "conjuring"    : 150 ]),
                    "skill_perc"   :
               ([ "conjuring" : 100 ]),
                    "spell_properties" : 
               ({ "sorcery" }),
                    "target properties" :
               ({ "no target" })
               ]));
}

int cmd_tempestcraft()
{
 object ob;

 if (!player_ok(this_player(),0)) return notify_fail(
	"You cannot cast this.\n");
 if (!spell_ok(this_player()))  return notify_fail(
	"What?\n");
 spell_message( ({ "%^BOLD%^CYAN%^Y%^BLUE%^ou summon forth the raw "
			"power of the tempest and craft a mighty "
			"chariot!",
                   "If you <dispell chariot> your mp will be "
			"partially replenished.",
                   "%^BOLD%^%^CYAN%^%s%^BLUE%^ summons forth the raw"
			"power of the tempest and crafts a mighty "
			"chariot!" }),
                                   this_player(), this_player());
 ob = new("/wizards/inferno/cyclone");
 ob->set_owner(tp->query_name());
 ob->move(environment(tp));
 return 1;
}

void help() {
write("
Syntax: <tempestcraft>
This conjuring spell is known to powerful conjurers. It allows the
caster to tap into nature's raw force of the tempest and summon
forth a cyclone chariot. Riding the cyclone chariot can be thought
of as riding a tornado; it will blow foes much weaker than the rider
out of the room and send others sprawling to the ground.
");
}
