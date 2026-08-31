#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Slick Willy");
         set_id(({ "willy", "slick willy" }));
         set_short("Slick Willy");
         set_long("Slick Willy looks back at you and his nose crinkles. He "
                 "used to be the most sly and famous thief and adventurer "
                 "ever to come out of the gates of Tirun. Slick Willy disa"
		"ppeared long ago when he ventured to this mountain in sear"
		"ch of a treasure rumored to be kept in the bowels of the m"
		"ountain.");
         set_race("halfling");
         set_body_type("human");
         set("aggressive", 0);
         set_stats("dexterity", 800);
         set_gender("male");
         set_level(60);
   add_money("gold", random(1500));
         set_spell_chance(20);
         set_spells(({"stab"}));
    new("/wizards/smoke/mountain/items/weapon/dagger")->move(this_object());
    force_me("wield dagger");
    new("/wizards/smoke/mountain/items/weapon/dagger")->move(this_object());
    force_me("wield dagger");
    new("/wizards/smoke/mountain/armour/tunic")->move(this_object());
    force_me("wear tunic");
    new("/wizards/smoke/mountain/items/other/sack")->move(this_object());
}
void catch_tell(string str) {
    object ob;
    string a, b, c;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%streasure%s", a, b) == 2 || sscanf(str, "%smountain%s", a, b) ==
2) {
        this_object()->force_me("say Perhaps you can have better luck than I
had. There is a cavern full of the elder dragons of the realm inside this mountain, 
hidden from the outside world. The treasure is too great to even imagine, for this is 
centuries worth of pillaging and dragon raids. I cannot help you, for I have accepted
my fate to die in this hole.");
        return;
    }
}
