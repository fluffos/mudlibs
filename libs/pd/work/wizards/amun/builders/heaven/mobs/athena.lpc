#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Athena");
    set("id", ({ "athena", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Athena%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Athena is the goddess of war, the female counterpart of Ares. However, she was also a goddess of peace, noted for her compassion and generosity. She was also a patron of the arts and crafts, especially spinning and weaving. In later times she was important as a goddess of wisdom. Athena was also a guardian of cities, notably Athens, where the Parthenon was erected as her temple.%^RESET%^" );
    set("race", "goddess" ); 
    set_gender( "female" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush", "slash" }) );
    set_spell_chance(60); 
    new(HEVARM "silver_breastplate")->move(this_object());
    new(HEVARM "cloak_of_the_light")->move(this_object());
    new(HEVARM "helm_of_clouds")->move(this_object());
    new(HEVARM "belt_of_clouds")->move(this_object());
    new(HEVARM "diamond_earrings")->move(this_object());
    new(HEVWEP "crystalline_blade")->move(this_object());
    new(HEVWEP "crystalline_blade")->move(this_object());
    force_me("wear armour");
    force_me("wear cloak");
    force_me("wear helm");
    force_me("wear belt");
    force_me("wear earrings");
    force_me("wield blade");
    force_me("wield blade 2");
    set_max_hp(9500);
    set_exp(200000);
}
