#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Ardanna");
  set_spell("chain lightning");
  set_art("fiat",4);
  set_lore("aer",4);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(33);
  set_requirements(({"hand"}));
  set_delay(500);
  set_info("The chain lightning is very good spell against all enemies in "
    "your environment. But take care in its usage.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "wave", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " hand around ", M_THE,
		  M_OBJECT, M_ARG, E_AGENT, " for a lightning storm." }),
	       event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but it stays dark." }),
                 event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  int damage, align;
  align=event[E_AGENT]->query_alignment();
  damage=30+random(event[E_AGENT]->query_extern_data("Ethakar","WW_Level")*3);
  damage-=abs(align)/20;
  if (damage<10) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "Your extremely unbalanced "
		      "mind prevents anyone from being harmed by you." }),
		 event);
    return;
  }
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "release", M_ARG, E_AGENT, " a mighty "
		  "chainlightning all around ", M_THE, M_OBJECT, M_ARG,
		  E_AGENT, " harming every enemy." }),event);
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,
                   ({ #'call_other, 'x, "query_npc" }),
                   ({ #'call_other, 'x, "hit_player", damage, event[E_AGENT] })
                })));
  return;
}
