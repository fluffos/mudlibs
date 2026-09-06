// Tin for the Tinning Kit by Graah
// 300395 fixed eat->eat_cmd & updated... Haw
// 9-Sep-96 / Graah: Gives twice more heal now. Tins are hard to
// make, and very expensive at baker's.

#include <food.h>

#include <conditions.h>

int tin_level, orig_level;

void
set_tin_level(int x)
{
    tin_level = orig_level = x;

    /*   x = 3 * (x / 4); */
    if (x > 25) x = 25;

    set_strength(x);
}

void set_tin_strength_baker(int x)
{
    set_strength(x);
}

/* Level of the original creature */
int query_orig_level() { return orig_level; }

/* Fool them with rotten tins */
int
min_cost()
{
    int x;

    x = 4 * strength + (strength * strength) / 10;
    if (x < 0) x = -x;
    else if (!x) x = 8;

    return x;
}

/* Redefined */
status
eat_cmd(string str)
{

    if (!str || !id(str)) return 0;

    if((int)this_player()->query_level() * 8 < strength)
	return notify_fail("You realize even before trying that you'll \
never be able to eat all this.\n"),0;

    if (!this_player()->eat_food(strength)) return 1;

    this_player()->heal_self(strength * 2);

    this_player()->tell_me("You open " + query_short() + " and consume it.");
    environment(this_player())->tell_here(this_player()->query_name() + " opens " + 
      query_short() + " and consumes it.\n",this_player());

    if (strength < 1) {
	this_player()->tell_me("Blerghhhh! Rotten food!");
	if (!random(3)) {
	    this_player()->tell_me("Everything goes dark.");
	    environment(this_player())->tell_here(this_player()->query_name() +
	      " falls down, unconscious.\n",this_player());
	    this_player()->set_condition(C_UNCONSCIOUS, 4 + random(6));
	} else {
	    this_player()->tell_me("You feel very sick and vomit everything you've eaten.");
	    environment(this_player())->tell_here(this_player()->query_name() + 
	      " vomits violently.\n",this_player());
	}
    }

    destruct(this_object());
    return 1;
}
