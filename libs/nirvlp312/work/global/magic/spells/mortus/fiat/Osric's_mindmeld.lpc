// changed all this_player() stuff to event[E_AGENT], Coogan, 09-Jun-99

#include <event.h>
#include <message.h>

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Osric");
  set_spell("mindmeld");
  set_art("fiat",2);
  set_lore("mortus",2);
  set_art_learn_level(1);
  set_lore_learn_level(1);
  set_cost(13);
  set_requirements(({"head"}));
  set_delay(3000);
  set_info("Osric's mindmeld will give you information about the given "
	   "target in relation to yourself.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ",
                  M_OBJECT, M_ARG, E_AGENT, " for a clearing thought." }),
               event);
  return 1;
}

// changed {start, execute, finish}_spell() to return void, Coogan, 13-Mar-01
void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
  if (!sizeof(event[E_TARGET])) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "Na, you have to give a target!" }),
                 event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET])>1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not mindmeld with "
                    "more than one living in the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET][0] == event[E_AGENT]) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "You can not mindmeld with yourself." }), event);
    cancel_event();
    return;
  }
  if (!living(event[E_TARGET][0])) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "You only can mindmeld with livings!" }), event);
    cancel_event();
    return;
  }
  return;
}

void execute_spell(mapping event) {
  object depp,ak;
  depp=event[E_TARGET][0];
  ak = event[E_AGENT];
  message(({ event,
            ({ M_THE, M_ARG, E_AGENT, M_VERB, "mindmeld", M_ARG, E_AGENT,
               " with ", M_THE, M_OBJECT, depp, "." }),
            M_PRE, ({ M_TARGETS, M_ARG, E_AGENT }),
            ({ "You feel ", (ak->query_str() > depp->query_str() ? 
               "stronger" : "weaker"), " than ", M_THE, M_OBJECT, depp, "." }),
            ({ "You feel ", (ak->query_int() > depp->query_int() ? 
               "wiser" : "dumber"), " than ", M_THE, M_OBJECT, depp, "." }),
            ({ "You feel ", (ak->query_exp() > depp->query_exp() ? 
               "more" : "less")," experienced than ",M_THE,M_OBJECT,depp,"." }),
            ({ "You feel ", (ak->query_ac() > depp->query_ac() ? 
               "better" : "worse")," armoured than ",M_THE,M_OBJECT,depp,"." }),
            ({ "You feel ", (ak->query_wc() > depp->query_wc() ? 
               "better" : "worse"), " armed than ", M_THE, M_OBJECT,depp,"." }),
            ({ "Hui, what a interesting experience it is to "
               "mindmeld with other livings!" })}));
  return;
}

