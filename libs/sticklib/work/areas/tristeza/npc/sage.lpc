#include <npc.h>
#include <city_name.h>

void create_monster()
{
    set_name("sage");
    set_short("The Sage of " CITY_NAME);
    set_long(
      "The sage of " CITY_NAME " is an elderly man in the twilight of his years. "
      "He is very wealthy, but quite stingy with his wealth. He is well known "
      "for being inquisitive to extremes, but is very inventive. His magical "
      "creations are sought all across the world. "
    );
    set_level(30);
    set_hp(1000);
    set_id(({ "sage", "sage of " LCASE_CITY_NAME, LCASE_CITY_NAME " sage" }));
    set_money(400*(random(2)));
}
