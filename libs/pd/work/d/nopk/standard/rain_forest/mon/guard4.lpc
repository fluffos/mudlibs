// Will be wearing a spiked helmet spiked gloves and cerrated sword spiked
// platemail
#include <std.h>
#include <rain.h>
inherit MONSTER;

create() {
    ::create();
    set_name("knight");
    set_short("A large black knight");
    set_level(15);
    set_id(({"knight", "guard", "black knight"}));
    set_class("fighter");
    set_race("ogre");
    set_body_type("human");
    set_long("This guard was hired by the king to guard the palace. "
      "He is a large burly ogre wearing platemail with it's c"
      "hest and soldiers spiked. It's got spikes coming out o"
      "f his gloves. His helmet has some spiked coming out of"
      " the helmet also. His sword is a long sword with a ser"
      "rated edge.");
    set_gender("male");
    set_spells(({"slash", "whirl"}));
    set_spell_chance(30);
    new(WEA"spsword")->move(this_object());
    new(ARM"sphelm")->move(this_object());
    new(ARM"spplate")->move(this_object());
    new(ARM"spglove")->move(this_object());
    this_object()->force_me("wield sword");
    this_object()->force_me("wear platemail");
    this_object()->force_me("wear gloves");
    this_object()->force_me("wear helmet");
}
