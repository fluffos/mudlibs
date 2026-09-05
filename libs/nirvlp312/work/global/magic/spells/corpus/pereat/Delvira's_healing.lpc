#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delvira");
  set_spell("healing");
  set_art("pereat",3);
  set_lore("corpus",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(19);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Good witches use this spell to heal livings in need and very "
    "good witches use it to heal themselves.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a healing purpose." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // made it void, Coogan, 21-May-01
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not heal more than "
                    "one person in the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET])
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,"You only can heal livings!" }),
                      event);
      cancel_event();
      return;
    }
  return;
}

void execute_spell(mapping event) {  // made it void, Coogan, 21-May-01
  int howmuch;
  howmuch=33;
  if (event[E_AGENT]->query_alignment()>200)
    howmuch+=event[E_AGENT]->query_extern_data("Ethakar","WW_Level");
  if (sizeof(event[E_TARGET]))
    if (event[E_TARGET][0] != event[E_AGENT]) {
      message(({ event,
                ({ "A healing salve streams out of ", M_THE, M_S, M_ARG,
                   E_AGENT, " hands at ", M_THE, M_OBJECT,
                   event[E_TARGET][0], "." }),
                ({ M_TARGETS, event[E_TARGET][0], 
                   "You feel much better." })}));
      event[E_TARGET][0]->reduce_hit_point(-howmuch);
      return;
    }
  message(({ event,
            ({ M_THE, M_S, M_ARG, E_AGENT, " hand glows softly and emits "
               "a healing aura around ",
               M_POSSESSIVE, M_ARG, E_AGENT, " whole body." }),
            ({ M_TARGETS, M_ARG, E_AGENT, "You feel much better." })}));
  event[E_AGENT]->reduce_hit_point(-howmuch);
  return;
}

