#include <mudlib.h>
inherit MONSTER ;


void create () {
  ::create();
  seteuid(getuid());
  set("short", "");
   set ("long", @Foo
You have stumbled into the lair of the Shadow Demon, and he is NOT
happy that you are here. You can't see him at all, but every once
in a while you catch enough of a glimpse to see what shape he is in.
Legend says that he can be killed, but it won't be easy.

Foo
);
  set("id", ({ "demon" , "shadow" }) );
  set_level(20);
  set_size(10);
  set_name("shadow demon");
  set("aggressive", 50);
  set_living_name("demon");
  set("gender" , "neuter");
  set("race", "shadow");
   set("undead", 1);
  set("damage", ({ 10,15 }) );
  set("weapon_name", "shadowy fists");
   set_verbs( ({ "smack", "uppercut" }) );
   set_verbs2( ({ "smacks", "uppercuts" }) );
   set("natt", 1);
}
