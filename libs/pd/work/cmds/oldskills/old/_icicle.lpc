#include <std.h>

inherit SPELL;

#define tp this_player()
void create()
{
 ::create();
 set_properties( ([ "req_class"    : ({ "mage" }),
                    "req_subclass" : ({ "druid" }),
                    "req_level"    : 60,
                    "set_level"    : 60, // spell level
                    "req_mp"       : 50, // required mp
                    "min_mp"       : 70, // minimum mp taken away
                    "req_skills"   :
               ([ "magic attack" : 200,
                  "nature"       : 200,
                  "conjuring"    : 150 ]),
                    "skill_perc"   :
               ([ "magic attack" : 10,    // MUST ADD UP TO 
                  "nature"       : 40,    // 100% or else damnit
                  "conjuring"    : 50 ]),
                    "spell_properties" : 
               ({ "no attack" }),
                    "target properties" :
               ({ "living", "start combat" })
               ]));
}

int cmd_icicle(string str)
{
 object target;
 if (!player_ok(this_player(), 0)) return 0;
 if ((!str || str == "") &&
     !tp->query_current_attacker()) return notify_fail("Icicle what?\n");
 if (!spell_ok(this_player()))  return 0;
 if (!(target = tp->query_current_attacker()))
 if (!target = present(str, environment(this_player())))
   return notify_fail("You do not see that anywhere.\n");
 if (!target_ok(target)) return 0;
 spell_message( ({ "%^BOLD%^%^BLUE%^You shoot a gigantic icicle at %s.",
                   "%^BOLD%^%^BLUE%^%s shoots a gigantic icicle at you.",
                   "%^BOLD%^%^BLUE%^%s shoots a gigantic icicle at %s." }),
                                   this_player(),       target );

 setup_spell( tp, target, ({ "ice" }) ); 
 return 1;
}

