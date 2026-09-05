// changed all this_player() stuff to event[E_AGENT], Coogan, 09-Jun-99

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
  set_spell("starlight");
  set_art("fiat",5);
  set_lore("mortus",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(43);
  set_requirements(({"head"}));
  set_delay(6000);
  set_info("The starlight releases a concentrated beam of light "
	   "at one of your enemies. Shouldn't be very healthy "
	   "for your foe!\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ", M_THE, M_OBJECT,
                  M_ARG, E_AGENT, " for a flashing light." }), event);
  return 1;
}

// changed {start, execute, finish}_spell to return void, Coogan, 13-Mar-01
void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not flash more "
                    "than one person at the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET]) {
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You only can flash livings!" }), event);
      cancel_event();
      return;
    }
    if (interactive(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You shall not flash other players!" }), event);
      cancel_event();
      return;
    }
  }
  if (!sizeof(event[E_TARGET]) && !event[E_AGENT]->query_attack()) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "Here is no good target for starlights ..." }), event);
    cancel_event();
    return;
  }
  return;
}

void execute_spell(mapping event) {
  object sash,depp;
  int howmuch;
  howmuch = 25+random(25);
#ifdef TUBMUD
  if (sash=present_clone(SASH, event[E_AGENT]))
    howmuch+=sash->query_ak_level()*2;
#endif
  if (environment(event[E_AGENT])->query_property(P_INSIDE))
    howmuch -= 11;
  if (sizeof(event[E_TARGET])) 
    depp=event[E_TARGET][0];
  else
    if (event[E_AGENT]->query_attack())
      depp=event[E_AGENT]->query_attack();
  send_message(({ M_THE, M_S, M_ARG, E_AGENT, " eyes shine in the most white "
                  "light. A sudden flash releases ", M_POSSESSIVE, M_ARG,
                  E_AGENT, " eyes to strike ", M_THE, M_OBJECT, depp,
                  " with a sparkling sound." }), event);
  depp->hit_player(howmuch, event[E_AGENT]);
  return;
}

