#include <event.h>
#include <message.h>
#include <filter.h>

#define PREVENT_CAST "/domains/deathbat/guild/spells/ww_prevent"

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delvira");
  set_spell("shapeshifting");
  set_art("mutetur",5);
  set_lore("animal",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(61);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("A mighty witchcraft. It turns its caster into a great dangerous "
    "monster without the ability to cast spells. Only good minds are "
    "able to control their bodies in this way. Non-white witches often "
    "complain about strange side-effects.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE, 
                  M_OBJECT, M_ARG, E_AGENT, " for shifting shapes." }),
               event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 20-Nov-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but your shape stays." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()<-200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your evil desires "
                    "prevent you from finishing this shift." }),event);
    cancel_event();
    return;
  }
}

mixed do_filter(string func, mixed arg) {
  switch(func) {
  case F_CON: return arg+20;
  case F_DEX: return arg+20;
  case F_STR: return arg+20;
  case F_NAME: return "monster";
  case F_TITLE: return "who is furry, big, and ugly";
  case F_PRETITLE: return "a mighty";
  case F_ID: return ({ "mighty monster","monster","ugly monster",
			 "big monster","furry monster" });
  case F_HIDE_INV: return 1;
  default: return arg;
  }
}

void shapeback(object witch) {
  witch->remove_filter(F_CON);
  witch->remove_filter(F_DEX);
  witch->remove_filter(F_STR);
  witch->remove_filter(F_TITLE);
  witch->remove_filter(F_NAME);
  witch->remove_filter(F_PRETITLE);
  witch->remove_filter(F_ID);
  witch->remove_filter(F_HIDE_INV);
  witch->remove_daemon(PREVENT_CAST);
  send_message(({ M_THE, witch, M_VERB, "turn", witch, " back." }));
}

void execute_spell(mapping event) {
  if (event[E_AGENT]->query_alignment()<200 && 
      !random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level"))) {
    send_message(({ "Oops! Suddenly ", M_THE, M_ARG, E_AGENT, M_VERB,
                    "turn", M_ARG, E_AGENT, " into a big slimy frog." })
		 ,event);
    event[E_AGENT]->frog_curse(1);
    return;
  }
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "turn", M_ARG, E_AGENT,
		  " into a big furry monster." }),event);
  event[E_AGENT]->add_filter(F_CON,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_DEX,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_STR,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_TITLE,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_NAME,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_PRETITLE,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_ID,FPRIO_POLYMORPH);
  event[E_AGENT]->add_filter(F_HIDE_INV,FPRIO_POLYMORPH);
  event[E_AGENT]->add_daemon(PREVENT_CAST,-789);
  call_out("shapeback", 
	   120 + event[E_AGENT]->query_extern_data("Ethakar","WW_Hunting")*2,
	   event[E_AGENT]);
  return;
}

