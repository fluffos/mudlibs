#include <mudlib.h>
inherit MONSTER ;

object axe;

void create () {
  ::create();
  seteuid(getuid());
  set("short", "a ghost");
   set ("long", @Foo
This is a lost soul, wandering the earth and searching for freedom
from torment. It is translucent and tough to spot.

Foo
);
  set("id", ({ "ghost" }) );
  set_level(1);
  set("aggressive" , 50);
  set_size(3);
  set_name("a ghost");
  set_living_name("ghost");
  set("gender" , "neuter");
  set("race", "ghost");
   set("undead", 1);
   set("damage", ({ 1,4 }) );
  set("weapon_name", "ghostly fists");
   set_verbs( ({ "smack", "uppercut" }) );
   set_verbs2( ({ "smacks", "uppercuts" }) );
   enable_commands() ;
   set("natt", 1);
   set ("chat_chance", 10);
   set ("chat_output", ({
   }) );
   set ("att_chat_output", ({
   }) );
}
