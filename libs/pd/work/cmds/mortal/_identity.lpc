#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)
#define SYNTAX FAIL("See <help identity> for syntax.")
#define tp this_player()

inherit DAEMON;

void help() {
  message("help",
    "The identity manager keeps track of your characters, email address, "
    "LANs, and connections. It works automatically at login and you can use "
    "the following commands:\n"
    "\n"
    "Syntax: <identity show>\n"
    "\n"
    "This will display your identity information, including email address, "
    "alternate characters, and LANs.\n"
    "\n"
    "        <identity email [email address]>\n"
    "\n"
    "This will change the email address registered with your identity.\n"
    "Note that this is only visible to immortals, not other players.\n"
    "\n"
    "        <identity primary [character]>\n"
    "\n"
    "This will set an alternate character to be your primary.\n"
    "\n"
    "See also: lan",
    tp);
  if (wizardp(tp))
  message("help",
    "\n"
    "Immortal only commands:\n"
    "\n"
    "        <identity show [player]>\n"
    "\n"
    "Shows identity information for the named player.\n"
    "\n"
    "        <identity add [primary] [alternate]>\n"
    "        <identity remove [primary] [alternate]>\n"
    "\n"
    "Adds or removes an alternate character to a player's identity.\n"
    "\n"
    "        <identity merge [primary] [alternate]>\n"
    "\n"
    "Merges the first identity into the second, and deletes the first one.\n"
    "\n"
    "        <identity set [player] [setting] [value]>\n"
    "\n"
    "Changes the value of a setting. Available settings:\n"
    "gag - on, off, or number of seconds (gag 600)\n"
    "exp - percentage of exp to gain (exp 105)\n",
    tp);
}

int cmd_identity(string str) {
  string cmd, args, func;

  if (!str)
    SYNTAX;

  if (sscanf(str, "%s %s", cmd, args) != 2)
    cmd = str;

  func = "cmd_identity_"+cmd;

  if (!function_exists(func, this_object()))
    SYNTAX;


  return call_other(this_object(), func, args);
}

int cmd_identity_show(string args) {
  string who, msg;
  mixed chars, lans, conns, settings, tmp;

  if (args && wizardp(tp))
    who = args;
  else
    who = tp->query_primary_char() || tp->query_name();

  if (!IDENTITY_D->query_identity(who))
    who = IDENTITY_D->query_primary(who);

  if (!who)
    FAIL("Could not find any identity information.");

  chars = IDENTITY_D->query_characters(who);
  chars -= ({ who });
  if (sizeof(chars)) {
    chars = sort_array(chars, 1);
    chars = list(map(chars, (: capitalize($1) :)), 0, "" );
    chars = wrap(chars, 75);
    chars = chars[0..<2];
    chars = "   "+replace_string(chars, "\n", "\n   ");
  }
  else {
    chars = "   none";
  }

  lans = IDENTITY_D->query_lans(who);
  if (sizeof(lans)) {
    lans = sort_array(lans, 1);
    lans = list(lans, 0, "");
  }
  else {
    lans = "none";
  }

  msg =
    header_line("Identity") + "\n"+
    " Primary Character: " + capitalize(who) + "\n"+
    header_line() + "\n"+
    " Alternate Characters:" + "\n"+
    chars + "\n\n"+
    " Email address: " + IDENTITY_D->query_email(who) + "\n\n"+
    " LANs: " + lans + "\n"+
    header_line()
  ;

  if (wizardp(tp)) {
    settings = IDENTITY_D->query_settings(who);
    if (!settings || !mapp(settings) || !sizeof(settings))
      tmp = "none";
    else {
      tmp = values(map(settings, (: capitalize($1)+": "+$2 :)));
      tmp = list(tmp, 0, "");
    }
    msg +=
      "\n"+
      " Settings:" + "\n"+
      "   " + tmp + "\n"+
      header_line()
    ;
  }

  conns = IDENTITY_D->query_connections(who);
  if (conns && sizeof(conns)) {
    conns = sort_array(conns, (:
      $1[2] > $2[2] ? 1 : ($1[2] < $2[2] ? -1 : 0)
    :) );
    conns = conns[<5..<1];
    msg +=
      "\n"+
      " Last five connections:" + "\n"
    ;
    foreach (mixed *conn in conns) {
      string char = conn[0];
      string ip = conn[1];
      int time = conn[2];
      msg +=
        "   "+capitalize(char)+" from "+ip+" at "+ctime(time)+"\n"
      ;
    }
    msg += header_line();
  }

  message("info", msg, tp);

  return 1;
}

