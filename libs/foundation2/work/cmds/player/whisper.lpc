//      /cmd//      from the Nightmare mudlib
//      written by Valodin, Feb. 4,  1993
//      modified by Bohemund, Jan. 16 1994

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
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

  if(ob->GetInvis()) {
    notify_fail(capitalize(who) +
                " does not appear to be within whispering distance.\n");
    tell_object(ob, this_player()->GetName() +
                            " is unaware of whispering to you: " + msg);
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail(ob->GetName()+" is link-dead and cannot hear you.\n");
    return 0;
  }
  tell_object(ob, "%^BOLD%^%^CYAN%^"+act_ob->GetName()+
                              " whispers to you: %^RESET%^"+msg);
  write("%^BOLD%^%^CYAN%^You whisper to "+ob->GetName()+": %^RESET%^"+
	msg);
  say("%^CYAN%^"+act_ob->GetName() + " whispers something to " +
      ob->GetName() + ".", ob);
  return 1;
}

void help() {
  write("Syntax: <whisper [player] [message]>\n\n"+
        "This command is used to whisper a message to another " 
        "player who is in the same room as you without other "
        "players being able to hear what you are saying.\n"
        "See also: say, emote, yell\n");
}





