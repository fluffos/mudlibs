#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Zydonia");
  set_spell("diabolic consultation");
  set_art("obsequatur",3);
  set_lore("terra",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(17);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Black witches often use this witchcraft to keep evil and "
	   "grey witches use it to balance their desires better.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for an inner voice." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 31-Oct-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing changes." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()>350) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your good thoughts "
                    "prevent you from finishing this diabolic "
		    "consultation." }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {  // changed to void, Coogan, 31-Oct-00
  if (event[E_AGENT]->query_alignment()>150 && 
      !random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level"))) {
    send_message(({ "Oops! Suddenly ", M_THE, M_ARG, E_AGENT, M_VERB,
		      "turn", " into a big slimy frog." }),event);
    event[E_AGENT]->frog_curse(1);
  }
  send_message(({ M_TARGETS, M_ARG, E_AGENT, "You feel worse aligned." }),
	       event);
  if (event[E_AGENT]->query_alignment()>-800)
    event[E_AGENT]->add_alignment(-66);
  return;
}
