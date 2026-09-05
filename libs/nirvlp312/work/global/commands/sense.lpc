/*
 * global/commands/consume, written by Coogan@Tubmud, 01-Feb-98
 * it has been renamed to global/commands/sense somewhen before 98-Sep-30  Alfe
 */

#pragma strong_types

#include <grammar.h>
#include <message.h>
#include <event.h>
#include <prop/item.h>
#include <skilltree.h>

#define HANDLE_PRIO    1

inherit "basic/create";

void lick(mapping e) {
  mixed h;
  h = e[E_TARGET]->query_taste(e[E_TARGET, 1]);
  if (h && h[<1] == '\n')
    h = h[0..<2];
  message(({ e,
    ({ M_PL_THE, M_PL_VERB, "lick", M_THE }) +
    (e[E_TARGET] != environment(e[E_AGENT])
     ? ({ M_OBJECT, M_ARG, E_TARGET, "." })
     : (e[E_TARGET]->id(e[E_TARGET,1])
       ? ({ e[E_TARGET,1] + "." })
       : ({ M_OBJECT, M_ARG, E_TARGET, "." }))),
    ({ M_WRITE,
       h || capitalize(message2string(({ M_PRONOUN, e[E_TARGET], M_VERB, "have",
                                   e[E_TARGET], " no particular taste." })))}),
    }));
}

void taste(mapping e) {
  mixed h;
  h = e[E_TARGET]->query_taste(e[E_TARGET, 1]);
  if (h && h[<1] == '\n')
    h = h[0..<2];
  message(({ e,
    ({ M_PL_THE, M_PL_VERB, e[E_TYPE,1], M_THE }) +
#if 0  // Coogan, 27-Apr-02
    (e[E_TARGET] != environment(e[E_AGENT])
     ? ({ M_OBJECT, M_ARG, E_TARGET, "." })
     :
#endif
     // added living check for a better message, Coogan, 15-Aug-2006
       (living(e[E_TARGET])
        ? ({ M_OBJECT, M_ARG, E_TARGET, "." })
        : (e[E_TARGET]->id(e[E_TARGET,1])
           ? ({ e[E_TARGET,1] + "." })
           : ({ M_OBJECT, M_ARG, E_TARGET, "." })
          )
       )
#if 0
       )
#endif
        ,
    ({ M_WRITE,
       h || capitalize(message2string(({ M_PRONOUN, e[E_TARGET], M_VERB,
                           "have", e[E_TARGET], " no particular taste." })))}),
    }));
}

void sniff(mapping e) {
  mixed h;
  h = (e[E_TARGET]->query_smell(e[E_TARGET, 1]) ||
       e[E_TARGET]->query_property(P_SMELL));
  if (h && h[<1] == '\n')
    h = h[0..<2];
  message(({ e,  // args-mapping
    ({ M_PL_THE, M_PL_VERB, e[E_TYPE,1], M_THE }) +
    (e[E_TARGET] != environment(e[E_AGENT])
     ? ({ M_OBJECT, M_ARG, E_TARGET, "." })
     : (e[E_TARGET]->id(e[E_TARGET,1])
       ? ({ e[E_TARGET,1] + "." })
       : ({ "the air." }))),
    ({ M_WRITE, h || "You smell nothing special." }) }));
}

void smell(mapping e) {
  sniff(e);
}

void listen(mapping e) {
  mixed h;
  h = e[E_TARGET]->query_sound(e[E_TARGET, 1]);
  if (h && h[<1] == '\n')
    h = h[0..<2];
  message(({ e,
    ({ M_PL_THE, M_PL_VERB, "listen", " to ", M_THE }) +
    (e[E_TARGET] != environment(e[E_AGENT]) 
     ? ({ M_OBJECT, M_ARG, E_TARGET, "." }) 
     : (e[E_TARGET]->id(e[E_TARGET,1])
       ? ({ e[E_TARGET,1] + "." })
       : ({ M_OBJECT, M_ARG, E_TARGET, "." }))),
    ({ M_WRITE, h || "You hear nothing special." }) }));
}

