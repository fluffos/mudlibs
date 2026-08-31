#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Poseidon");
    set("id", ({ "poseidon", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Poseidon%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Poseidon is the god of the sea, protector of all waters. After the fall of the Titans, Poseidon was allotted the sea. He was worshiped especially in connection with navigation; but as the god of fresh waters he also was worshiped as a fertility god. Poseidon was represented as extremely powerful, with a violent and vengeful disposition.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("mage");
    set_subclass("necromancer");
    set("aggressive", 60);
    set_spells( ({ "chaoswave" }) );
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    set_max_hp(9500);
    set_exp(200000);
}
