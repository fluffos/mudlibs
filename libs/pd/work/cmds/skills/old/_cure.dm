#include <std.h>

inherit SPELL;

#define tp this_player()
void create()
{
 ::create();
 set_properties( ([ "req_class"    : ({ "clergy" }),
                    "req_subclass" : ({ "cleric" }),
                    "req_level"    : 10,
                    "set_level"    : 10, // spell level
                    "req_mp"       : 20, // required mp
                    "min_mp"       : 30, // minimum mp taken away
                    "req_skills"   :
               ([   "healing"    : 20 ]),
                    "skill_perc"   :
               ([ "healing" : 100 ]),
                    "spell_properties" : 
               ({ "heal" }),
                    "target properties" :
               ({ "living" })
               ]));
}

int cmd_cure(string str)
{
 object target;

if (!player_ok(this_player(),0)) return 0;
 if (!spell_ok(this_player()))  return 0;
 if (!str || str == "") return notify_fail("Cast cure  on whom?\n");
 if (!target = present(str, environment(this_player())))
   return notify_fail("You dont see that anywhere.\n");
 if (!target_ok(target)) return 0;
 spell_message( ({ "%^BOLD%^%^YELLOW%^You mutter a few words and heal %s.",
                   "%^BOLD%^%^YELLOW%^%s mutters a few words and heals you.",
                   "%^BOLD%^%^YELLOW%^%s mutters a few words and heals %s." }),
                                   this_player(),       target );

 setup_spell( tp, target, ({ "heal" }) ); 
 return 1;
}

