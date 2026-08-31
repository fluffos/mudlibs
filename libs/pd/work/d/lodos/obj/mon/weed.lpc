#include <std.h>
#include <lodos.h>
inherit MONSTER;

int die_weed();

void create() {
 ::create();
   set_short("a living weed");
   set_id(({ "weed", "plant", "living weed" }));
   set_name("weed");
   set_level(27);
   set_long("The large, living weed has its roots in the ground "
     "near the creek. It's long, blade-like vines lash at the air "
     "in front of you.");
   set_body_type("bladedplant");
   set_race("weed");
   set_alignment(420);
   set_die( (: die_weed() :) );
}

int die_weed() {
   message("info", "The dried roots of the weed rip out of the ground "
     "as it dies.", environment(this_object()));
   new(OBJ"weed2")->move(environment(this_object()));
   new(OBJ"weed2")->move(environment(this_object()));
   new(OBJ"weed2")->move(environment(this_object()));
   return 1;
}

