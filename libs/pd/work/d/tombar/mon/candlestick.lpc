#include <std.h>
#include <tombar.h>

inherit MONSTER;
void create() {
    ::create();
    set_name("candlestick");
    set_long("This is a long, broad candlestick.  Its flaming "
      "eyes seem to lurk into your soul.");
    set_short("silver candlestick");
    set_id(({"candlestick", "silver candlestick"}));
    add_action("monter_hit", "monster_hit");
    add_action("flame", "flame");
    set_spells(({"monster_hit", "flame"}));
    set_spell_chance(10);
    set_level(34);
    set_race("candlestick");
    set_body_type("candlestick");
}

int monster_hit(object ob) {
    tell_object(ob, "Flames that burn deep from the candlesticks "
      "eyes seems to torment your soul.");
    return random(100);
}

int flame(object ob) {
    say("Flames streak from the candlestick and reach out for "+
      ob->query_cap_name());
    return random(130);
}

