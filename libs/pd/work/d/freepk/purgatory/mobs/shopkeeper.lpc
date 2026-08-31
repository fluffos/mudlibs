#include <purgatory.h>
inherit "/std/vendor";

create() {
    ::create();
    set_name("Yvehc, The shopkeeper");
    set_id( ({ "Yvehc", "shopkeeper", "monster" }) );
    set_short("Yvehc, the shopkeeper.");
    set("aggressive", 0);
    set_level(90);
    set_long("Yvehc, the shopkeeper is a big burly man. Someone a drunken man would leave well enough alone.");
    set_languages( ({ "kanashi" }) );
    set_gender("male");
    set_alignment(-420);
    set("race", "gracknarl");
    add_money("gold", random(60));
    set_body_type("scorpion");
    set_currency("gold");
    set_storage_room(ROOMS"storage");
    set_skill("bargaining", 150);
    set_property("no bump", 1);
    set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi "+
      (string)previous_object()->query_cap_name()+" just threw their life away!");
    return 0;
}
