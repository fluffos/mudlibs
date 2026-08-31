#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("Dark Archer");
    set_short("%^BOLD%^%^BLACK%^Dark Archer%^RESET%^");
    set_id(({"monster", "archer"}));
    set_long("One of the band of %^BOLD%^%^BLACK%^Dark Archers%^RESET%^ summoned by the royal magician to defend the walls of Purgatory.");
    set_level(75+random(10));
    set("aggressive", 25);
    set_gender("male");
    set_race("human");
    set_class("fighter");
    set_subclass("ranger");
    set_body_type("raknid");
    set_spell_chance(39);
    set_spells(({"slash"}));

    new(EQ"quiver")->move(this_object());
    force_me("wear quiver");

    new(WEAP"longbow")->move(this_object());
    force_me("wield bow");

    new(WEAP"shortsword")->move(this_object());
    force_me("wield sword");

    new(WEAP"shortsword")->move(this_object());
    force_me("wield sword");

    new(WEAP"shortsword")->move(this_object());
    force_me("wield sword");

}
