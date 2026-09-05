// changed all this_player() stuff to event[E_AGENT], Coogan, 09-Jun-99

#include <event.h>
#include <message.h>
#include <prop/room.h>

#ifdef TUBMUD
#define SASH "players/ethakar/knights/sash"
#endif

inherit "complex/spell";

void create() {
  spell::create();
  set_author("Osric");
  set_spell("refresh");
  set_art("pereat",5);
  set_lore("mortus",5);
  set_art_learn_level(3);
  set_lore_learn_level(3);
  set_cost(5);
  set_requirements(({"head"}));
  set_delay(10000);
  set_info("Osric's refresh is good to restore lost magical abilities. "
	   "But the time it takes forces you to be patient.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ", M_THE, M_OBJECTIVE,
                  M_ARG, E_AGENT, " for a refreshing wind." }), event);
  return 1;
}

// changed {start, execute, finish}_spell to return void, Coogan, 13-Mar-01
void start_spell(mapping event) {
  if (event[E_SUCCESS] < 0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "... but nothing happens." }),
                 event);
    cancel_event();
    return;
  }
  if (sizeof(event[E_TARGET]) > 1) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not refresh more "
                    "than one person in the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET])
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,
                      "You only can refresh livings!" }), event);
      cancel_event();
      return;
    }
  return;
}

void execute_spell(mapping event) {
  object sash;
  int howmuch;
  string guiding_star;
  howmuch=25;
#ifdef TUBMUD
  if (sash=present_clone(SASH, event[E_AGENT])) {
    howmuch+=sash->query_ak_level()*2;
    if (sash->query_star()!="Unknown")
      guiding_star=sash->query_star();
  }
#endif
  if (environment(event[E_AGENT])->query_property(P_INSIDE))
    howmuch -= 7;
  if (sizeof(event[E_TARGET]))
    if (event[E_TARGET][0] != event[E_AGENT]) {
      message(({ event,
                ({ "A refreshing beam streams out of ", M_THE, M_S, M_ARG,
                   E_AGENT, " eyes at ", M_THE, M_OBJECT, event[E_TARGET][0],
                   "." }),
                ({ M_TARGETS, event[E_TARGET][0], 
                   (guiding_star ? guiding_star + " increases your magic." : 
                   "You feel somewhat restored.") })}));
      event[E_TARGET][0]->restore_spell_points(howmuch);
      return;
    }
  message(({ event,
            ({ M_THE, M_S, M_ARG, E_AGENT, " eyes gleam in a soft green "
               "light. As the light vanishes, ", M_POSSESSIVE, M_ARG, E_AGENT,
               " head turns green for a moment." }),
            ({ M_TARGETS, M_ARG, E_AGENT, "You feel refreshed",
               (guiding_star ? " by " + guiding_star : ""), "." })}));
  event[E_AGENT]->restore_spell_points(howmuch);
  return;
}

