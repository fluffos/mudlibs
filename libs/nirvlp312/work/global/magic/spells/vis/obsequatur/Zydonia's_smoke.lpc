#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Zydonia");
  set_spell("smoke");
  set_art("obsequatur",3);
  set_lore("vis",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(23);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("You can detect invisible livings. But you also have heard about "
	   "non-black witches complaining about strange side-effects.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for matters of sight." }),
	       event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but smoke abstains." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()>200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your good thoughts "
                    "prevent you from finishing this smoke." }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  if (event[E_AGENT]->query_alignment()>-200 && 
      !random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level"))) {
    send_message(({ "Oops! Suddenly ", M_THE, M_ARG, E_AGENT, M_VERB,
		      "turn", " into a big slimy frog." }),event);
    event[E_AGENT]->frog_curse(1);
  }
  send_message(({ "Smoke is turning all invisible livings visible now." }));
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,
                   ({ #'living, 'x }),
                   ({ #'call_other, 'x, "vis" })
                })));  
  return;
}
