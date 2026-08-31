#include <std.h>
#include <lodos.h>
inherit MONSTER;

int die_weed();

void create() {
 ::create();
   set_short("a large weed");
   set_id(({ "weed", "plant", "large weed" }));
   set_name("weed");
   set_level(24);
   set_long("The large, living weed has its roots barely planted "
     "into the ground. It's razor sharp vines flick threateningly "
     "through the air.");
   set_body_type("bladedplant");
   set_race("weed");
   set_alignment(420);
   set_die( (: die_weed() :) );
}

int die_weed() {
   message("info", "The dried roots of the weed rip out of the ground "
     "as it dies.", environment(this_object()));
   new(OBJ"weed2")->move(environment(this_object()));
   return 1;
}

