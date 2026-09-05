/*
 * This object defines the commands for players which concern the privacy
 * in the mud. It is a daemon and must be added with a negative priority
 * to achieve the wanted privacy.
 *
 * A daemon added with negative priority cannot be overridden by the use of
 * add_action().
 *                                     Alfe 1997-Jun-13
 *
 * Everything embedded in #define INTERMUD3 is part of the Intermud-3-code,
 * written by Fafnir 1998, (C) Evermore 1998
 */

#pragma strong_types

#include <grammar.h>
#include <global_commands.h>  // added global_, Coogan, 02-May-2001

#ifdef INTERMUD3
#include <imud3.h>
#endif

inherit "basic/daemon";
inherit "basic/parser";
inherit "basic/create";

void create() {

#if 0  // Coogan, 18-Feb-2002, obsolete now
#ifdef INTERMUD3
  add_rule("tell "G_REMOTE_RESOURCE" "G_TEXT,"tell_remote");
#endif
#endif

  // next two rules by Coogan, 14-Feb-2002
  add_rule("to "G_AMBIG_LIVINGS" "G_ADVERBS" tell "G_TEXT,"tell",COMMANDS_COMM);
  add_rule("to "G_AMBIG_LIVINGS" tell "G_TEXT,           "tell",COMMANDS_COMM);

  // next rules by Coogan, 19-Feb-2002
  add_rule("tell < "G_ADVERBS" > "G_AMBIG_LIVINGS" "G_TEXT,"tell",COMMANDS_COMM);

  add_rule("tell to "G_AMBIG_LIVINGS" in "G_TONGUE" "G_TEXT,
                                                         "tell",COMMANDS_COMM);
  add_rule("tell to "G_AMBIG_LIVINGS" "G_TEXT,           "tell",COMMANDS_COMM);
  add_rule("tell "G_AMBIG_LIVINGS" in "G_TONGUE" "G_TEXT,"tell",COMMANDS_COMM);
  add_rule("tell "G_AMBIG_LIVINGS" "G_TEXT,              "tell",COMMANDS_COMM);
  add_error_message("tell", "Tell whom what?\n");
  filter(query_rule_verbs(),
               lambda(({ 'v }), ({ #'add_command, "parse_cmd", 'v })));
  create::create();
}

int parse_cmd(string arg,string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

#ifdef INTERMUD3
int do_action(string v, mapping a) {
  mixed h;

  a[G_REMOTE_RESOURCE,1] = capitalize(a[G_REMOTE_RESOURCE,1]);
  h = IMUD3->send_tell(a[G_REMOTE_RESOURCE,1], a[G_REMOTE_RESOURCE], a[G_TEXT]);
  switch (h) {
  case 0:
    write(a[G_REMOTE_RESOURCE]+" doesn't support remote tells.\n");
    return 1;
  case 1:
    write("You tell " + a[G_REMOTE_RESOURCE,1] + "@" +
          a[G_REMOTE_RESOURCE] + ": " + a[G_TEXT] + "\n");
    return 1;
  }
  // default:
  return 1;
}
#endif

