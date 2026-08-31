// Coded by Whit

#include <tombar.h>
#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("tombar guard");
    set_id(({"guard", "tombar guard"}));
    set_long("This is a tombar guard.  He garuds the sacred temples "
      "hidden secrets.");
    set_short("tombar guard");
    set_skill("magic attack", 100);
    set_skill("blade", 50);
    set_class("mage");
    set_subclass("necromancer");
    set_level(29);
    set("aggressive", 30);
    set_spells(({"shadowburst"}));
    set_spell_chance(50);
    set_gender("male");
    set("race", "dwarf");
    set_body_type("dwarf");
    new(ARM"guardarm")->move(this_object());
    new(WEP"guardwep")->move(this_object());
    force_me("wear armour");
    force_me("wield sword");
    add_money("gold", random(100));
}

