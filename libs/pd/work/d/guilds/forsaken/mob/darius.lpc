#include <std.h>
#include <guild.h>
inherit VENDOR;
create() {
    ::create();
    set_name("darius");
    set_id( ({ "darius" }) );
    set_short("%^BOLD%^%^BLACK%^Darius the Black%^RESET%^");
    set("aggressive", 0);
    set_level(45);
    set_long("%^BOLD%^%^BLACK%^Darius once led the minions of evil upon a "
             "strike against good. Since his failure he has been branded Forsaken.");
    set_languages( ({ "farsi" }) );
    set_gender("male");
    set_alignment(-420);
    set("race", "human");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
    set_storage_room(ROOMS"forsaken/storage");
    set_skill("bargaining", 100);
    set_property("no bump", 1);
    set_property("no attack", 1);
}
int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi "+
      (string)previous_object()->query_cap_name()+" is about to die!");
    return 0;
}
