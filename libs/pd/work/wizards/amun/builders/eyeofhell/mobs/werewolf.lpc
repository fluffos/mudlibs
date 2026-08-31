#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Werewolf");
    set("id", ({ "werewolf", "monster", "wolf" }) );
    set_level( 70 );
    set("short", "Werewolf" );
    set("long", "%^BOLD%^%^RED%^The werewolf howls as you look at him.  He begins to move towards you..%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("werewolf");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    set_emotes(20, ({"%^BOLD%^%^RED%^Rips you apart with his claws!%^RESET%^"}), 1);
    new(HELLWEP+"werewolf_claws")->move(this_object());
    new(HELLWEP+"werewolf_claws")->move(this_object());
    force_me("wield claws");
    force_me("wield claws 2");
    set_max_hp(9500);
    set_exp(220000);
}
