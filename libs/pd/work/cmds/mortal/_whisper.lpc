//      /cmds/mortal/_whisper.c
//      from the Nightmare mudlib
//      written by Valodin, Feb. 4,  1993
//      modified by Bohemund, Jan. 16 1994

#include <std.h>

inherit DAEMON;

int cmd_whisper(string str) {
  string who, msg;
  object ob, act_ob;

  act_ob = previous_object();

  if (!str || sscanf(str, "%s %s", who, msg) != 2)  {
    notify_fail("usage: whisper <player> <message>\n");
    return 0;
  }

  who = lower_case(who);
  ob = find_living(who);
  if(!ob || !living(ob)) {
    notify_fail(capitalize(who) +
                " does not appear to be within whispering distance.\n");
    return 0;
  }

  if(environment(ob) != environment(act_ob)) {
    notify_fail(capitalize(who) +
                " does not appear to be within whispering distance.\n");
    return 0;
  }

  if(ob->query_invis()) {
    notify_fail(capitalize(who) +
                " does not appear to be within whispering distance.\n");
    message("whisper", this_player()->query_cap_name() +
                            " is unaware of whispering to you: " + msg, ob);
    return 1;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail(ob->query_cap_name()+" is link-dead and cannot hear you.\n");
    return 0;
  }
  message("whisper", act_ob->query_cap_name()+
                              " whispers to you: "+msg, ob);
  message("whisper", "You whisper to "+ob->query_cap_name()+": "+
	msg, this_player());
  message("whisper", ""+act_ob->query_cap_name() + " whispers something to " +
      ob->query_cap_name() + ".", environment(ob), ({ ob, act_ob }) );
  return 1;
}

void help() {
  write("Syntax: <whisper [player] [message]>\n\n"+
        "This command is used to whisper a message to another " 
        "player who is in the same room as you without other "
        "players being able to hear what you are saying.\n"
        "See also: say, emote, yell\n");
}





