#include <std.h>

inherit OBJECT;
inherit SPELL;

#define tp this_player()
void create()
{
 spell::create();
 object::create();

 set_name("icicle");
 set_short("A small icicle");
 set_long("An iclce");
 set_id( ({ "icicle" }) );
 set_mass(1);
 set_value(1);

 set_properties( ([ "req_class"    : ({ "mage" }),
                    "req_subclass" : ({ "druid" }),
                    "req_level"    : 70,
                    "req_mp"       : 50, // required mp
                    "min_mp"       : 70, // minimum mp taken away
                    "req_skills"   :
               ([ "magic attack" : 200,
                  "nature"       : 200,
                  "conjuring"    : 150 ]),
                    "spell_properties" : 
               ({ "no attack" }),
                    "target properties" :
               ({ "living", "start combat" })
               ]));
 
}

int init()
{
 ::init();
 add_action("cmd_icicle", "icicle");
}
int cmd_icicle(string str)
{
 object target;
 int damage;
 if (!player_ok(this_player())) return 0;
 if ((!str || str == "") &&
     !tp->query_current_attacker()) return notify_fail("Icicle what?\n");
 if (!spell_ok(this_player()))  return 0;
 if (!(target = tp->query_current_attacker()))
 if (!target = present(str, environment(this_player())))
   return notify_fail("You do not see that anywhere.\n");
 if (!target_ok(target)) return 0;
 spell_message( ({ "%%^BOLD%%^%%^BLUE%%^You shoot a gigantic icicle at %s.",
                   "%%^BOLD%%^%%^BLUE%%^%s shoots a gigantic icicle at you.",
                   "%%^BOLD%%^%%^BLUE%%^%s shoots a gigantic icicle at %s." }),
                                   this_player(),       target );

 damage = (tp->query_stats("intelligence") * 3)      +
          (tp->query_stats("wisdom") * 3 )           - 
          (target->query_stats("wisdom") * 2)        -
          (target->query_stats("intelligence") * 2)  +
          (tp->query_skill("magic attack") / 2)      +
          (tp->query_skill("nature") / 3)            +
          (tp->query_skill("conjuring") / 4)         +
          (random(200));
           
          
 setup_spell( tp, target, damage, ({ "ice" }), damage/5 ); 
 return 1;
}

