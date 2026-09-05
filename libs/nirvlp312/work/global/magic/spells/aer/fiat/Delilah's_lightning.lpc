#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delilah");
  set_spell("lightning");
  set_art("fiat",2);
  set_lore("aer",2);
  set_art_learn_level(1);
  set_lore_learn_level(1);
  set_cost(11);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("The lightning is an effective spell enabled through the air "
    "you breathe. This spell is mostly used by evil witches.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a cleaning light." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 20-Nov-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but it stays cool." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()>200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your good thoughts "
		    "prevent you from finishing this lightning." }),event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not target more "
                    "than one enemy at the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET]) {
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You only can target livings!" }), event);
      cancel_event();
      return;
    }
    if (interactive(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You shall not target other players!" }), event);
      cancel_event();
      return;
    }
  }
  if (!sizeof(event[E_TARGET]) && !event[E_AGENT]->query_attack()) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "Here is no good target for lightnings." }), event);
    cancel_event();
    return;
  }
  return;
}

void execute_spell(mapping event) {
  object depp;
  int damage;
  if (sizeof(event[E_TARGET])) depp=event[E_TARGET][0];
  else
    if (event[E_AGENT]->query_attack()) depp=event[E_AGENT]->query_attack();
  damage=random(26);
  if (event[E_AGENT]->query_alignment()<-200) 
    damage+=event[E_AGENT]->query_extern_data("Ethakar","WW_Level")*3/2;
  send_message(({ M_THE, M_S, M_ARG, E_AGENT, " hand releases wonderful "
		  "lighting against ",M_THE, M_OBJECT, depp, "." }),event);
  depp->hit_player(damage, event[E_AGENT]);
  return;
}
