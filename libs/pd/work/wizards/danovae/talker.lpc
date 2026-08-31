
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("Lucsator");
   set_id( ({"lucsator","priest","cleric"}) );
   set_short("Initiator Priest, Lucsator");
   set_long(
     "Lucsator"
   );
   set_class("clergy");
   set_subclass("cleric");
   set_level(20);
   set_gender("male");
   set_race("human");
   set_body_type("human");
}

void init() {
   ::init();
   if(this_player()->query_class() == "child") {
   call_out("talker",3);
   }
}

void talker() {
   force_me("say Hello "+this_player()->query_cap_name()+", would you be interested in joining the children of the gods?");
   remove_call_out("talker");
}

void catch_tell(string str) {
   string a,b;
   if(this_player()->query_class() != "child") {
   return 0;
   }

   if(sscanf(str, "%syes%s", a, b) == 2) {
      write("Lucsator places a hand on your shoulder\n");
      write("%^CYAN%^Lucsator says:%^RESET%^ Welcome to the church my child.\n");
      this_player()->set_class("clergy");
   return;
   }
}




