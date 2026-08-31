#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("protector");
    set_short("Protector");
    set_long("The generals protecter.");
    set_id(({"guardian", "dark souls guardian","guard"}));
    set_race("artrell");
    set_alignment(1500);
    set_class("fighter");
    set_subclass("knight");
    set_level(70);
    set_stats("strength", 200);
    set_spell_chance(100);
    set_spells( ({"stun"}) );
    set_body_type("artrell");
    set_gender("male");
    new("/wizards/detach/roston/drow/obj/sword")->move(this_object());
    new("/wizards/detach/roston/drow/obj/sword")->move(this_object());
    new("/wizards/detach/roston/drow/obj/sword")->move(this_object()); 
    new("/wizards/detach/roston/drow/obj/sword")->move(this_object());
    this_object()->force_me("wield sword");
    this_object()->force_me("wield sword 2");
    this_object()->force_me("wield sword 3");
    this_object()->force_me("wield sword 4");

  //  set_heart_beat(1);
}                                             
void init()   
{
 ::init();
 if (this_player()->query_race()!="drow")
   {
    this_object()->force_me("say Trespassor! You will pay for this!");
    this_object()->force_me("stun "+this_player()->query_name());

   }
}
/*
void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wield knife");
    this_object()->force_me("wield knife 2");
    this_object()->force_me("wield knife 3");
    this_object()->force_me("wield knife 4");
    wielded_sword = 1;
   }
}
*/
