/*
 * action handler for the hiss action
 * modified Aug 93 by marion@cs.tu-berlin.de
 * shortened by Coogan, 05-Feb-02
 */

#pragma strong_types

#include <skilltree.h>
#include <grammar.h>
#include <tongue.h>
#include <global_commands.h>

inherit "basic/parser";
inherit "basic/action";

void create() {
  action::create();
  set_skill_path(S_LIZTONGUE);
  set_command("hiss");
  set_specific(0);
  set_function("parse_action");

  add_rule("hiss at "G_ALL_LIVINGS" \" "G_TEXT" \"", "hiss", COMMANDS_COMM);
  add_rule("hiss at "G_ALL_LIVINGS" \" "G_TEXT,      "hiss", COMMANDS_COMM);
  add_rule("hiss at "G_ALL_LIVINGS" "G_TEXT,         "hiss", COMMANDS_COMM);
  add_rule("hiss "G_TEXT,                            "hiss", COMMANDS_COMM);
  add_error_message("hiss", ({ "Hiss what?\n", -1 }));
}

string query_info(string str) {
  return "To hiss means to speak in the language of lizards. Depending\n"
         "on how complicated a word is, the chance of properly pronouncing it\n"
         "decreases. Of course, skilled liztongue-speakers can even hiss\n"
         "supercalilizwaysswampy without problems.\n";
}

