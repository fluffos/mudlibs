#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
  set("no_attack" , 1);
  set("short" , "Jerry");
  set("long" , @EndText
  Its Jerry! One of the most popular bartenders of all time. Master
  of the 2000 flushes drink(tm) and beer-slinger. His longish grey
  hair reminds you of an ex-WWF wrestler, but his happy face reminds
  you of a kind, happy man.

EndText
);
  set("id" , ({ "jerry" , "bartender" }) );
  set_level(1);
  set_size(6);
  set_name("jerry");
  set_living_name("mickey");
  set("gender" , "male");
  set("race" , "human");
}

void init() {
  command("say Welcome to the Viper Lounge!");
 }
