#include <room_defs.h>
#include "../DEFS.h"
#include <criminal.h>

inherit "/lib/food_shop";

#define ROOM_EAST "/areas/tristeza/finnclub/hall"
#define TP this_player()

void
init_foods()
{
    /* ids, short, strength, weight, cost, long desc, eat msg, said msg */
    foods = ({
      ({ "piirakka", "karjalan", "pie" }), "Karjalanpiirakka",
      10, 2, 75,
      "A 'Karjalan piirakka' ('Karelian pie') is a pie made of rice and rye dough.",
      "Munch munch munch...good!",
      "eats a Karjalanpiirakka.",

      ({ "sausage", "black", "makkara", "musta" }), "Musta makkara",
      15, 1, 100,
      "'Musta Makkara' ('Black Sausage') looks like shit.",
      "Munch munch munch...not bad!",
      "eats some shit (or is it Mustamakkara)?",

      ({ "paisti", "karjalan", "roast" }), "Karjalanpaisti",
      20, 1, 350,
      "'Karjalanpaisti' ('Karelian roast') is simply a dish of meat slowly \
roasted in an oven. It includes pork, cow and sometimes sheep meat.",
      "Chomp munch mum yum...yum! Tasty stuff!",
      "eats some Karjalanpaisti."
    });
}

void
reset_shop()
{
    if (!baker) {
	baker = clone_object(NPC_DIR+"shopkeeper");
	baker->set_name("head waiter");
	baker->move_player("foo", this_object());
	baker->set_name("waiter");
	baker->set_short("Head Waiter");
	baker->set_race("human");
	baker->set_long("The head waiter is a bald middle-aged finnish man.");
	baker->set_random_pick(0);
    }
}

void
create_shop()
{
    set_short("'Paha Yst{v{' Restaurant");
    set_long(
      "'Paha Yst{v{' is a typical finnish restaurant. Poor but rude waiters, \
long waits, expensive meals.\n\n"+
      list_foods(0) +
      "\nYou can 'fill bag' (or any container) with Karjalanpiirakka - or with \
some other food: for example 'fill bag with makkara'.");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);

    add_exit("east", ROOM_EAST);
    reset_shop();
}

void
init_room()
{
    object o;

    if (!interactive(o = TP) && o && environment(o) == this_object()
      && o != baker && !TP->id("city_guard"))
	call_out("throw_out", 0, o);
    // Call out used since we don't want to throw it out before arrive msg gets
    // printed!!!

}

void
throw_out(object who)
{
    if (!baker || !who || environment(baker) != this_object() ||
      environment(who) != this_object()) return;

    // Coded this way so we get "Baker says... Baker throws Foobar out.",
    // and also, players in the other room get "Foobar arrives."

    tell_here("Keeper says: No monsters allowed!\nKeeper throws ", who, 1);
    who->move_player("Vout"+ROOM_EAST);
}

int
shop_open()
{
    object ob;

    if (!baker || !present(baker))
	return notify_fail("The head waiter is not here.\n"), 0;

    if ((int)TP->query_crime_level() > CR_THEFT)
	return notify_fail("We do not trade with criminals!\n"), 0;

    return 1;
}