int cmd_identity_email(string args) {
  string who = tp->query_primary_char() || tp->query_name();

  if (!IDENTITY_D->query_identity(who))
    who = IDENTITY_D->query_primary(who);

  if (!who)
    FAIL("Could not find any identity information.");

  IDENTITY_D->change_email(who, args);

  message("info", "Changed email address to: "+args, tp);

  return 1;
}

int cmd_identity_primary(string args) {
  string who = tp->query_primary_char() || tp->query_name();

  if (!IDENTITY_D->query_identity(who))
    who = IDENTITY_D->query_primary(who);

  if (!who)
    FAIL("Could not find any identity information.");

  if (member_array(args, IDENTITY_D->query_characters(who)) == -1)
    FAIL(
      "The character "+capitalize(args)+
      " is not registered as your alternate.\n"
      "If this is your character, you must login with it to register it."
    );

  IDENTITY_D->transfer_identity(who, args);

  message("info", "Changed your primary character to "+capitalize(args)+".", tp);

  return 1;
}

int cmd_identity_add(string args) {
  string pri, alt;
  if (!wizardp(tp)) SYNTAX;

  if (sscanf(args, "%s %s", pri, alt) != 2)
    SYNTAX;

  if (!IDENTITY_D->query_identity(pri))
    pri = IDENTITY_D->query_primary(pri);

  if (!pri)
    FAIL("Could not find any identity information.");

  IDENTITY_D->add_character(pri, alt);

  message("info", "Added "+alt+" as an alternate character of "+pri+".", tp);

  return 1;
}

int cmd_identity_remove(string args) {
  string pri, alt;
  if (!wizardp(tp)) SYNTAX;

  if (sscanf(args, "%s %s", pri, alt) != 2)
    SYNTAX;

  if (!IDENTITY_D->query_identity(pri))
    pri = IDENTITY_D->query_primary(pri);

  if (!pri)
    FAIL("Could not find any identity information.");

  IDENTITY_D->delete_character(pri, alt);

  message("info", "Deleted "+alt+" as an alternate character of "+pri+".", tp);

  return 1;
}

int cmd_identity_merge(string args) {
  string one, two;
  string *conns;
  if (!wizardp(tp)) SYNTAX;

  if (sscanf(args, "%s %s", one, two) != 2)
    SYNTAX;

  if (!IDENTITY_D->query_identity(one))
    FAIL("Could not find any identity information for "+one+".");

  if (!IDENTITY_D->query_identity(two))
    FAIL("Could not find any identity information for "+two+".");

  if (one == two ||
      IDENTITY_D->query_identity(one) == IDENTITY_D->query_identity(two))
        FAIL("They are already the same identity!");

  IDENTITY_D->transfer_identity(one, two);
  IDENTITY_D->delete_identity(one, 1);

  message("info", "Merged identity of "+one+" into "+two+".", tp);

  return 1;
}

int cmd_identity_set(string args) {
  string pri, setting;
  mixed value;
  int intval;
  if (!wizardp(tp)) SYNTAX;

  if (sscanf(args, "%s %s %s", pri, setting, value) != 3)
    SYNTAX;

  if (!IDENTITY_D->query_identity(pri))
    pri = IDENTITY_D->query_primary(pri);

  if (!pri)
    FAIL("Could not find any identity information.");

  switch (setting) {
    case "gag":
      intval = to_int(value);
      if (intval) value = intval;
      else if (value != "on" && value != "off")
        FAIL("Gag settings: on, off, or number of seconds.");
    break;
    case "exp":
      intval = to_int(value);
      if (intval) value = intval;
      else
        FAIL("Exp settings: percentage of normal (100 is normal).");
    break;
  }

  IDENTITY_D->add_setting(pri, setting, value);

  message("info", "Setting changed for "+pri+": "+
    setting+" to "+value+".", tp);

  return 1;
}

