/*
 *  forge.c - give a forge skill
 *  April/May 1997 by Coogan
 */

#pragma strong_types

#include <grammar.h>
#include <describe.h>
#include <event.h>
#include <skills.h>
#include <skilltree.h>
#include <server.h>

#define HANDLE_PRIO  0
#define NO_OBJECT    "<no_object>"
#define MAX_REWARD   (IMPROVE_SOMEWHAT*2)

inherit "basic/parser";
inherit "basic/action";

private void receive_forge_event(mapping event, string type, int prio);

void create() {
  action::create();
  set_skill_path(S_P_SMITH);
  set_command("forge");
  set_specific(0);
  set_function("parse_action");
  set_reward(MAX_REWARD);

  duplicate_class(G_TEXT, NO_OBJECT);

  add_rule("forge "G_OBJECT" into "G_TEXT,   "forge");
  add_rule("forge "G_TEXT" out of "G_OBJECT, "forge");
  add_rule("forge "G_TEXT" from "G_OBJECT,   "forge");

  add_rule("forge "NO_OBJECT" into "G_TEXT,   "forge_error");
  add_rule("forge "G_TEXT" out of "NO_OBJECT, "forge_error");
  add_rule("forge "G_TEXT" from "NO_OBJECT,   "forge_error");

  add_error_message("forge",({ "Forge what from/out of what?\n", -1 }));

  set_global_listening_event("forge",1);
  listen_event("forge", HANDLE_PRIO, #'receive_forge_event);
}

int do_action(string action, mapping args) {
  mapping ev;

  if (action == "forge_error") {
    if (!present(args[NO_OBJECT],this_player())) {
      if (!present(args[NO_OBJECT],environment(this_player())))
        notify_fail("You can't forge "+
                    describe(args[G_TEXT])+", because you don't possess "+
                    describe(args[NO_OBJECT])+"!\n",1);
      else
        notify_fail("You can't forge "+
                    describe(args[G_TEXT])+" here with that "+
                    describe(args[NO_OBJECT],ARTICLE_NONE)+"!\n",1);
    }
    return 0;
  }

  ev = ([ E_TARGET:  args[G_TEXT],
          E_COMMAND: action,
          E_AGENT:   this_player(),
       ]);
  if (args[G_OBJECT]) {
    ev += ([ E_OBJECT:  args[G_OBJECT],
             E_ID:      args[G_OBJECT,1],
          ]);
    notify_fail("You can't forge "+describe(args[G_TEXT])+" out of "+
                describe(args[G_OBJECT],ARTICLE_THE)+" here!\n",1);
  } else
    notify_fail("You can't forge "+describe(args[G_TEXT])+" here!\n",1);
  send_event("forge", ev, environment(this_player()));
  if (ev[E_CANCELLED])
    return 1;
  if (ev[E_SUCCESS] > 0) {
    if (ev[E_SUCCESS] == 1)
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              ev[E_SUCCESS],
                                                              50, S_P_SMITH));
    else
      this_player()->add_skill_points(query_skill_path(), ev[E_SUCCESS]);
  }
  return ev[E_SUCCESS];
}

private int apply_forge_action(mapping event) {
  int skill;
  skill = this_player()->query_modified_skill(query_skill_path());
  return (environment(this_player())->apply_action(query_skill(),skill,event));
}

private void receive_forge_event(mapping event, string type, int prio) {
  if (type != "forge" || prio != HANDLE_PRIO)
    return;
  event[E_HANDLED] = 1;
  event[E_SUCCESS] = with_player(event[E_AGENT], #'apply_forge_action, event);
  if (event[E_SUCCESS] > 0)
    event[E_AGENT]->decrease_saturation();  // Coogan, 01-Apr-2003
}

string query_info (string str) {
  return
    "Several raw materials like crude metal or metal bars can be forged.\n"
    "But bear in mind, that it's a long way to become a good smith.\n";
}

/*
 * To use this skill define in the room where the object can be smithed
 * something like that:

// if you want other error messages than the default error messages, put into
// configure() the following (here only an example):
void configure() {
  ... your stuff from configure()
  add_error_message("forge",
                    "You can't forge here, because the anvil is broken!\n");
}

// but the next one is really nessessary:
int apply_action(string action, int level, mapping args) {
  switch (action) {
    case "forge":
      ... args is a mapping with the contents: 
          string E_TARGET:  what is to be forged, e.g. "floret"
          string E_COMMAND: action ("forge")
          object E_AGENT:   who wants to forge
          object E_OBJECT:  which object is the raw material
          string E_ID:      the matched id of the to-be-forged object

      ... do here what is to do

      ... if there is a reason leading to an unsuccessful forge action (and
          no reward should be given), use
        notify_fail("message"); or notify_fail(({({ message_array })}));
        return 0;

      ... if you are going to let them forge weapons, please use the following
          to make this things equal in all smithies:

      weapon_class = to_int(level/5.8)+4;
      if (weapon_class > 20)
        weapon_class = 20;

      ... the range of weapon_class is [4..20]
      ... some examples:
      ... smith count    : 0  100  300  500  1000  1600
      ... level          : 0   46   71   81    89    93
      ... resulting class: 4   11   16   17    19    20
      ... the smith count means that the smith always got the maximal reward

      ... in all other cases (perhaps you want to forge an ornamented gate)
          just do like you want.

      ... we want the standard reward dependent on the light, the load of the
          player, his dexterity and his strength:
      return 1;
    default:
      return 0;
    }
  return 0;
}

*/

