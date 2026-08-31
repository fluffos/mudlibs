#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("scimitar");
   set_short("a dancing scimitar");
   set_long("The magically animated scimitar bobs merrily around in the air, "
     "even turning a somersault every now and then. The scimitar gloats around "
     "in the air, swinging at invisible foes.");
   set_level(45);
   set_id(({ "scimitar", "dancing scimitar", "sword" }));
   set_auto(10);
   set_race("sword");
   set_body_type("blob");
}

int die() {
   message("info", "The life exits the scimitar's form and it drops to the "
     "ground.", environment(this_object()));
   new(WEA"scimitar")->move(environment(this_object()));
   this_object()->remove();
   return 1;
}
