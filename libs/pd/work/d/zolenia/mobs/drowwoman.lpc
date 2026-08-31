#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow woman");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ woman");
    set_long("This drow is fairly frail looking, although she might have some tricks up her sleeves.");
    set_id(({"drow", "woman", "drowwoman", "drow woman"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment(-500);
    set("aggressive",30);
    set_gender("female");
    set_class("mage");
    set_subclass("necromancer");
   new(ARM"darkdress")->move(this_object());
     force_me("wear dress");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"raise zombie", "deathtouch"}));   
}
void heart_beat() {
  remove_property("deathtouch_spell_charge");
  set_property("deathtouch_spell_charge", 50);
  ::heart_beat();
}
