/*  File upgrade by Grimbrand 2-11-96                                   */

#include "unarmed_combat.h"
inherit "/obj/monster";

int att_count;

void setup() {
   object ob;

   set_name("mind flayer");
   add_alias("flayer");
   set_short("Mind Flayer");
   set_long("   It has been said that this creature lives and feeds off "
            "the minds of other inteligent beings.  This one has seen "
            "better days.  One of its large dark eyes has been put out "
            "allowing a dark puss to leak out.  Two of its four tentacles "
            "around its mouth area also missing.  It obviously tried to "
            "attack a Duergar, and was taught a lesson."
            "\n\n");
   set_race("mind flayer");
   set_level(8);
   set_random_stats(10,18);
   set_al(200);
   set_max_hp(34);
   adjust_money(5,"gold");
   set_kill_xp(431);

}

mapping valid_attack() {
  return([
        "punch" : ({ AN+" whips "+DN+" with a tentacle.\n",
                     "You whip "+DN+" with a tentacle.",
                     AN+" whips you with a tentacle.\n" }),
        "kick"  : ({ AN+" slaps "+DN+" with a withery hand.\n",
                     "You slap "+DN+" with a withery hand.",
                     AN+" slaps you with a withery hand.\n"   }),
        "knee"  : ({ AN+" rakes "+DN+" with its long claws.\n",
                     "You rake "+DN+" with your claws everywhere.",
                     AN+" rakes you with its claws.\n" }),
        "headbutt" : ({ AN+" glances at "+DN+", who winces as if hit.\n",
                        "You mind whip "+DN+".",
                        AN+" glances at you, lashing you with its mind.\n" })
        ]);
}
