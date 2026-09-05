#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delvira");
  set_spell("holy bolt");
  set_art("cernatur",3);
  set_lore("vis",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(24);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Good witches use this spell to clean their way from unholy "
    "crap. Dark desires quickly vanish where a holy bolt strikes in.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a holy strike." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // made it void, Coogan, 21-May-01
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing strikes." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()<-200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your ugly thoughts "
		    "prevent you from finishing this strike." }),event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not strike more "
                    "than one enemy at the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET]) {
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You only can strike livings!" }), event);
      cancel_event();
      return;
    }
    if (interactive(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You shall not strike other players!" }), event);
      cancel_event();
      return;
    }
  }
  if (!sizeof(event[E_TARGET]) && !event[E_AGENT]->query_attack()) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "Here is no good target for holy bolts." }), event);
    cancel_event();
    return;
  }
  return;
}

void execute_spell(mapping event) {  // made it void, Coogan, 21-May-01
  object depp;
  int damage;
  if (sizeof(event[E_TARGET])) depp=event[E_TARGET][0];
  else
    if (event[E_AGENT]->query_attack()) depp=event[E_AGENT]->query_attack();
  damage=(event[E_AGENT]->query_alignment() - depp->query_alignment())/24;
  if (damage<5) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Somehow your holy bolt does "
		      "not want to succeed." }),event);
    return;
  }
  send_message(({ M_THE, M_S, M_ARG, E_AGENT, " hands gleam in a holy light "
		  "releasing their power against ",M_THE, M_OBJECT, depp,
		  "." }),event);
  depp->hit_player(damage, event[E_AGENT]);
  return;
}

