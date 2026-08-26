#include <mudlib.h>
inherit MONSTER ;

object axe;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a wraith");
  set("long" , @End
You can barely make out the figure before you. The red coal-like
eyes stare at you and you begin to feel a little queasy from it.
Long gangly finger arc out at you, and the venomous fingernails
look as if they carry as much disease as a pack of sewer rats.

End
);
  set("id", ({ "wraith" }) );
  set("wealth" , 10000);
  set_level(25);
  set("armor_class" , -5);
  set_size(6);
  set_name("a wraith");
  set_living_name("wraith");
  set("gender" , "neuter");
  set("race" , "wraith");
  set("aggressive" , 9);
   set("undead", 1);
  set("damage",({ 2,6 }) );
  set("weapon_name" , "fists" );
  set_verbs( ({ "touch" , "smack" }) );
  set_verbs2( ({ "touches" , "smacks" }) );
   set("natt", 1);
}

