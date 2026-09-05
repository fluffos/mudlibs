#include <event.h>
#include <message.h>

#define CAT "published/domains/deathbat/mag_cat"

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delilah");
  set_spell("catwarrior");
  set_art("mutetur",5);
  set_lore("animal",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(63);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("This mighty chant turns your little cat into a great "
	   "catwarrior, half human and half cat.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
		  M_OBJECT, M_ARG, E_AGENT, " for changing shapes." }),
	       event);
  return 1;

}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but noone shapes." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()>200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
		      "Your good thoughts prevent you to cast this "
		      "spell." }),event);
    cancel_event();
    return;
  }
  if (!present_clone(CAT,environment(event[E_AGENT]))) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, 
		    "But where is your little cat?" }),event);
    cancel_event();
    return;
  }
  if (present_clone(CAT,environment(event[E_AGENT]))->id("warrior")) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, 
		    "This is already a mighty cat warrior!" }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  object cat;
  send_message(({ "Suddenly the cat turns into a cat warrior and grrs "
		  "mysteriously at ", M_THE, M_ARG, E_AGENT, "." }),event);
  cat=present_clone(CAT,environment(event[E_AGENT]));
  cat->set_race("cat warrior");
  cat->set_name("cat warrior");
  cat->set_short("a huge cat warrior");
  cat->set_long("This cat warrior looks like a on two legs standing "
		"tiger with a humanoid look. The fur is black and "
		"yellow striped, the claws are long and sharp and "
		"the head has an aggressive look at everything.\n");
  cat->set_level(16+event[E_AGENT]->query_extern_data("Ethakar","WW_Level"));
  cat->set_int(24);
  cat->set_id(({"\nmagic_cat","cat","catwarrior","cat warrior","warrior"}));
  cat->heal_self(100);
  return;
}
