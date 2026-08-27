#include "path.h"
#include "wizard.h"
inherit BASIC;

/*
 * This spell creates a nice bunch of flowers.
 */

void setup() {
  set_power_level(3);
  set_name("finger");
  set_ritual(({
   ({
      ({
        "You sit deep in thought.\n",
        "$tp_name$ sits deep in thought.\n",
      }),
    }),
    ({
      ({
        "You suddently spring up and yell something incomprehensible.\n",
        "$tp_name$ suddenly springs up and yells something incomprehensible.\n",
      }),
    }),
    ({
      ({
        "You waggle your arms around wildly.\n",
        "$tp_name$ waggles his arms around wildly.\n",
      }),
    }),
    ({
      ({
        "You point excitedly off into the distance.\n",
        "$tp_name$ points excitedly off into the distance.\n",
      }),
    }),
  }));
  set_failure(10);
  set_skill_threshold(10);
  set_fixed_time(1);
  set_teach_lvl(4);
  set_learn_lvl(1);
  set_skill_used("magic.spells.misc.target");
  set_info(
"Allows you to send a message to players on other muds.  "
"Useful huh?\n");
  set_consumables(({ }));
  set_needed(({ }));
  set_spell_type("silly");
  set_point_cost(10);
  set_duration(1); /* Please note this is the duration in the player's
                    * spell effects array */
  set_directed(0);
  set_multiple(0);
  set_casting_time(200);
} /* setup() */

/* Returns the xp gained from casting the spell. */
int effect_heart_beat() {
  object demon;

  demon = clone_object(CHAR+"tell_demon");
  demon->set_caster(this_player());
  tell_room(environment(this_player()),
"A demon wanders casualy into the room.\n");
  demon->move(environment(this_player()));
  demon->init_command("whisper "+this_player()->query_name()+
                      " Use the command 'send' to send a message to the "
                      "other person.  ie 'send pinkfish@discworld'");
  return 10;
} /* effect_heart_beat() */
 
void do_spell_failure() {
  write("We failed...\n");
} /* do_spell_failure() */
