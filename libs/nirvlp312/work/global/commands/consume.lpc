/*
 * global/commands/consume, written by Coogan@Tubmud, Jan 98
 *
 */

#pragma strong_types

inherit "basic/create";

#include <describe.h>
#include <grammar.h>
#include <message.h>
#include <event.h>
#include <prop/item.h>

#define HANDLE_PRIO      1
#if 0  // Coogan, 06-Jul-98
#define DEFAULT_LIQUIDS  (({ "water" }))
#endif

void do_eat(mapping e) {
  if (!e[E_TARGET])
    return;
  e[E_TARGET]->consume_food(e[E_AMOUNT], e[E_TYPE, 1]);
}

void do_drink(mapping e) {
  if (!e[E_TARGET])
    return;
  if (e[E_TARGET] == e[E_FROM])  // old drinks
    e[E_TARGET]->drink(e[E_TARGET]);
  else
    e[E_TARGET]->consume_liquid(e[E_AMOUNT], e[E_TYPE, 1]);
}

void do_slurp(mapping e) {
  if (!e[E_TARGET])
    return;
  e[E_TARGET]->consume_liquid(e[E_AMOUNT], e[E_TYPE, 1]);
}

void receive_consume_event(mapping e, string type, int prio) {
  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  switch (e[E_TYPE, 1]) {
  case "eat":
    if (e[E_TARGET])
      do_eat(e);
    break;
  case "drink":
  case "sip":
    if (e[E_TARGET])
      do_drink(e);
    break;
  case "slurp":
    if (e[E_TARGET])
      do_slurp(e);
    break;
  }
  return;
}

object clone_dummy_liquid(string name) {
  object l;
  l = clone_object("complex/liquid");
  l->set_name(name);
  l->set_invitro(1);  // needed for nicer messages
  return l;
}

