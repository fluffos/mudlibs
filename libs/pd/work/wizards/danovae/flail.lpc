
#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_id( ({ "whip","flail","velvet flail" }) );
   set_name("velvet flail");
   set_short("%^BOLD%^%^MAGENTA%^velvet flail%^RESET%^");
   set_long(
     "velvet flail"
   );
   set_mass(10);
   set_wc(10);
   set_type("flail");
   set_prevent_get("This isn't yours.");
}

void init() {
   ::init();
   add_action("flog","flog");
}

int flog(string str) {
   object ob;
   if(!str || str=="") {
   notify_fail("Who do you wish to flog?\n");
   return 0;
   }
   ob = present(str, environment(this_player()));
   write("You whip "+ob->query_cap_name()+"'s tender bottom.");
   say(this_player()->query_cap_name()+" whips "+ob->query_cap_name()+"'s tender bottom.");
   ob->force_me("moan");
   ob->force_me("say Please sir, may I have another?");
   return 1;
}



