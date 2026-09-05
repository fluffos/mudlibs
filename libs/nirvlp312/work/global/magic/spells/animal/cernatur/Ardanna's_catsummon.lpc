#include <event.h>
#include <message.h>

#define CAT "published/domains/deathbat/mag_cat"

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("catsummon");
  set_art("cernatur",1);
  set_lore("animal",1);
  set_art_learn_level(1);
  set_lore_learn_level(1);
  set_cost(42);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Witches and warlocks are known for their eternal fourlegged friends "
	   "called cats. This spell enables every witchcraft member to summon "
	   "or to call one of these sweet little helpers.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for a helping hand." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // made it void, Coogan, 21-May-01
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but noone meows." }),
                 event);
    cancel_event();
    return;
  }
  if (present("\nmagic_cat",environment(event[E_AGENT]))) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, 
		    "How many cats do you want to collect here?" }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {  // made it void, Coogan, 21-May-01
  object cat;
  send_message(({ "Suddenly a cat steps out of nowhere and purrs "
		  "contentedly at ", M_THE, M_ARG, E_AGENT, "." }),event);
  cat=clone_object(CAT);
  cat->set_level(6+event[E_AGENT]->query_extern_data("Ethakar","WW_Level"));
  cat->move_living(0,environment(event[E_AGENT]));
  cat->set_guarded(event[E_AGENT]);
  return;
}

