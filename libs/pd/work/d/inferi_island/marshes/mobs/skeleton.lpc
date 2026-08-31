#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Skeleton");
    set("id", ({ "monster", "skeleton" }) );
    set_level( 25 );
    set("short", "%^BOLD%^%^WHITE%^Skeleton%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^This sun-bleached skeleton resembles an average man..only a skeleton.%^RESET%^" );
    set("race", "human" );
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5);
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 25);
    new(MARSHARM+"decaying_pants")->move(this_object());
    new(MARSHARM+"tattered_rags")->move(this_object());
    new(MARSHWEP+"frayed_whip")->move(this_object());
    force_me("wear pants");
    force_me("wear shirt");
    force_me("wield whip");
    set_alignment(-150);
    set_undead(1);
}
