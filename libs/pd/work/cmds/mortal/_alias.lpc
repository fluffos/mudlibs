
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

string format_alias(string, string);
void display_alias(string, string);
void reset_aliases();

void help() {
  message("help",
    "Syntax: <alias>\n"
    "        <alias -reset>\n"
    "        <alias -clear>\n"
    "        <alias [short]>\n"
    "        <alias [short] [command]>\n"
    "        <unalias [short]>\n\n"
    "Aliases let you set up a short form of a command. Some examples:\n\n"
    "\talias hi say Hi there!\n"
    "\tNow you can type \"hi\" to greet people.\n\n"
    "\talias bs backstab $1\n"
    "\tYou can use $1 - $9 to refer to a certain word after the short command.\n"
    "\tThis lets you type \"bs goblin\" to attack things.\n\n"
    "\talias bs backstab $*\n"
    "\tUsing $* refers to all the words after the short command.\n"
    "\tThis one lets you do \"bs goblin 2\", which is much more useful.\n\n"
    "\talias $- newbie $*\n"
    "\tPutting a $ in front of the short command lets you start a line with it.\n"
    "\tWith this alias, \"-hello there\" will make you talk on the newbie line.\n\n"
    "The -clear option will remove all your aliases.\n"
    "The -reset option will first do -clear, then put the defaults back in.\n"
    "Using the alias command with no arguments will display all your aliases. "
    "Using only one argument will display the alias by that name. "
    "The unalias command will remove a single alias.\n\n"
    "See also: nickname, history",
    this_player() );
}

varargs int cmd_alias(string str, int silent) {
  object tp = this_player();
  mapping aliases;
  string *sort;
  string msg = "";
  string verb, arg;

  aliases = tp->query_aliases();

  // display all aliases
  if (nullp(str) || !str) {

    if (!mapp(aliases))
      FAIL("An error occurred with your aliases, please contact a staff member.");
    else if (!aliases || !sizeof(aliases))
      FAIL("No aliases defined.");
    else {
      sort = sort_array(keys(aliases), 1);
      sort = map(sort, (: format_alias($1, $2[$1]) :), aliases);
      tp->more(sort, "info");
    }
  }

  else {

    // check for options:
    switch(str) {

      // reset aliases
      case "-reset":
        tp->clear_aliases();
        reset_aliases();
        msg = "Default aliases restored.";
      break;

      // clear aliases
      case "-clear":
        tp->clear_aliases();
        msg = "All aliases removed.";
      break;

      default:

        // add or redefine an alias
        if (sscanf(str, "%s %s", verb, arg) == 2) {

          if (verb == "alias")
            FAIL("You may not alias the 'alias' command.");
          
          msg = "Alias "+verb+" ("+arg+") ";
          if (!aliases[verb])
            msg += "added.";
          else
            msg += "altered.";
          tp->add_alias(verb, arg);
        }

        // display a specific alias
        else {
          if (!aliases[str])
            msg = "Alias '"+str+"' not found.";
          else
            display_alias(str, aliases[str]);
        }
    }
  }

  if (nullp(silent) || !silent) {
    if (strlen(msg))
      message("info", msg, tp);
  }

  return 1;
}

string format_alias(string short, string command) {
  return sprintf("%-15s: %-60s", short, command);
}

void display_alias(string short, string command) {
  message("info", format_alias(short, command), this_player() );
}

void reset_aliases() {
  cmd_alias("i inventory $*",1);
  cmd_alias("eq equipment $*", 1);
  cmd_alias("l look $*",1);
  cmd_alias("$' say $*",1);
  cmd_alias("$\" say $*",1);
  cmd_alias("$: emote $*",1);
  cmd_alias("bio biography",1);
  cmd_alias("sc score",1);
  cmd_alias("sk skills",1);
  cmd_alias("sp spells",1);
  cmd_alias("abil abilities", 1);
  cmd_alias("con consider $*",1);
  cmd_alias("sac sacrifice $*",1);
  cmd_alias("e east", 1);
  cmd_alias("w west", 1);
  cmd_alias("n north", 1);
  cmd_alias("s south", 1);
  cmd_alias("u up", 1);
  cmd_alias("d down", 1);
  cmd_alias("ne northeast", 1);
  cmd_alias("nw northwest", 1);
  cmd_alias("sw southwest", 1);
  cmd_alias("se southeast", 1);
}

