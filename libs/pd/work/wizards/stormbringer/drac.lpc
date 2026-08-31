#include <std.h>
#include <amun.h>
inherit MONSTER;
void init() {
    ::init();
    add_action("suck","suck");
}
void create() {
    ::create();
    set_name("Drac");
    set("id", ({ "drac", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^BLACK%^Drac" );
    set("long", "%^BOLD%^%^BLACK%^Staying in the shadows, Drac bares his fangs at you.  He has %^WHITE%^pale white skin%^BLACK%^, and %^RED%^blood red eyes%^BLACK%^ that seem to be glaring at the neck of anyone who passes by.  Drac has a thurst for blood.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_spell_chance(25);
    set_spells( ({"suck"}) );
    set("aggressive", 55);
    new(HELLARM+"lava_ring")->move(this_object());
    force_me("wear ring");
    set_max_hp(9500);
    set_exp(220000);
    add_action("suck", "suck");
}

int suck() {
    if(this_player()->is_player()) {
        message("info","What?",this_player());
        return 1;
    }
    if(!query_current_attacker()) return 1;
    else {
        message( "info", "%^BOLD%^%^RED%^Drac sucks the blood from your body!", this_object()->query_current_attacker(), 0 );
        query_current_attacker()->set_paralyzed(3, "%^BOLD%^%^RED%^Your body shakes as the blood spills from your neck!%^RESET%^");
        this_player()->add_hp(-500);
    }
    return 1;
}
