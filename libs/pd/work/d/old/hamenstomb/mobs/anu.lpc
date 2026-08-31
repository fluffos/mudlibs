#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Anu");
    set("id", ({ "anu", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Anu" );
    set("long", "%^BOLD%^%^GREEN%^Anu aids the Queen anyway she can.  If you kill her auick, she will not be able to tell the Queen you are coming.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set("aggressive", 40);
    set_emotes(1, ({"%^BOLD%^%^GREEN%^Anu glows with a green aura."}), 0);
    new(ARM+"bronze_coatmail")->move(this_object());
    if(random(100) > 90)
	new(ARM+"amulet")->move(this_object());
    if(random(100) > 90)
	new(WEP+"bronze_sword")->move(this_object());
    if(random(100) > 90)
	new(WEP+"bronze_sword")->move(this_object());
    force_me("wear armour");
    force_me("wear amulet");
    force_me("wield sword");
    force_me("wield sword 2");
}
