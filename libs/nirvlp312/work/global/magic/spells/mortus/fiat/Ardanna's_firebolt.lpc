#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("firebolt");
  set_art("fiat",1);
  set_lore("mortus",1);
  set_art_learn_level(1);
  set_lore_learn_level(1);
  set_cost(6);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("The firebolt is the smallest spell from the firedamage group. "
    "It provides witches and warlocks with an effective offense against "
    "lesser creatures.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a small bolt of fire." }),
	       event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but it stays cool." }),
                 event);
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
                    "Here is no good target for firebolts." }), event);
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
  damage=random(18);
  if (event[E_AGENT]->query_alignment()<200 && 
      event[E_AGENT]->query_alignment()>-200) 
    damage+=event[E_AGENT]->query_extern_data("Ethakar","WW_Level");
  send_message(({ M_THE, M_S, M_ARG, E_AGENT, " hand releases a firebolt "
		  "against ",M_THE, M_OBJECT, depp, "." }),event);
  depp->hit_player(damage, event[E_AGENT]);
  return;
}
