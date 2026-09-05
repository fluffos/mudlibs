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
  set_spell("healing");
  set_art("pereat",3);
  set_lore("corpus",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(42);
  set_requirements(({"head"}));
  set_delay(6000);
  set_info("Osric's healing is good to cure yourself or someone near you "
           "at a high rate. But since this spell is robbing a lot of "
           "its casters magical balance for a while, it can rarely "
           "help you often in the same battle.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ", M_THE, M_OBJECT,
                  M_ARG, E_AGENT, " for a cleansing wind." }), event);
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
    send_message(({ M_TARGETS, M_ARG, E_AGENT, "You can not heal more than "
                    "one person in the same moment." }), event);
    cancel_event();
    return;
  }
  if (event[E_TARGET])
    if (!living(event[E_TARGET][0])) {
      send_message(({ M_TARGETS, M_ARG, E_AGENT,"You only can heal livings!" }),
                      event);
      cancel_event();
      return;
    }
  return;
}

void execute_spell(mapping event) {
  object sash;
  int howmuch;
  string guiding_star;
  howmuch = 60;
#ifdef TUBMUD  // Coogan, 09-Jun-99
  if (sash=present_clone(SASH, event[E_AGENT])) {
    howmuch += sash->query_ak_level()*3;
    if (sash->query_star()!="Unknown")
      guiding_star = sash->query_star();
  }
#endif
  if (environment(event[E_AGENT])->query_property(P_INSIDE))
    howmuch -= 10;
  if (sizeof(event[E_TARGET]))
    if (event[E_TARGET][0] != event[E_AGENT]) {
      message(({ event,
                ({ "A healing beam streams out of ", M_THE, M_S, M_ARG,
                   E_AGENT, " eyes at ", M_THE, M_OBJECT,
                   event[E_TARGET][0], "." }),
                ({ M_TARGETS, event[E_TARGET][0], 
                   (guiding_star ? guiding_star + " increases your health." : 
                   "You feel much better.") })}));
      event[E_TARGET][0]->reduce_hit_point(-howmuch);
      return;
    }
  message(({ event,
            ({ M_THE, M_S, M_ARG, E_AGENT, " eyes gleam with the light of "
               "a star. In a second the light seems to vanish into ",
               M_POSSESSIVE, M_ARG, E_AGENT, " whole body and the eyes get "
               "their normal colour back." }),
            ({ M_TARGETS, M_ARG, E_AGENT, "You feel much better",
       	       (guiding_star ? " by " + guiding_star : ""), "." })}));
  event[E_AGENT]->reduce_hit_point(-howmuch);
  return;
}

