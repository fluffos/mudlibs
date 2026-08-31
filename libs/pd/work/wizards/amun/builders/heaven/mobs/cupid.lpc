#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Cupid");
    set("id", ({ "cupid", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^CYAN%^Cupid%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Cupid is the god of love. He was the personification of love in all its manifestations, including physical passion at its strongest, tender, romantic love, and playful, sportive love. According to some legends he was one of the oldest of the gods, born from Chaos and personifying creative power and harmony.%^RESET%^" );
    set("race", "god" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    new(HEVARM "diaper")->move(this_object());
    new(HEVARM "quiver_of_love")->move(this_object());
    new(HEVWEP "bow_of_love")->move(this_object());
    force_me("wear diaper");
    force_me("wear quiver");
    force_me("wield bow");
    set_max_hp(9500);
    set_exp(200000);
}
