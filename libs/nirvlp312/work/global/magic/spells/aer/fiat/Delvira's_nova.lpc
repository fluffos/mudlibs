#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delvira");
  set_spell("nova");
  set_art("fiat",5);
  set_lore("aer",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(53);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("Nova is the most powerful lightning damage spell. It cleans "
    "your way from your enemies.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a lightning star." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 20-Nov-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but it stays dark." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()<-200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your ugly thoughts "
		    "prevent you from finishing this nova." }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  int damage, align;
  align=abs(1000-event[E_AGENT]->query_alignment());
  damage=50+random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level")*10);
  damage-=align/25;
  if (damage<10) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your not so saintly desires "
		      "prevent anyone from being chased by you." }),
		 event);
    return;
  }
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "release", M_ARG, E_AGENT,
                  " a shining nova all around ", M_THE, M_OBJECT, M_ARG,
		  E_AGENT, " hurting every enemy." }),event);
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,
                   ({ #'call_other, 'x, "query_npc" }),
                   ({ #'call_other, 'x, "hit_player", damage, event[E_AGENT] })
                })));
  return;
}

