#include <std.h>
#include <arlon.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("rat");
 if (random(10) > 5)
  {
   set_short("A giant rat");
   set_level(14);
  }
 else 
 { 
   set_short("A tiny rat");
   set_level(8);
 }
   set_race("rat");
   set_body_type("enquine");
   set_gender("male");
   set_id(({ "rat", query_short() }));
   set_long("The rodent seems to be wondering why he has been disturbed.");
}
