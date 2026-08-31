#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("magi");
    set("id", ({ "magi", "monster" }) );
    set_level( 60 );
    set("short", "%^RESET%^%^BLACK%^Magi" );
    set("long", "%^BOLD%^%^BLACK%^Wearing all black, it is hard at first to see the Magi.  He is strong and looks ready to defend himself and his King and Queen.%^RESET%^" );
    set("race", "human" ); //
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7); // 
    set_fingers(5); 
    set_skill("melee", 40);
    set_skill("attack", 100);
    set_class("mage");
    set_subclass("necromancer");
    set_spell_chance(75);
    set_spells( ({ "shadowburst", "disease", "soulburn" }) );
    set_skill("necromancy", 60*6);
    set_skill("magic attack", to_int(60*5.5) );
    set("aggressive", 40);
    set_emotes(1, ({"A shadow grips his bow an draws and arrow as you draw near."}), 0);
    set_emotes(2, ({"A shadow mutters something about the '%^BOLD%^%^RED%^Oculus Inferi%^RESET%^'."}), 0);
    new(ARM+"leather_pants")->move(this_object());
    new(ARM+"leather_shirt")->move(this_object());
    new(ARM+"horn_ring")->move(this_object());
    //new(ARM+"leather_pouch")->move(this_object());
    new(WEP+"magi_bow")->move(this_object());
    force_me("wear pants");
    force_me("wear shirt");
    force_me("wear ring");
    force_me("wear pouch");
    force_me("wield bow");
}
