#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "green snake", "gray snake", "striped snake",
           "red snake" });

 i = random(sizeof(name));
   set_name("snake");
   set_short(name[i]);
   set_level(i+4*2);
   set_race("snake");
   set_body_type("snake");
   set_gender("male");
   set_class("animal");
   set_subclass("fast");
   set_id(({ "snake", name[i] }));
 if (name[i]=="green snake")
   set_long("A green snake. The scales are almost the same color as the "
            "surrounding grass.");
 if (name[i]=="gray snake")
   set_long("The grey snake moves along slowly.");
 if (name[i]=="striped snake")
   set_long("A striped snake with scales of varying brown color.");
 if (name[i]=="red snake")
   set_long("A red snake coiled and waiting.");
}