status do_action(string action, mapping args) {
  mapping e;
  object ob;

  e = ([ E_AGENT        : this_player(); this_player()->query_name(),
         E_RECIPIENT    : this_player(); this_player()->query_name(),
         E_SUCCESS      : 1            ; 0,  // we are optimistic first
      ]);

  if (args[G_IN_ENVIRONMENT])
    switch (action) {
      case "eat":
      case "eat_all":
        if (args[G_IN_ENVIRONMENT] == environment(this_player()))
          return notify_fail("You can't eat that.\n"), 0;
        if (!args[G_IN_ENVIRONMENT]->query_property(P_EATABLE))
          return notify_fail("You can't eat that.\n"), 0;
        return notify_fail("First get it!\n"), 0;

      case "sip":
      case "drink":
      case "drink_all":
        if (args[G_IN_ENVIRONMENT] == environment(this_player())) { // fakeitem
#if 0
          if (member(DEFAULT_LIQUIDS, args[G_IN_ENVIRONMENT, 1]) == -1)
#else   // added this part to re-enable a default drink action for fakeitems
        // which are marked as drinkable, Coogan, 06-Jun-2004
          if (!args[G_IN_ENVIRONMENT]->query_property(P_DRINKABLE) ||
              member(args[G_IN_ENVIRONMENT]->query_property(P_DRINKABLE),
                     args[G_IN_ENVIRONMENT,1]) == -1)
#endif
            return notify_fail("You can't " +
                     ((action=="sip") ? "sip" : "drink")+" that.\n"), 0;
#if 1   // 1 again, Coogan, 06-Jun-2004
          ob = clone_dummy_liquid(args[G_IN_ENVIRONMENT, 1]);
          e += ([ E_TARGET : ob; args[G_IN_ENVIRONMENT, 1] ]);
          if (action == "drink")
            action = "drink_all";
#endif
        }
        else if (args[G_IN_ENVIRONMENT]->query_property(P_LIQUID))
            e += ([ E_TARGET : args[G_IN_ENVIRONMENT, 0];
                               args[G_IN_ENVIRONMENT, 1] ]);
        else if ((ob = present(args[G_IN_ENVIRONMENT, 1],
                               args[G_IN_ENVIRONMENT, 0])) &&
                 ob->query_property(P_LIQUID) &&
                 !ob->query_property(P_NOT_PORTABLE))  // e.g. a fountain
            e += ([ E_TARGET : ob;
                               args[G_IN_ENVIRONMENT, 1] ]);
        else
            return notify_fail("First get it!\n"), 0;
        break;

      case "slurp":
      case "slurp_all":
        if (args[G_IN_ENVIRONMENT] == environment(this_player())) // fakeitem
#if 0
            member(DEFAULT_LIQUIDS, args[G_IN_ENVIRONMENT,1]) != -1) {
          args[G_IN_ENVIRONMENT]=clone_dummy_liquid(args[G_IN_ENVIRONMENT, 1]);
          action = "slurp_all";
          }
#else
          return notify_fail("You can't slurp that.\n"), 0;
#endif
        if (args[G_IN_ENVIRONMENT]->query_property(P_LIQUID))
          e += ([ E_TARGET : args[G_IN_ENVIRONMENT, 0];
                             args[G_IN_ENVIRONMENT, 1],
               ]);
        else
          return notify_fail("You can't slurp that.\n"), 0;
        break;

      default:
        return 0;
      }

  if (args[G_IN_INVENTORY] &&
      environment(args[G_IN_INVENTORY]) != this_player())
    return
      notify_fail(({({ M_WRITE, "First get ", M_PRONOUN, M_OBJECT,
                       args[G_IN_INVENTORY], " out of ", M_THE, M_OBJECT,
                       environment(args[G_IN_INVENTORY]), "!" })})), 0;

  if (args[G_IN_INVENTORY])
    switch (action) {
    case "eat":
    case "eat_all":
      if (args[G_IN_INVENTORY]->query_property(P_EATABLE))
        e += ([ E_TARGET : args[G_IN_INVENTORY, 0];
                           args[G_IN_INVENTORY, 1],
             ]);
      else
        return notify_fail("You can't eat that.\n"), 0;
      break;

    case "sip":
    case "drink":
    case "drink_all":
      if (args[G_IN_INVENTORY]->query_property(P_DRINKABLE)) // compatibility
        ob = args[G_IN_INVENTORY];                          // for old drinks
      else                          // bottles containing liquid 
        ob = present(args[G_IN_INVENTORY, 1], args[G_IN_INVENTORY, 0]);
      if (ob &&
          (ob->query_property(P_LIQUID) || ob->query_property(P_DRINKABLE)))
        e += ([ E_TARGET : ob; args[G_IN_INVENTORY, 1],
                E_FROM   : args[G_IN_INVENTORY, 0];
                           describe(args[G_IN_INVENTORY, 0], ARTICLE_NONE),
             ]);
      else
        return notify_fail("You can't " +
                 ((action=="sip") ? "sip" : "drink")+" that.\n"), 0;
      break;

    case "slurp":
    case "slurp_all":
      return notify_fail("You can't slurp that.\n"), 0;

    default:
      return 0;
    }

  switch (action) {
    case "eat_all":
    case "drink_all":
    case "slurp_all":
      e += ([ E_AMOUNT : e[E_TARGET]->query_encumbrance(); 0,
              E_TYPE   : "consume"; action[0..<5],
           ]);
      break;
    case "eat":
      if (member(args, G_NUMBER)) {
        if (args[G_NUMBER] < 0)
          return notify_fail("You are silly eating less than nothing!\n"), 0;
        else if (args[G_NUMBER] == 0)
          return notify_fail("You are silly eating nothing!\n"), 0;
        e += ([ E_AMOUNT : args[G_NUMBER] * e[E_TARGET]->query_portion(); 0,
                E_TYPE   : "consume"; action,
             ]);
        break;
      }
      e += ([ E_AMOUNT : e[E_TARGET]->query_portion(); 0,
              E_TYPE   : "consume"; action,
           ]);
      break;
    case "sip":
      if (e[E_TARGET]->query_encumbrance() <= e[E_TARGET]->query_potion()) {
        e += ([ E_AMOUNT : e[E_TARGET]->query_encumbrance(); 0,
                E_TYPE   : "consume"; "drink",
             ]);
        break;
      }
      // fall through
    case "drink":
    case "slurp":
      e += ([ E_AMOUNT : e[E_TARGET]->query_portion(); 0,
              E_TYPE   : "consume"; action,
           ]);
      break;
  }
  send_event("consume", e, ({ environment(this_player()) }));
  return e[E_SUCCESS];
}

void create() {
  set_global_listening_event("consume", 1);
  listen_event("consume", HANDLE_PRIO, #'receive_consume_event);
}

