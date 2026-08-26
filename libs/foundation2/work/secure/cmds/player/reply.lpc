//     /bin/user/_reply.c
//     from the Nightmare mudlib
//     replies to the person who previously told to you
//     created by Descartes of Borg 06 february 1993
 
#include <lib.h>
#include <daemons.h>
 
inherit LIB_DAEMON;
 
int cmd(string str) {
    string reply, a, b;
    object ob;
 
    reply = (string)this_player()->GetProperty("reply");
    if(!reply) reply = "no one";
    if(!str) {
       notify_fail("Current reply addressee: "+capitalize(reply)+"\n");
       return 0;
    }
    if(reply == "no one") {
       notify_fail("No current reply addressee.\n");
       return 0;
    }
    ob = find_living(reply);
    if(!ob && (sscanf(reply, "%s@%s", a, b) != 2)) {
       notify_fail(capitalize(reply)+" is not currently in our reality.\n");
       return 0;
    }
    if(sscanf(reply, "%s@%s", a, b) == 2) {
        a = lower_case(a);
	SERVICES_D->eventSendTell(a, b, str);
	return 1;
    }
    if(ob->GetInvis()) 
      reply = "someone";
 
    if(!interactive(ob) && userp(ob)) {
        notify_fail(ob->GetName()+" is link-dead and cannot hear "
                    "you.\n");
        return 0;
    }
    message("tell", (string)this_player()->GetName()+" replies: "+
      str, ob);
    message("tell", sprintf("You reply to %s: %s",
      (string)ob->GetName(), str), this_player());
    ob->SetProperty("reply", this_player()->GetKeyName());
    return 1;
}
 
void help() {
    message("help",
      "Syntax: <reply [(message)]>\n\n"
      "With a message, it replies to the person who last told or replied "
      "to you.  Without a message, it shows who the current object of "
      "your reply would be.\n\nSee also: "
      "finger, idle, muds, say, shout, tell, yell", this_player()
    );
}
