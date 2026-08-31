#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Dwarven War Mage");

set_short("%^BOLD%^%^BLUE%^D%^RED%^w%^BLUE%^a%^RED%^r%^BLUE%^v%^RED%^e%^BLUE%^n "
"%^BOLD%^%^BLACK%^W%^RED%^a%^BLACK%^r "
"%^BOLD%^%^BLUE%^M%^RESET%^%^ORANGE%^a%^BOLD%^%^BLUE%^g%^RESET%^%^ORANGE%^e%^RESET%^");
    set_long("This war mage has a intense look in his eyes he has "
    "been waiting to fight the drows for a long time. He stands watin "
    "for the word to invade.");
    set_id(({"mage", "dwarven war mage"}));
    set_race("dwarf");
    set("aggressive", 40);
    set_class("mage");
    set_subclass("druid");
    set_spell_chance(40);
    set_spells(({"lash","bolt"}));
    set_skill("knife", 220);
    set_level(63);
    set_exp(820000);
    set_body_type("human");
    set_gender("male");
    set_emotes(10,
       ({"%^CYAN%^Dwarf says:%^RESET%^ Those Drows will pay for coming to Roston.",
        }),
        0);    
    new("/wizards/detach/roston/war/boots")->move(this_object());
    new("/wizards/detach/roston/war/armour")->move(this_object());
    new("/wizards/detach/roston/war/knife")->move(this_object()); 


    set_heart_beat(1);
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
    this_object()->force_me("wear armour");
    this_object()->force_me("wield dagger");
    this_object()->force_me("wear boots");
    wielded_sword = 1;
   }
}
