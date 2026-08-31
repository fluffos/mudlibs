// Owner of the armory in roston.  NS.
#include <std.h>
#include <roston.h>
inherit VENDOR;

void create() {
    ::create();
    set_name("Joey");
    set_id( ({ "joey","monster" }) );
    set_short("Joey the armorer");
    set("aggressive", 0);
    set_level(20);
    set_long("Joey will buy or sell you any of your amour needs. <help shop> "
             "will get you a list of available shop commands.");
    set_languages( ({ "farsi" }) );
    set_gender("male");
    set_alignment(40);
    set_race("dwarf");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
    set_storage_room(ROOMS "armory_s");
    set_skill("bargaining", 150);
}

int is_invincible() {return 1;}
