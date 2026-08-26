//  /cmds/std/_smell.c
//  Allows a player to smell a room, or smell items in a room.
// (03-26-95) Chronos modified it to allow living objects to be smelt with.
//            (ha - ha)
// (04-04-98) Chronos ports the code to the new mudlib.

#include <mudlib.h>

inherit DAEMON;

#define FAIL_MSG "You smell nothing out of the ordinary.\n"

int
cmd_smell(string str) {
  mixed smell_prop;
  string * to_smell;
  object ob;

  if (!str) {
    say(TPN + " sniffs the air inquisitively.\n");
    smell_prop = environment(TP)->query("smell/default");
    if (!smell_prop) write("You smell nothing out of the ordinary.\n");
    else write(smell_prop);
   return 1;
  }
  str = lower_case(str);
  if (str == this_player()->query("name")) str = "me" ;
  if (str == "me") {
    write("You smell yourself.\n");
    smell_prop = TP->query("smell");
    if (!smell_prop) write(FAIL_MSG);
   else write(smell_prop+"\n");
    message("smelling", TPN+" smells "+
   objective(TP->query("gender"))+"self.\n", environment(TP),
   ({ TP }) );
   return 1;
  }
  ob = present(str, TP);
  if (!ob) ob = present(str, environment(TP)) ;
  if (!visible(ob, TP)) ob = 0 ;
  if (ob) {
    write("You smell "+ob->query("short")+".\n");
    say(TPN+" smells "+ob->query("short")+".\n");
    smell_prop = ob->query("smell");
    if (!smell_prop) write(FAIL_MSG);
    else write(smell_prop + "\n");
    return 1;
  }
  ob = find_living(str);
  if (ob) {
   if (environment(TP) == environment(ob)) {
   smell_prop = (string)ob->query("smell");
   message("sniffing", TPN + " sniffs the air around "+ob->query("cap_name")+
    ".\n", environment(TP), ({ ob, TP }) );
   write("You sniff the air around "+ob->query("cap_name")+".\n");
   tell_object(ob, TPN + " sniffs the air around you.\n");
   if (!smell_prop) write("You smell nothing in particular.\n");
   else write(smell_prop +"\n");
   return 1;
   } else {
     write("They aren't here for you to smell.\n");
     return 1;
  }
  }
   smell_prop = environment(this_player())->query("smell");

    notify_fail(FAIL_MSG);

// If the room has no smell set, this should fail.  Likewise if "smell" is
//   not a string or mapping.

    if(!smell_prop || (!stringp(smell_prop) && !mapp(smell_prop))) return 0;
    
// If "smell" is a mapping, it should be treated like this.

    if(mapp(smell_prop)) {
        to_smell = keys(smell_prop);
        if(!str) str = "default";
        if(member_array(str, to_smell) == -1) return 0;
        write(smell_prop[str]);
        return 1;
    }

// If "smell" is a string, trying to smell something in particular fails.

    if(str) return 0;
    write(smell_prop);
    return 1;
}

string help() {
  return @EndHelp

Usage: smell
       smell <something>

This will allow you to smell the room, or smell items in a room.

EndHelp
;
}
