#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "Wolf Hunter", "Wolverine Hunter", "Deer Hunter",
           "Gorilla Hunter", "Huge  Hunter", " Hunter",
           "Grunt Hunter", "Snake Hunter", "Bear Hunter"});

 i = random(sizeof(name));
   set_name("Hunter");
   set_short(name[i]);
   set_level(i+40);
   set("aggressive", (i+25) );
   set_race("elf");
   set_body_type("elf");
   set_gender("male");
  new("/wizards/detach/azeria/obj/a8")->move(this_object());
  new("/wizards/detach/azeria/obj/a9")->move(this_object()); 
  new("/wizards/detach/azeria/obj/1")->move(this_object());
  new("/wizards/detach/azeria/obj/1")->move(this_object());  
  set_id(({ "wolverine", name[i] }));
   set_long("This  Wolverine is one of the many mystical bear's "
"of the forbiden forest.");
}
                                           
void init()   
{
 ::init();
}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wear cloak");
    this_object()->force_me("wear boots");
    this_object()->force_me("wield pike");
    this_object()->force_me("wield pike 2");
    wielded_sword = 1;
   }
}
