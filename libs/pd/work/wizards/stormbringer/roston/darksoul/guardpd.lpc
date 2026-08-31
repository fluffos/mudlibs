#include <std.h>
inherit MONSTER;


void create() {
    ::create();
    set_name("guard");
    set_short("%^BOLD%^%^BLACK%^Dark %^WHITE%^Souls %^BLACK%^"
      "Guardian");
    set_long("\'Nuff said");
    set_id(({"guardian", "dark souls guardian","guard"}));
    set_race("raknid");
    set_alignment(1500);
    set_class("rogue");
    set_subclass("assassin");
    set_level(7000);
    set_skill("murder", 9999);
    set_skill("agility", 9999);
    set_gender("male");
    set_body_type("artrell");
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    new("/wizards/detach/roston/guild/d_knife")->move(this_object()); 
    new("/wizards/detach/roston/guild/d_knife")->move(this_object());
    this_object()->force_me("wield knife");
    this_object()->force_me("wield knife 2");
    this_object()->force_me("wield knife 3");
    this_object()->force_me("wield knife 4");

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