void receive_sense_event(mapping e, string type, int prio) {
  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  if (e[E_HANDLER])
    return;
  if (!e[E_TARGET]) {
    e[E_SUCCESS] = 0;
    return;
  }
#if 0 // Ugh Oct-15-98
      // (I don't see a reason why one should not be able to smell
      //  at something just because it has no particular smell).
  if (!e[E_TARGET]->query_property(P_EATABLE) &&
      !e[E_TARGET]->query_property(P_LIQUID) &&
      !e[E_TARGET]->query_property(P_DRINKABLE) &&
      e[E_TARGET] != environment(e[E_AGENT]) &&
      !((e[E_TYPE,1] == "smell" || e[E_TYPE,1] == "sniff") &&
        e[E_TARGET]->query_smell())) {
    e[E_SUCCESS] = 0;
    if (living(e[E_TARGET]))
      return notify_fail("You can't " + e[E_TYPE,1] + " " +
                         (e[E_TARGET]->query_objective() || "it") +
                         ".\n"), 0;
    return notify_fail("You can't " + e[E_TYPE,1] + " that.\n"), 0;
  }
#endif
  switch (e[E_TYPE, 1]) {
  case "taste":
    with_player(e[E_AGENT], #'taste, e);
    e[E_AGENT]->use_skill(S_TASTE);     // Coogan, 02-Jan-01
    break;
  case "lick":
    with_player(e[E_AGENT], #'lick, e);
    e[E_AGENT]->use_skill(S_TASTE);     // Coogan, 02-Jan-01
    break;
  case "sniff":
    with_player(e[E_AGENT], #'sniff, e);
    e[E_AGENT]->use_skill(S_SMELL);     // Coogan, 02-Jan-01
    break;
  case "smell":
    with_player(e[E_AGENT], #'smell, e);
    e[E_AGENT]->use_skill(S_SMELL);     // Coogan, 02-Jan-01
    break;
  case "listen":
    with_player(e[E_AGENT], #'listen, e);
    e[E_AGENT]->use_skill(S_HEAR);      // Coogan, 02-Jan-01
    break;
  }
  return;
}

status do_action(string action, mapping args) {
  mapping e;
  string sense_function;

  if (!args[G_OBJECT]) {  // 'smell here' or similar?
    args[G_OBJECT] = environment(this_player());
    args[G_OBJECT,1] = "here";  // this is the id
  }

  sense_function = 0;
  switch (action) {
  case "listen":
    sense_function = "query_sound";
    break;
  case "lick":
#if 0  // this is not a feeling yet
  case "taste":
#endif
    sense_function = "query_taste";
    break;
  case "sniff":
#if 0  // this is not a feeling yet
  case "smell":
#endif
    sense_function = "query_smell";
    break;
  }

  // let the soul handle this, as there is nothing special here.
  // Coogan, 17-Aug-2006
  if (sense_function    &&
      living(args[G_OBJECT])    &&
      call_other(args[G_OBJECT], sense_function) == 0)
    return 0;

  e = ([
         E_TYPE    : "sense"       ; action,
         E_AGENT   : this_player() ; this_player()->query_name(),
         E_TARGET  : args[G_OBJECT]; args[G_OBJECT,1],
         E_SUCCESS : 1             ; 0,  // optimistic first
      ]);

  switch (action) {
  case "lick":
  case "sniff":
  case "smell":
  case "taste":
  case "listen":
    send_event("sense", e, ({ environment(this_player()) }));
    break;
  default:
    raise_error("Unexpected value\n");
  }
  return e[E_SUCCESS];
}

void create() {
  set_global_listening_event("sense", 1);
  listen_event("sense", HANDLE_PRIO, #'receive_sense_event);
}

