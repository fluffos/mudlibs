#include <drink.h>

#include <player_defs.h>
#include "../DEFS.h"
#include <invis_levels.h>
#include <conditions.h>

void
create_drink()
{
    set_name("kossu");
    set_id(({ "kossu", "koskenkorva"}));
    set_short("bottle of Kossu");
    set_long(
      "This liquor bottle has a label:\n\n"+
      "     \"KOSKENKORVAN KIVENN[ISVESI\n\n"+
      " Pullotettua kansanviisautta jo 30-luvulta\"\n\n");
    set_value(150);
    set_strength(17);
    set_keep_short(0);

    drinker_mess =
    "HNGGGGHHH!! GAAH! Slurp? Ahh. Hek? PIIP! Lurps, doioingg...\n";
}

extra_drink()
{
    object tp, d;

    tp = this_player();

    // Didn't work with present() at all :) / Graah
    d = present4("finn_drunk", tp, tp, IL_TOTALLY_INVISIBLE);
    if (d) d->add_counter(8 + random(8));
    else {
	d = clone_object( CITY_PATH+"finnclub/finn_drunk");
	move_object(d, tp);
	d->set_counter(8 + random(8));
    }

    tp->add_condition(C_HALLUCINATING, 8 + random(8));
}
