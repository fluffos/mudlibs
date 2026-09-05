/*
 * bin/interactive.c by Alfe for Tubmud 1998-Apr-29
 *
 * a daemon for all commands which interactives should have
 */

#include <kernel.h>
#include <message.h>
#include <grammar.h>
#include <libs.h>
#include <persistence.h>
#include <global_commands.h>  // added global_, Coogan, 02-May-2001

#define BG_COLOUR       "<bg_colour>"       // Coogan, 24-Feb-2000
#define G_WRONG_COLOUR  "<g_wrong_colour>"  // Coogan, 22-Sep-2001

inherit ACCESS;
inherit "basic/create";
inherit "basic/daemon";
inherit "basic/parser";

void create() {
  add_rule("quit",       "quit_normal");
  add_rule("quit really","quit_really");
  add_rule("save",       "save");
  add_rule("finalize",   "finalize");
  add_rule("persistent "G_ALL,"persistent");
  add_rule("prompt "G_TEXT, "prompt");  // Alfe 1998-Jul-31
  add_rule("prompt",        "prompt");

  add_rule("create party", "party_create",  COMMANDS_MISC);
  add_rule("leave party",  "party_leave",   COMMANDS_MISC);
  add_rule("party score",  "party_score",   COMMANDS_MISC);
  add_rule("party info",   "party_info",    COMMANDS_MISC);
  add_rule("add "G_ANY_LIVING" to party", "party_add",
                                            COMMANDS_MISC);
  add_rule("remove "G_ANY_LIVING" from party", "party_remove",
                                            COMMANDS_MISC);
  add_rule("change party leadership to "G_ANY_LIVING, "party_ch_leader",
                                            COMMANDS_MISC);
  add_rule("make "G_ANY_LIVING" to party leader", "party_ch_leader",
                                            COMMANDS_MISC);
  add_error_message("party", "See 'help party' for further details.\n");

  // colour handling added, Coogan, 25-Feb-2000
  duplicate_class(G_COLOUR, BG_COLOUR);
  duplicate_class(G_WORDS,  G_WRONG_COLOUR);
  // next eight rules, Coogan, 16-Oct-2001
  add_rule("colour "BG_COLOUR" background for "G_WORDS" from "G_WORD,
                                           "set_bg_colour", COMMANDS_COLOUR);
  add_rule("colour "BG_COLOUR" background for "G_WORDS" with "G_WORD,
                                           "set_bg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" background for "G_WORDS" from "G_WORD,
                                           "set_bg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" background for "G_WORDS" with "G_WORD,
                                           "set_bg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_COLOUR" foreground for "G_WORDS" from "G_WORD,
                                           "set_fg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_COLOUR" foreground for "G_WORDS" with "G_WORD,
                                           "set_fg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" foreground for "G_WORDS" from "G_WORD,
                                           "set_fg_colour", COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" foreground for "G_WORDS" with "G_WORD,
                                           "set_fg_colour", COMMANDS_COLOUR);

  add_rule("colour "BG_COLOUR" background for "G_WORDS, "set_bg_colour",
                                                            COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" background for "G_WORDS, "set_bg_colour",
                                                            COMMANDS_COLOUR);
  add_rule("colour "G_COLOUR" foreground for "G_WORDS,  "set_fg_colour",
                                                            COMMANDS_COLOUR);
  add_rule("colour "G_WRONG_COLOUR" foreground for "G_WORDS,  "set_fg_colour",
                                                            COMMANDS_COLOUR);
#if 1  // Coogan, 16-Oct-2001
  add_rule("colour reset for "G_WORDS" from "G_WORD,
                                        "reset_one_colour", COMMANDS_COLOUR);
  add_rule("colour reset for "G_WORDS" with "G_WORD,
                                        "reset_one_colour", COMMANDS_COLOUR);
#endif
  add_rule("colour reset for "G_WORDS,  "reset_one_colour", COMMANDS_COLOUR);
  add_rule("colour reset",              "reset_colours",    COMMANDS_COLOUR);
  add_rule("colour status",             "status",           COMMANDS_COLOUR);
  // next four by Coogan, 19-Feb-2001
  add_rule("colour toggle "G_WORD,      "colour_toggle",    COMMANDS_COLOUR);
  add_rule("colour toggle",             "colour_toggle",    COMMANDS_COLOUR);
  add_rule("colour model "G_WORD,       "colour_model",     COMMANDS_COLOUR);
  add_rule("colour model",              "colour_model",     COMMANDS_COLOUR);
  add_rule("colour setting "G_WORD,     "colour_setting",   COMMANDS_COLOUR);
  add_rule("colour setting",            "colour_setting",   COMMANDS_COLOUR);
  add_error_message("colour",
                    ({ "See 'help colour' for further details.\n", -1}));

  add_rule("pose", "pose");// moved from obj/player to here, Coogan, 01-Dec-2000

  add_rule("toggle brief", "toggle_brief", COMMANDS_MISC);// Coogan, 01-Dec-2000
  filter(query_rule_verbs(),
               lambda(({ 'v }),({ #'add_command,"parse_cmd",'v })));
  create::create();
}

int parse_cmd(string arg, string verb) {
  return parse_sentence(arg? verb + " " + arg : verb);
}

status do_action(string action,mapping args) {
  mixed h;
  switch (action) {
  case "pose":
    if (this_player()->query_level() >= 15) {
      message(({ M_RAW,
                 ({ M_SAY, M_PL_THE, M_PL_VERB, "make",
                    " a magical gesture.\n"
                    "A ball of fire explodes in the sky." }),
                 ({ M_WRITE, "You send a ball of fire into the sky." })}));
    }
    else {
      message(({ M_RAW,
                 ({ M_SAY, M_PL_THE, M_PL_VERB, "try", " to make"
                    " a magical gesture.\n"
                    "Nothing happens." }),
                 ({ M_WRITE, "You try hard to send a ball of fire into "
                    "the sky, but nothing happens." }),
                 ({ M_WRITE, "Maybe when you reached another level?" })}));
      return 1;
    }
    return 1;
  case "quit_normal":
    if (this_player()->query_guest()) {
      message("As a guest character you only can quit by typing 'quit really'"
              " which will destroy your character, the name you chose and"
              " any information about you. If you want to store your character"
              " you have to leave the guest status behind by typing"
              " 'finalize'.\n");
      return 1;  // quit is nothing to be overloaded
    }
    message("You go linkdead now and will be logged out after 30 minutes.\n");
#if TUBMUD  // Coogan, 19-Feb-2001
    message("See you soon back in Tubmud!\n");
#endif
    remove_interactive(this_player());  // make him linkdead; this in turn
                                        // will call master::disconnect()
                                        // which calls
                                        // player->notify_disconnect() which
                                        // then gives him a nice petrification
                                        // mark which will log him out after
                                        // 30 minutes.
    return 1;
  case "quit_really":
    if (this_player()->query_guest())
      message("Ok, your character will not be saved, any information about"
              " it is now lost.\n"
              "Good-bye, hope to see you again with another character.\n");
    else  // Alfe 1998-May-5
      log_file("QUIT_REALLY",
               ctime() + ": " + this_player()->query_real_name() +
               (is_wizard(this_player())? "" : " (" +
                this_player()->query_level() + ")") +
               " with commandline " + this_player()->query_commandline() +
               "\n");
    command("drop all", this_player(), 1);  // ,1 by Coogan, 17-Apr-1999
    if (this_player()->short())
      send_message(({ M_PL_THE,M_PL_VERB,"leave"," the mud." }));
    h = this_player()->query_real_name();  // store the name before quitting
    // remove his equipment file (just in case he has one), he should be
    // naked after a 'quit really'
    unguarded(1,#'rm,"/save/equipment/"+h[0..0]+"/"+h+".o");
    this_player()->quit(1);  // this will destruct the player object after
                             // a final save; argument 1 means: discard
                             // all the equipment, don't move it into the
                             // depot boxes, don't write an equipment .o-
                             // file, but drop it during the destruct of
                             // the player object.
    return 1;
  case "save":
    if (this_player()->query_guest()) {
      notify_fail("Save ignored.\n"
                  "Use 'finalize' to make your character permanent.\n");
      return 0;
    }
    this_player()->save();
    message("Ok. BTW, it normally isn't necessary to type 'save' as this"
            " is automatically done periodically.\n");
    return 1;
  case "finalize":
    if (this_player()->query_guest()) {
      message("To make your character permanent, you need to give a password"
              " for authentication purposes.\n");
      unguarded(1,#'call_other,({ this_player(),"change_password",0 }));
      return 1;
    }
    notify_fail("Your character is already permanent.\n");
    return 0;
  case "persistent":
    // first filter away all invisible or otherwise ill objects:
    args[G_ALL] = filter_objects(args[G_ALL],"short") - ({ 0 });
    // then take the proper number
    h = args[G_ALL][0..args[G_ALL,1][1]-1];
    if (catch(h=({ h,filter(h,lambda(({ 'x }),
                                     ({ #'member,
                                        ([  0, PER_MISS_PERSISTENCE,
                                           -1, PER_NO_PERSISTENCE ]),
                                        ({ #'call_other, 'x, "get_state" })
                                     }))) }))) {
      message("That were too many objects at once. Please choose a smaller"
              " list.\n");
      return 1;
    }
    h[0] -= h[1];
    if (sizeof(h[0]))
      send_message(({ M_WRITE,M_THE,h[0],M_VERB,"are",h[0]," persistent." }));
    h = ({ h[1],filter_objects(h[1],"query_auto_load") });
    h[0] -= h[1];
    if (sizeof(h[1]))
      send_message(({ M_WRITE,M_THE,h[1],M_VERB,"are",h[1]," autoload." }));
    if (sizeof(h[0]))
      send_message(({ M_WRITE,M_THE,h[0],M_VERB,"are",h[0],
                      " neither persistent nor autoload." }));
    return 1;
  case "prompt":  // Alfe 1998-Jul-31
    if (!args[G_TEXT])
      write("Prompt: \"" +
            LIB_STRINGS->quote_string(this_player()->change_prompt(0)) +
            "\"\n");
    else {
      h = args[G_TEXT];
      if (h[0]=='\"' && h[<1]=='\"')
        h = LIB_STRINGS->unquote_string(h[1..<2]);
      write("Old prompt: \"" +
            LIB_STRINGS->quote_string(this_player()->change_prompt(h)) +
            "\"\n");
    }
    return 1;
  default:
    raise_error("Unexpected value\n");
  }
  return 0;  // Coogan, 26-Mar-2011
}

