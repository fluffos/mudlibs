#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("killer");
    set_short("Leviathas Killer");
    set_long("I was made for killin leviathas that pice of sorry "
"worthless bottem feeding trash bag whiner.");
    set_id(({"killer", "leviathas killer","killer"}));
    set_race("artrell");
    set_alignment(1500);
    set_class("rogue");
    set_subclass("assassin");
    set_level(7000);
    set_skill("murder", 99999);
    set_spell_chance(100);
    set_spells( ({"backstab"}) );
    set_body_type("artrell");
    set_gender("male");
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    new("/wizards/detach/azeria/obj/8")->move(this_object());
    new("/wizards/detach/azeria/obj/8")->move(this_object()); 
    new("/wizards/detach/azeria/obj/8")->move(this_object());
    this_object()->force_me("wield knife");
    this_object()->force_me("wield dagger");
    this_object()->force_me("wield dagger 2");
    this_object()->force_me("wield dagger 3");

  //  set_heart_beat(1);
}                                             
void init()   
{
 ::init();
 if (this_player()->query_name()=="leviathas")
   {
    this_object()->force_me("say Die You Fucking Whineing Pice of Shit!");
    this_object()->force_me("backstab "+this_player()->query_name());

   }
}
