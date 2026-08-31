#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("Wolf Master");
    set_short("%^BOLD%^%^WHITE%^W%^GREEN%^o%^BOLD%^%^WHITE%^l%^GREEN%^f %^BOLD%^%^WHITE%^M%^GREEN%^a%^BOLD%^%^WHITE%^s%^GREEN%^t%^BOLD%^%^WHITE%^e%^GREEN%^r");
    set_long("The Wolf Master is the ruler of the forbidden forest, he has control over all wolfs of the land.");
    set_id(({"master", "wolf master"}));
    set_race("elf");
    set("aggressive", 50);
    set_class("fighter");
    set_subclass("ranger");
    set_spell_chance(60);
    set_spells(({"slash","rush"})); 
    set_level(62);
    set_body_type("elf");
    set_gender("male");
    new("/wizards/detach/forbiden/obj/skull")->move(this_object());
    new("/wizards/detach/forbiden/obj/cloak")->move(this_object());
    new("/wizards/detach/forbiden/obj/boots")->move(this_object());
    new("/wizards/detach/forbiden/obj/gloves")->move(this_object());
    new("/wizards/detach/forbiden/obj/armour")->move(this_object()); 
    if(random(15) == 10) {
       new("/wizards/detach/forbiden/obj/Claw")->move(this_object());
       new("/wizards/detach/forbiden/obj/Claw")->move(this_object());
       force_me("wield claw");
       force_me("wield claw 2");
    }
    force_me("wear gloves");
    force_me("wear boots");
    force_me("wear cloak");
    force_me("wear skull");
    force_me("wear armour");
    set_heart_beat(1);
    set_moving(1);
    set_speed(4);
}                                             
