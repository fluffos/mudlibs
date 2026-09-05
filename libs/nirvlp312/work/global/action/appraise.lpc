/*
 * action handler for the appraise action
 * modified Aug 93 by marion@cs.tu-berlin.de
 * shortened to 'estimate value of' usage, Coogan, 05-Feb-02
 */

#pragma strong_types

#include <skilltree.h>
#include <grammar.h>
#include <global_commands.h>

inherit "basic/parser";
inherit "basic/action";

void create() {
  action::create();
  set_skill_path(S_ESTIMATE_ITEM);
  set_command("appraise");
  set_specific(0);
  set_function("parse_action");

  add_rule("appraise "G_OBJECT, "est_value", COMMANDS_LOOK);
  add_error_message("appraise", "Appraise what?\n");
}

string query_info(string str) {
  return "You can try to guess the value of an item you have in your\n"
         "inventory, but be careful you need a lot of practice before you\n"
         "know the worth of an item before the shop does.\n";
}               

