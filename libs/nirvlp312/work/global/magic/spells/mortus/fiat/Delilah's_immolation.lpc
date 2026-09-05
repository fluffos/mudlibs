#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Delilah");
  set_spell("immolation");
  set_art("fiat",5);
  set_lore("mortus",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(39);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("The immolation is one of the largest firedamage spells. It will "
    "hurt everyone in your environment if successfully casted.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a flaming circle." }),
	       event);
  return 1;
}

void start_spell(mapping event) {  // changed to void, Coogan, 20-Nov-00
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but it stays cool." }),
                 event);
    cancel_event();
    return;
  }
  if (event[E_AGENT]->query_alignment()>200) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your friendly thoughts "
		    "prevent you from finishing this immolation." }),event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  int damage, align;
  align=abs(-1000-event[E_AGENT]->query_alignment());
  damage=40+random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level")*8);
  damage-=align/25;
  if (damage<10) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your not so evil desires "
		      "prevent anyone from being hurt by you." }),
		 event);
    return;
  }
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "release", " a very hot "
		  "flame wave all around ", M_THE, M_OBJECT, M_ARG,
		  E_AGENT, " harming every foe." }),event);
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,
                   ({ #'call_other, 'x, "query_npc" }),
                   ({ #'call_other, 'x, "hit_player", damage, event[E_AGENT] })
                })));
  return;
}


