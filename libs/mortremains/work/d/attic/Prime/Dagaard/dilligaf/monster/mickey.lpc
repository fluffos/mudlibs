#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
  set("no_attack" , 1);
  set("short" , "Mickey");
  set("long" , @EndText
  Its Mickey, he owns the place. His intense stare gives you the 
  impression that hes not someone to be trifled with. Also the glow
  that surrounds him make you think that he is impervious to your
  attacks of any kind.

EndText
);
  set("id" , ({ "mickey" , "bartender" }) );
  set_level(1);
  set_size(6);
  set_name("mickey");
  set_living_name("mickey");
  set("gender" , "male");
  set("race" , "Sasquash");
}

void init() {
  command("say Welcome to Mickeys!");
 }
