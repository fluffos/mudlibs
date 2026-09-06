#include <room.h>
#include <areas.h>
#include <generic_items.h>
#include <mud_name.h>

void
create_room()
{
    int i;
    set_short("Bank vault");
    set_long("This is the vault of the First Mudional Bank of "+MUD_NAME+".\
 Here are kept the gold coins players have been depositing. Some of\
 the money have been exchanged for treasures, because the Shopkeeper has\
 had a shortage of money. The walls are made of large stones and look\
 like they might be earthquake-proof.");
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_exits(([ "out" : AREA_TRISTEZA+"bank/bank_back" ]));
    for (i=0; i<3; i++)
	add_object( ({ 0,
	    ({ "set_name", "goldbar" }),
	    ({ "set_id", ({ "bar", "gold bar" }) }),
	    ({ "set_short", "Goldbar" }),
	    ({ "set_long", "It is a standard banking gold bar.\
 It has \"24K\" stamped into it." }),
	    ({ "set_weight", 10 }),
	    ({ "set_value", 3000 }) }), 0, 1);

    for (i=0; i<3; i++)
	add_object( ({ 0,
	    ({ "set_name", "zorkmid" }),
	    ({ "set_short", "A zorkmid" }),
	    ({ "set_long",
	      "Written on it is 'In Frobozz we trust'. You notice that under word 'Frobozz'\
 there has once been some else writing." }),
	    ({ "set_value", 100 }),
	    ({ "set_weight", 1 }) }), 0, 1 );

    //Gives the same amount of money in every reset, oh well
    add_object(({ GENERIC_MONEY_OBJECT,
	({ "set_money", 1000 + random(1001) })
      }),0,1);
    replace_program(ROOM_FILE);
}
