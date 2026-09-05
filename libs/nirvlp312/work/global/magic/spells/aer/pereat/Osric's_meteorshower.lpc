// changed all this_player() related stuff to event[E_AGENT], Coogan, 09-Jun-99

#include <event.h>
#include <message.h>
#include <prop/room.h>
#include <closures.h>  // Coogan, 09-Jun-99

#ifdef TUBMUD  // Coogan, 09-Jun-99
#define SASH "players/ethakar/knights/sash"
#endif

inherit "complex/spell";

void
create() {
  spell::create();
  set_author("Osric");
  set_spell("meteorshower");
  set_art("pereat",3);
  set_lore("aer",3);
  set_art_learn_level(2);
  set_lore_learn_level(2);
  set_cost(26);
  set_requirements(({"head"}));
  set_delay(8000);
  set_info("The rain of meteors will harm every living in your environment. "
           "You should be very careful when casting this spell since your "
           "friends and even you will suffer damage by these tiny meteors.\n");
}

status init_spell(mapping event) {
  send_message(({ M_THE, M_ARG, E_AGENT, M_VERB, "focus", M_ARG, E_AGENT,
                  M_POSSESSIVE, M_ARG, E_AGENT, " mind on ", M_THE,
                  M_OBJECTIVE, M_ARG, E_AGENT, " for a stony shower." }),
               event);
  return 1;
}

void start_spell(mapping event) {
  if (event[E_SUCCESS]<0) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "... but no shower comes down." }), event);
    cancel_event();
    return;
  }
  if (!environment(event[E_AGENT])->query_property(P_OUTSIDE)) {
    send_message(({ M_TARGETS, M_ARG, E_AGENT,
                    "... but meteors only fall down outside." }), event);
    cancel_event();
    return;
  }
}

void execute_spell(mapping event) {
  int howmany;
  object sash;
  howmany = 5 + random(10);
#ifdef TUBMUD  // Coogan, 09-Jun-99
  if (sash = present_clone(SASH, event[E_AGENT]))
    howmany += sash->query_ak_level();  // changed from SASH to sash, Coogan
#endif
  if (environment(event[E_AGENT])->query_property(P_UNDER_WATER))
    howmany -= 5;
  send_message(({ "Suddenly you hear a loud noise in the air as ",
                  howmany, " dozens of tiny meteors fall down on everything "
                  "around you." }));
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,  // && -> ?, Coogan, 09-Jun-99
                   ({ #'living, 'x }),
                   ({ #'call_other, 'x, "reduce_hit_point", howmany })
                })));
  filter(all_inventory(environment(event[E_AGENT])),
         lambda(({ 'x }),
                ({ #'?,  // && -> ?, Coogan, 09-Jun-99
                   ({ #'call_other, 'x, "query_npc" }),
                   ({ #'call_other, 'x, "set_attack",
                      ({ CL_L_INDEX, event, E_AGENT })
                   })
                })));
  return;
}

