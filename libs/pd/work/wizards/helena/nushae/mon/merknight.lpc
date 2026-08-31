#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_id(({ "knight", "merknight" }));
    set_short("a loyal mer-knight");
    set_name("knight");
    set_level(26);
    set_long("Scanning their surrounds for signs of trouble or plight, the royal knights of NuShae possess a stony glare, and a fierce look about them, ever ready to head into battle in the name of NuShae.");
    set_body_type("merperson");
    set_race("merfolk");
    set_gender("male");
    new(WEAP "naxe")->move(this_object());
    this_object()->force_me("wield axe");
    new(ARM "ibracers")->move(this_object());
    this_object()->force_me("wear bracers");
}
