// a dungeonware.net production
// coded by stormbringer for primal darkness
// 20-Oct-00

#include <std.h>
#include <rest.h>

inherit SPELL;
int spell();

#define tp this_player()
void create()
{
 ::create();
 set_properties( ([ "req_class"    : ({ "mage" }),
                    "req_subclass" : ({ "illusionist" }),
                    "req_level"    : 20,
                    "set_level"    : 8, // spell level
                    "req_mp"       : 50, // required mp
                    "min_mp"       : 60, // minimum mp taken away
                    "req_skills"   :
               ([ "magic attack"   : 35,
                  "illusion"       : 95 ]),
                    "skill_perc"   :
               ([ "magic attack" : 25,         // MUST ADD UP TO 
                  "illusion"       : 75 ]),    // 100% or else damnit
                    "spell_properties" : 
               ({ "no attack", "not combat" }),
                    "target properties" :
               ({ "living", "start combat" })
               ]));
}

int cmd_gammon(string str)
{
 object target;
if (!player_ok(this_player(),0)) return 0;
 if ((!str || str == "") &&
    !tp->query_current_attacker()) return notify_fail("Gammon what?\n");
 if (!spell_ok(this_player()))  return 0;
 if (!(target = tp->query_current_attacker()))
 if (!target = present(str, environment(this_player())))
   return notify_fail("You do not see that anywhere.\n");
 if (!target_ok(target)) return 0;
 spell_message( ({ "%^YELLOW%^You begin to decieve %s.",
                   "%^YELLOW%^%s weaves a spell around you!",
                   "%^YELLOW%^%s weaves a spell around %s."}),
                                   this_player(),       target );
 target->set_rest_type( LAY );
 setup_spell( tp, target, ({ "magic" }) ); 
 return 1;
}

void help() {
    message("help", "Syntax: <gammon [target]>\n\n"
      "Illusionists decievs the target into falling down "
      "and causing damage to itself.", this_player());
}

int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "mage") return 0;
   if (o->query_subclass() != "illusionist") return 0;
   if (o->query_level() < 20) return 0;
   return 1;
}
