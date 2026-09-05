#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("titlechange");
  set_art("obsequatur",3);
  set_lore("vis",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(24);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("All witches use this spell to change their titles.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for a change." }),
	       event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing changes." }),
                 event);
    cancel_event();
    return;
  }
}

void enter_title(string title, object ww) {
  ww->set_title(title);
  send_message(({ M_TARGETS, ww, "Title successfully changed!" }));
}
  
void execute_spell(mapping event) {
  string paf;
  send_message(({ M_TARGETS, M_ARG, E_AGENT, "Type title and return!" }),
	       event);
  input_to("enter_title",0,event[E_AGENT]);
  return;
}

