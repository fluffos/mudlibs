//      _give.c
//      Mostly the _give.c from the TMI distribution mudlib.
//      Written by Sulam 12.12.91
//      Help added 1.28.92 by Brian
//      Fixed for the Nightmare monetary system by Descartes of Borg 
//      31 October 1992
// Light checking added by Hanse 4/11/92  :P
#include "move.h"
#include <daemons.h>
#include <std.h>
inherit DAEMON;
int help();
int cmd_give(string str) {
   object ob, to;
   string what, who, type;
   int i, amount;
    int dummy;
//    object *inv;
   
    if (!stringp(str)) return help();
    dummy = total_light(this_player());
    if(dummy < -6) {
      write("It is too dark.\n");
      return 1;
    }
    if (sscanf(str,"%s to %s", what, who) != 2) {
        return help();
    }
    if(who == "me" || who == "myself") {
        who = this_player()->query_name();
    }
    to = present(who, environment(this_player()));
    if (!to) {
      notify_fail("Give "+what+" to who?\n");
      return 0;
    }
    ob = present(what, this_player());
    if (ob)
    if (ob->give(what))
        return 1;
    if (!ob) {
        ob = parse_objects(this_player(), what);
    }
    if(!ob) 
    {
 
        if(sscanf(what, "%d %s coin", amount, type) !=2) 
        {
            return notify_fail("You must have an object to give it away!\n");
        }
          // wiz fixed this, you were able to give 0 coins to people
        if (amount<1) 
        {
            return notify_fail("Please enter a valid amount.\n");
        }
        
        if(amount > (int)this_player()->query_money(type)) 
        {
            return notify_fail("You don't have that much!\n");
        }
        
        if(query_ip_number(this_player()) == query_ip_number(to) && 
                this_player()->query_name() != to->query_name() ) 
        {         
                CHAT_D->do_raw_chat("system", "Multi <system> Exchange of money between "+this_player()->query_name()+" and "+to->query_name());
                seteuid("Log");
                log_file("multiplay", "Exchange of money ("+amount+" "+type+") between "+this_player()->query_name()+" and "+to->query_name()+" from "+query_ip_number(this_player())+". (give)\n");
                seteuid(getuid());
        }
           
        this_player()->add_money(type, -amount);
        to->add_money(type, amount);
        // this line makes it harder to steal from people/mobs if you give them stuff:
        this_player()->add_stolen(to, 2);
        write("You give " + amount + " " + type + " coins to " +
            to->query_cap_name() + ".\n");
        message("no_wrap",this_player()->query_cap_name()+ " gives some money to " 
            + to->query_cap_name() + ".\n", environment(this_player()),({ this_player(), to }));
            tell_object(to, this_player()->query_cap_name() +
            " gives you " + amount + " " + type + " coins.\n");
        return 1;
    }

    if (!living(to)) {
        return notify_fail("Only living objects can accept items.\n");
    }
    if(to->query_ghost()) {
        return notify_fail(to->query_cap_name()+" is unable to hold anything in that state!\n");
    }
    if(!ob->get()) {
        return notify_fail("You cannot give that away!\n");
    }
    i = (int) ob->move(to);
    switch(i) {
        case MOVE_OK: {
            // this line makes it harder to steal from people/mobs if you give them stuff:
            this_player()->add_stolen(to, 2);
            write("You give " + ob->query_short() + " to " +to->query_cap_name() + ".\n");
            say(this_player()->query_cap_name()+" gives "+ob->query_short()+" to " + to->query_cap_name() + ".\n", to);
            message("no_wrap",this_player()->query_cap_name()+" gives you "+ob->query_short() + ".\n", to);
            return 1;
            }
        case MOVE_NO_ROOM: {
            return notify_fail(to->query_short()+" can't carry any more.\n");
            }
        default: {
            return notify_fail("Oops, can't do that.\n");
        }
    }
}
int help() {
  write("Command: give\nSyntax: give <item> to <player>\n"+
        "This command will make you give an item in your inventory\n"+
        "to the player specified.  You must be in the same room for\n"+
        "this to occur.\n");
  return 1;
}
