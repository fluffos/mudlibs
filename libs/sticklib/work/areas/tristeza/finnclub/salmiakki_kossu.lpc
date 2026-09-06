#include <drink.h>

#include "../DEFS.h"
#include <invis_levels.h>
#include <conditions.h>

void
create_drink()
{
    set_name("kossu");
    set_id(({ "kossu", "koskenkorva", "salmiakkikossu", "salmiakki" }));
    set_short("bottle of Salmiakkikossu");
    set_long(
      "This liquor bottle has a label:\n\n"+
      "     \"KOSKENKORVAN SALMIAKKI KIVENN[ISVESI\n\n"+
      " Pullotettua kansanviisautta jo 30-luvulta\"\n\n");
    set_value(120);
    set_strength(15);
    set_keep_short(0);

    drinker_mess = "AAAAAHHHH! What a SMOOTH taste (it is spiced with \
salmiac, if you know what it is). You know, \
this stuff was BANNED in finland because it was too popular!\n";
}

extra_drink()
{
    object tp, d;

    tp = this_player();

    /* silly thing doesn't work like this +- Flagg
      d = present("finn_drunk", tp);
    */
    d = present4("finn_drunk", tp, tp, IL_TOTALLY_INVISIBLE);
    if (d) d->add_counter(8 + random(8));
    else {
	d = clone_object( CITY_PATH+"finnclub/finn_drunk");
	move_object(d, tp);
	d->set_counter(8 + random(8));
    }

    tp->add_condition(C_HALLUCINATING, 4 + random(4));
}
