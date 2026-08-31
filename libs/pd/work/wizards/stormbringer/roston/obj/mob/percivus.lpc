// Owner of the general store in roston -(Inferno)-
// Eh.. headerized by seeker
#include <std.h>
#include <roston.h>
inherit VENDOR;

void create() {
    ::create();
    set_name("percivus");
    set_id( ({ "percivus" }) );
    set_short("Percivus, the general store owner");
    set_level(20);
    set_long("Percivus will buy just about anything. <help shop> "
             "will get you a list of available shop commands.");
    set_languages( ({ "farsi" }) );
    set_gender("male");
    set_alignment(40);
    set("race", "dwarf");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
    set_storage_room(ROOMS "storage");
    set_skill("bargaining", 150);
}

int is_invincible() {return 1;}
