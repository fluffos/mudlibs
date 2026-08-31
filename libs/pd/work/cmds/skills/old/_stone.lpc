#include <std.h>

inherit SPELL;

#define tp this_player()
void create()
{
 ::create();
 set_properties( ([ "req_class"    : ({ "mage" }),
                    "req_subclass" : ({ "druid" }),
                    "req_level"    :5,
                    "set_level"    : 5, // spell level
                    "req_mp"       : 20, // required mp
                    "min_mp"       : 30, // minimum mp taken away
                    "req_skills"   :
               ([ "magic attack" : 20,
                  "nature"       : 20 ]),
                    "skill_perc"   :
               ([ "magic attack" : 30,    // MUST ADD UP TO 
                  "nature"       : 70 ]),    // 100% or else damnit
                    "spell_properties" : 
               ({ "no attack" }),
                    "target properties" :
               ({ "living", "start combat" })
               ]));
}

int cmd_stone(string str)
{
 object target;
 if (!player_ok(this_player(), 0)) return 0;
 if ((!str || str == "") &&
     !tp->query_current_attacker()) return notify_fail("Stone what?\n");
 if (!spell_ok(this_player()))  return 0;
 if (!(target = tp->query_current_attacker()))
 if (!target = present(str, environment(this_player())))
   return notify_fail("You do not see that anywhere.\n");
 if (!target_ok(target)) return 0;
 spell_message( ({ "%^YELLOW%^You launch a rock at %s.",
                   "%^YELLOW%s launches a rock at you.",
                   "%^YELLOW%s launches a rock at %s." }),
                                   this_player(),       target );

 setup_spell( tp, target, ({ "stone" }) ); 
 return 1;
}

void help() {
write("
Syntax: <stone [living]>
This druid spell will levitate a stone from the ground and
launch it at the caster's living victim, needless to say
the poor fellow on the recieving end won't be too happy about
that.
");
}
