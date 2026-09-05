#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("balance");
  set_art("cernatur",1);
  set_lore("vis",1);
  set_art_learn_level(1);
  set_lore_learn_level(1);
  set_cost(7);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Grey witches use this spell to check their balanced minds.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for an inner voice." }),
	       event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but noone is checked." }),
                 event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  int al;
  al=event[E_AGENT]->query_alignment();
  if ((event[E_AGENT]->query_alignment()<-250 ||
       event[E_AGENT]->query_alignment()>250) && 
      !random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level"))) {
    send_message(({ "Oops! Suddenly ", M_THE, M_ARG, E_AGENT, M_VERB,
		    "turn", " into a big slimy frog." }),event);
    event[E_AGENT]->frog_curse(1);
  }
  switch(abs(al)) {
  case 0 .. 9 :
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You feel superb balanced!" }),
		 event);
    return;
  case 10 .. 40 :
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You feel well balanced!" }),
		 event);
    return;
  case 41 .. 99 :
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You feel average balanced!" }),
		 event);
    return;
  case 100 .. 199 :
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You feel miserable balanced!" }),
		 event);
    return;
  default:
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You are out of balance!" }),
		 event);
    return;
  }
}
