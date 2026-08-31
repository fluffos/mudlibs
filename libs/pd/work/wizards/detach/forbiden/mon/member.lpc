#include <std.h>
inherit MONSTER;
void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "member", "a member of the wolf pack", "wolf pack member",
           "old man", "elite member"});

 i = random(sizeof(name));
   set_name("member");
   set_short(name[i]);
   set_level(i+42);
   set("aggressive", (i+25) );
   set_race("elf");
   set_body_type("elf");
   set_gender("male");
   new("/wizards/detach/forbiden/obj/skull")->move(this_object());
   new("/wizards/detach/forbiden/obj/cutlass")->move(this_object()); 
   new("/wizards/detach/forbiden/obj/cutlass")->move(this_object());  
   this_object()->force_me("wear skull");
   this_object()->force_me("wield cutlass");
   this_object()->force_me("wield cutlass 2");
   set_id(({ "member", name[i] }));
   set_long("A member of the Wolf Pack, an very old wise fighter..");

}

