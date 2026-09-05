#include <event.h>
#include <message.h>
#include <prop/room.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Osric");
  set_spell("astral ladder");
  set_art("pereat",5);
  set_lore("imago",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(31);
  set_requirements(({"head"}));
  set_delay(3000);
  set_info("Osric's astral ladder creates a direct connection between you "
           "and the home of the astral knights.\n");
}

int init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ",
                  M_OBJECT, M_ARG, E_AGENT, " for a way home." }),
               event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  if (environment(event[E_AGENT])->query_property(P_NO_TELEPORT)) {
    send_message(({ "An astral ladder appears for only a short moment. Seems "
      "this surrounding prevents astral ladders from holding position." }));
    return;
  }
  message(({ event,
            ({ M_THE, M_S, M_ARG, E_AGENT, " eyes get black, they reflect the "
               "sky and a transparent ladder appears. You imagine that ",
               M_OBJECTIVE, M_ARG, E_AGENT, M_VERB, "climb", M_ARG, E_AGENT,
               " this ladder up and ",M_VERB, "disappear", M_ARG, E_AGENT,
               " with the astral ladder again." }),1,
            ({ M_TARGETS, M_ARG, E_AGENT,
               "You find yourself on the platform of the astral knight tower. "
               "You still don't know, what was real and what imagination." })
  }));
  event[E_AGENT]->move_living(0,"players/ethakar/knights/platform");
  return;
}

