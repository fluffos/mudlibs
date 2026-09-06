#include <npc.h>
#include <city_name.h>

void create_monster()
{
    set_name("scribe");
    set_short("The Scribe of " CITY_NAME);
    set_long(
      "The scribe of " CITY_NAME " is an young man in the prime of his years. "
      "He is very wealthy, but quite stingy with his wealth. He is well known "
      "for being inquisitive to extremes, but is very inventive. His divine "
      "creations are sought all across the world. "
    );
    set_level(30);
    set_hp(1000);
    set_id(({ "scribe", "scribe of " LCASE_CITY_NAME, LCASE_CITY_NAME " scribe" }));
    set_money(400*(random(2)));
}
