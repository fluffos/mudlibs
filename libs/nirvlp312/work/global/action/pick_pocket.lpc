/*
 * pick the pockets of a living.....
 * sas@cs.tu-berlin.de (Ardanna)
 *
 * Modified Aug28 93 muxestba
 * Modified for NEW_MONEY Oct10 96 carador
 * Rewritten and event added, Coogan, 12-14. Jan-02
 */

#pragma strong_types

#include <skilltree.h>
#include <grammar.h>
#include <money.h>
#include <message.h>
#include <prop/living.h>
#include <event.h>
#include <server.h>

inherit "basic/parser";
inherit "basic/action";

private void receive_pickpocket_event(mapping e, string type, int prio);

mapping weight;
int sk;

void create() {
  action::create();
  set_skill_path(S_P_PICK_POCKET);
  set_command("pick");
  set_specific("pockets");
  set_function("parse_action");
  weight = COIN_WEIGHT;

  add_rule("pick pockets of "G_LIVING, "pick_pocket_living");
  add_rule("pick pockets of "G_TEXT,   "pick_pocket_error");
  add_error_message("pick", "Pick pockets of whom?\n");

  set_global_listening_event("pick_pocket", 1);
  listen_event("pick_pocket", EPRIO_HANDLE, #'receive_pickpocket_event);
}

string *init_living(object ob) {
  if (!ob)  // Coogan, 05-Jul-99
    return 0;
  if (ob->query_skill(query_skill_path()) < 1)
    return 0;
  return ({({ "pick", 0, "parse_action" })});
}

string query_info(string str) {
  return
    "You can try to pick the pockets of anyone, but if your attempt fails\n"
    "that person or monster might notice you and become aggressive.\n"
    "SYNOPSIS: pick pockets of <name> \n";
}

private int apply_pickpocket_action(mapping e) {
  sk = sk || this_player()->query_modified_skill(query_skill_path());
  return (e[E_TARGET]->apply_action(query_skill(), sk, e));
}

private void receive_pickpocket_event(mapping e, string type, int prio) {
  if (type != "pick_pocket" || prio != EPRIO_HANDLE || e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_pickpocket_action, e);
}

void inform(object victim) {
  victim && tell_object(victim, "Your purse feels strangely light ...\n");
  return;
}

private void reward_agent(int success) {
  if (success > 1)
    this_player()->add_skill_points(query_skill_path(), success);
  else
    this_player()->add_skill_points(query_skill_path(),
                                    SE_SKILLS->query_reward(this_player(),
                                                            success, 50,
                                                            S_P_PICK_POCKET));
}

int do_action(string action, mapping args) {
  mapping event, coins, stolen;
  string *types, desc;
  int chance, i, j, enc, amount;
  status too_much;

  if (args[G_LIVING] &&
      args[G_LIVING] == this_player()->query_attack()) {
    notify_fail("You are quite busy fighting " +
                describe(args[G_LIVING], ARTICLE_THE) + "!\n");
    return 0;
  }
  if (args[G_LIVING] && args[G_LIVING] == this_player()) {
    write("Pick your own pockets? Don't be ludicrous!\n");
    return 1;
  }
  if (args[G_LIVING]) {
    if (interactive(this_player()) && interactive(args[G_LIVING])) {
      /* 3.12.92 Mentar: Vorlaeufig pickpocket gegen Spieler disabled */
      write("You don't dare to steal from your fellow player.\n");
      return 1;
    }
    if (query_once_interactive(args[G_LIVING])) {
      write("It is impossible to pick pockets made of stone.\n");
      return 1;
    }
  }
  if (args[G_TEXT]) {
    object o;
    if ((o = present(args[G_TEXT], environment(this_player()))) &&
        !living(o)) {
      write("You find no pockets on your intended victim.\n");
      return 1;
    }
    return 0;  // standard error message
  }

  event = ([ E_AGENT    : this_player(),
             E_TARGET   : args[G_LIVING],
          ]);
  sk = this_player()->query_modified_skill(query_skill_path());
  send_event("pick_pocket", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;

  // when E_SUCCESS is greater than 0, then we do nothing but improve the
  // skill of the player. We assume, that every further action (and perhaps
  // a successful pilfering) was already done in apply_action().
  if (event[E_SUCCESS] > 0) {
    reward_agent(event[E_SUCCESS]);
    return 1;
  }

  // the next is not approved yet. Just return, action is done, no reward.
  if (event[E_SUCCESS] < 0)
    return 1;

  // Somebody with skill level 50 shall also have the chance to fail
  // when pilfering someone with intelligence 10. Carador.
  if (random(sk) < random(5*event[E_TARGET]->query_int())) {
    /* caught you red-handed...*/
    if (interactive(event[E_TARGET])) {
      send_message(({ M_TARGETS, M_ARG, E_TARGET, M_THE, M_ARG, E_AGENT,
                      " tried to pick your pockets." }), event);
      message("Your attempt at picking pockets failed.\n"
              "You might have been noticed too...\n");
      reward_agent(1);
      return 1;
    }
    send_message(({ M_WRITE, M_THE, M_ARG, E_TARGET, " noticed you!" }), event);
    if (event[E_TARGET]->query_property(P_NOT_FIGHTABLE)) {
      send_message(({ M_THE, M_ARG, E_TARGET, M_VERB, "slap", M_ARG, E_TARGET,
                      M_PL_THE, " hard in the face." }), event);
      this_player()->hit_player(event[E_TARGET]->query_level(), this_object());
    } else if (!event[E_TARGET]->notice_pick_pocket(this_player()))
      event[E_TARGET]->attacked_by(this_player());
    return 1;
  }	

  // Carador, Oct-96
  coins = event[E_TARGET]->query_coins();
  if (!sizeof(coins) || !event[E_TARGET]->query_money()) {
    send_message(({ M_WRITE, M_THE, M_ARG, E_TARGET, M_VERB, "do", M_ARG,
                    E_TARGET, " not posses any coins." }), event);
    return 1;
  }    

  stolen = ([ ]);
  types = m_indices(coins);
  chance = sk/2;
  for (i=sizeof(types); i--; )
    for (j=coins[types[i]]; j--;) {
      if (!this_player()->test_encumbrance(enc + weight[types[i]])) {
        too_much = 1;
        break;
      }
      if (random(100) < chance) {
        stolen[types[i]] ++;
        enc += weight[types[i]];
      }
    }

  if (!sizeof(stolen)) {
     if (too_much)
       message("You can't carry any further coin.\n");
     else
#if 0
       message("You don't manage to steal anything.\n");
#else
       message("Hmpf. Nothing.\n");
#endif
     return 1;
  }

  event[E_TARGET]->subtract_coins(stolen);

  this_player()->add_coins(stolen);
  amount = LIB_MONEY->query_value(stolen);
  desc   = LIB_MONEY->describe_money(stolen);

  log_file("Skills.all",
           this_player()->query_real_name() + " stole " + amount + " (" +
           desc + ") from " + describe(event[E_TARGET], ARTICLE_A) + " in " +
           environment(this_player())->short() +
           " (" + object_name(environment(this_player())) + ").\n");

  message("You successfully pilfer " + desc + " from " +
           describe(event[E_TARGET], ARTICLE_THE) + ".\n");

  if (interactive(event[E_TARGET]) && is_wizard(event[E_TARGET])) 
    tell_object(event[E_TARGET],
                "Your magical instinct tells you that " +
                this_player()->query_vis_name() + " successfully pilfered " +
                desc + " from you.\n");
  reward_agent(1);
  if (enc > 300)
    call_out("inform", sk, event[E_TARGET]);
  return 1;
}

