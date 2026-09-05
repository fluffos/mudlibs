#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("invisibility");
  set_art("mutetur",5);
  set_lore("vis",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(49);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("You can make yourself invisible. But you also have heard "
	   "about non-grey witches complaining about strange side-effects.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for matters of sight." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 31-Oct-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but sight remains." }),
                 event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {  // changed to void, Coogan, 31-Oct-00
  if ((event[E_AGENT]->query_alignment()<-200 ||
      event[E_AGENT]->query_alignment()>200) && 
      !random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level"))) {
    send_message(({ "Oops! Suddenly ", M_THE, M_ARG, E_AGENT, M_VERB,
		      "turn", " into a big slimy frog." }),event);
    event[E_AGENT]->frog_curse(1);
  }
  event[E_AGENT]->invis(20 + event[E_AGENT]->
			query_extern_data("Ethakar","WW_Charging"));
  return;
}
