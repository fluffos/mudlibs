#include <std.h>
#include <guild.h>
#include "ether.h"
inherit VENDOR;
create() {
    ::create();
    set_name("Strongbad");
    set_id( ({ "strongbad"}) );
    set_short("%^RESET%^%^RED%^St%^BOLD%^r%^ORANGE%^o%^RESET%^%^ORANGE%^n%^BOLD%^g%^RED%^B%^RESET%^%^RED%^ad%^RESET%^");
    set_level(45);
    set_long("Strongbad is a short man who wears boxing gloves and a strange "
      "mask.  He speaks in a funny Spanish accent, and you may "
      "recognize him from homestarrunner.com  He is Ethereal's Healing "
      "Shopkeeper.");
    set_gender("male");
    set_alignment(-420);
    set("race", "human");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
    set_storage_room(STORAGE"armour");
    set_skill("bargaining", 100);
    set_property("no bump", 1);
    set_property("no attack", 1);
}
