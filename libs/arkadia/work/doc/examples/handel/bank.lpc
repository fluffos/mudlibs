/*
 * Przykladowy bank
 */
 
inherit "/std/room";
inherit "/lib/bank";

#include <stdproperties.h>

/*
 * Function name: create_room
 * Description:   Set up default trade and cofigure it if wanted.
 */
void
create_room()
{
    set_short("Przykladowy bank");
    set_long("Znajdujesz sie w przykladowym banku, gdzie gracz moze "+
        "rozmienic oraz zdenominowac swoje pieniadze. Na scianie wisi "+
        "tabliczka, majaca najprawdopodobniej na celu doinformowanie "+
        "cie o uslugach, oferowanych tu.\n");

    add_item( "tabliczke",
        "W sumie to nic ciekawego, choc mozesz ja pewnie przeczytac.\n");

    add_cmd_item( ({ "tabliczke" }), "przeczytaj", "@@standard_bank_sign");

    add_prop(ROOM_I_INSIDE, 1);

    config_default_trade(); /* ustawia standardowe parametry banku -
    			     * niezbedny, jesli nie ustawiamy wszystkiego
    			     * samemu */
    set_bank_fee(30); /* % pobierany przy wszystkich tranzakcjach */
    config_trade_data();
}

init()
{
    ::init();

    bank_init(); /* Dodaje komendy banku */
}

