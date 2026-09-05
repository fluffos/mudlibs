// changed all this_player() related stuff to event[E_AGENT], Coogan, 09-Jun-99

#include <event.h>
#include <message.h>
#include <prop/room.h>

#ifdef TUBMUD
#define SASH "players/ethakar/knights/sash"
#endif

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Osric");
  set_spell("confusion");
  set_art("fiat",3);
  set_lore("imago",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(17);
  set_requirements(({"head"}));
  set_delay(4000);
  set_info("The confusion spell can have a very strange effect on "
	   "your opponents. Better you test them out.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ", M_PRONOUN,
                  M_OBJECT, M_ARG, E_AGENT, " for a confusing thought." }),
               event);
  return 1;
}

// changed {start, execute, finish}_spell() to return void, Coogan, 13-Mar-01
void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not confuse more "
                    "than one person at the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET]) {
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You only can confuse livings!" }), event);
      cancel_event();
      return;
    }
    if (interactive(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You shall not confuse other players!" }), event);
      cancel_event();
      return;
    }
  }
  if (!sizeof(event[E_TARGET]) && !event[E_AGENT]->query_attack()) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Noone here to confuse ... " }),
                 event);
    cancel_event();
    return;
  }
  return;
}

void execute_spell(mapping event) {
  object sash,depp;
  int howmuch;
  howmuch = 10+random(10);
#ifdef TUBMUD
  if (sash = present_clone(SASH, event[E_AGENT]))
    howmuch += sash->query_ak_level()*2;
#endif
  if (environment(event[E_AGENT])->query_property(P_INSIDE))
    howmuch -= 5;
  if (sizeof(event[E_TARGET])) 
    depp=event[E_TARGET][0];
  else
    if (event[E_AGENT]->query_attack())
      depp=event[E_AGENT]->query_attack();
  message(({ event,
            ({ M_THE, M_S, M_ARG, E_AGENT, " eyes get dark like the sky "
               "at night. As the darkness hits ", M_THE, M_OBJECT, depp, ", ",
               M_POSSESSIVE, M_ARG, E_AGENT, " eyes get their normal "
               "colour back." }),
            ({ M_THE, depp, M_VERB, "get", depp, " so confused that ",
               M_PRONOUN, depp, M_VERB, "are", depp, " hitting ",
               M_OBJECTIVE, depp, " for a moment." })}));
  depp->hit_player(howmuch, event[E_AGENT]);
  return;
}

