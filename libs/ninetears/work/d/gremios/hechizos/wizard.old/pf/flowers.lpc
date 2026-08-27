#include "wizard.h"
inherit BASIC;

/*
 * This spell creates a nice bunch of flowers.
 */

void setup() {
  set_power_level(10);
  set_name("flower");
  set_ritual(({
   ({
      ({
        "You stare intently into space opening a rift into the flower "
            "dimension.\n",
        "$tp_name$ stares intently into space.\n",
      }),
      ({
        "You carefully care open a rift into the flower dimension by stareing "
            "hard into space.\n",
        "$tp_name$ stare intently into space.\n",
      }),
    }),
    ({
      ({
         "You conjour up the immage of the flower you want in your mind "
             "and sketch it out in the space in front of you.\n",
         "$tp_name$ makes some hour glass motions with his hands.\n",
      }),
    }),
    ({
      ({
        "You wave your arms around wildly attracting the attension of the "
           "bunch of flowers you wish to bring back.\n",
        "$tp_name$ waves $tp_poss$ arms around wildly.\n",
      }),
    }),
  }));
  set_failure(10);
  set_skill_threshold(50);
  set_fixed_time(1);
  set_teach_lvl(10);
  set_learn_lvl(4);
  set_skill_used("magic.spells.misc.self");
  set_info(
"Makes a nice bunch of flowers.  How cute.\n");
  set_consumables(({ }));
  set_needed(({ }));
  set_spell_type("silly");
  set_point_cost(10);
  set_duration(1); /* Please note this is the duration in the player's
                    * spell effects array */
  set_directed(0);
  set_multiple(0);
  set_casting_time(90);
} /* setup() */

/* Returns the xp gained from casting the spell. */
int effect_heart_beat() {
  object flowers;

  flowers = clone_object("/std/object");
  flowers->set_name("flowers");
  flowers->set_short("bunch of flowers");
  flowers->set_main_plural("bunches of flowers");
  flowers->add_adjective(({ "bunch", "bunches", "of" }));
  flowers->add_plural("bunches");
  flowers->set_long(
"A nice bunch of flowers.\n");
  flowers->set_weight(30);
  if (flowers->move(this_player()))
    flowers->move(environment(this_player()));
  tell_room(environment(this_player()),
"In a last burst of energy "+this_player()->query_cap_name()+" reaches into "
"space and pulls out a bunch of flowers.\n", this_player());
  write("You reach out your hand into the flower dimension and drag a "
        "bunch of flowers screaming into this world.\n");
  return 100;
} /* effect_heart_beat() */
 
void do_spell_failure() {
  write("We failed...\n");
} /* do_spell_failure() */
