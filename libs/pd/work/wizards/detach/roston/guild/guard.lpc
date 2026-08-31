#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("guard");
    set_short("%^BOLD%^%^BLACK%^Dark %^WHITE%^Souls %^BLACK%^"
              "Guardian");
    set_long("'Nuff said");
    set_id(({"guardian", "dark souls guardian","guard"}));
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
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    new("/wizards/detach/roston/guild/d_knife")->move(this_object()); 
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    this_object()->force_me("wield knife");
    this_object()->force_me("wield knife 2");
    this_object()->force_me("wield knife 3");
    this_object()->force_me("wield knife 4");

  //  set_heart_beat(1);
}                                             
void init()   
{
 ::init();
 if (this_player()->query_guild()!="darksoul")
   {
    this_object()->force_me("say Trespassor! You will pay for this!");
    this_object()->force_me("backstab "+this_player()->query_name());

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
