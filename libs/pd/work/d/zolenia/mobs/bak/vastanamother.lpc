#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("vastana mother");
    set_short("%^RESET%^%^RED%^%^BOLD%^Vastana%^RESET%^ mother");
    set_long("This drow is fairly frail looking, although she might have some tricks up her sleeves.  Her eyes are %^RED%^red%^RESET%^ with bloody fury.  Her dark skin is covered in blood.");
    set_id(({"drow", "mother", "vastanamother", "vastana mother"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment("-500");
    set("aggressive",30);
    set_gender("female");
    set_class("mage");
    set_subclass("necromancer");
   new(ARM"bloodydress")->move(this_object());
     force_me("wear dress");
   new(ARM"bloodyring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"absorb", "deathtouch"}));   
}
void heart_beat() {
  remove_property("deathtouch_spell_charge");
  set_property("deathtouch_spell_charge", 50);
  ::heart_beat();
}
