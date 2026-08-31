#include <std.h>
#include <defs.h>
#include <rest.h>

inherit DAEMON;

int cmd_rest() {

    if(this_player()->query_current_attacker())
       return notify_fail("You cannot lay down in battle.\n");
    if (this_player()->query_rest_type() == REST ) 
      return notify_fail("You are already resting.\n");

   if(this_player()->query_mounting())
      this_player()->force_me("dismount "+this_player()->query_mounting()->query_name());
   if(this_player()->query_riding())
      this_player()->force_me("dismount");
          write("You lay down to rest.");
       this_player()->set_rest_type( REST );
       say(capitalize(this_player()->query_cap_name())+" lays down to rest.");
       call_out("htimer", 30);
       return 1;
}

 


int help() {
    write(
      "Syntax: <rest>\n"
      "\nSomeone who is resting will regain their lost health.\n"
    );
    return 1;
}
