#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Sesto (the Finnish Shop)");
    set_long(
      "Here you can buy genuine souvenirs of Finland, the land of the 1000 lakes! \
Commands: 'list' and 'buy'.");
    add_exit("west", CITY_PATH+"finnclub/hall");

    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);

    set_commands(([
	"list"	: "list",
	"buy"	: "buy"
      ]));
    set(IN_CITY);
    set(NO_PK);
}

status
list()
{
    this_player()->tell_me(
      "Available items:\
\nInstructions of how to make a 'vihta'      175 gp  (buy instr[uctions])\
\nPullo Kossua (a bottle of 'Koskenkorva')   150 gp  (buy kossu)"
      /*
      \nPullo Ponua  (a bottle of 'Moonshine')     250 gp  (buy ponu)\
      \nA 'Puukko' (genuine Finnish Knife)          25 gp  (buy puukko)\
      */
    );
    return 1;
}

status
buy(string str)
{
    object ob, tpl;
    int cost;

    tpl = this_player();
    if (!str) return notify_fail("Buy what?\n"), 0;

    str = lower_case(str);

    if (sizeof(str) > 5) str = str[0..4];

    cost = -1;

    if(str == "instr") cost = 175;
    if(str == "puukk") cost = 25;
    if(str == "kossu") cost = 150;
    if(str == "ponu") cost = 250;

    if (cost == -1) {
	this_player()->tell_me("No such thing in this shop.");
	list();
	return 1;
    }

    if(tpl->query_money() < cost) {
	this_player()->tell_me("Unfortunately don't have enough money.");
	tell_here((string) tpl->query_name() + " sighs deeply.", this_player());
	return 1;
    }

    if (str == "instr") {
	/*      if(present("vihta_instructions", tpl)) {
		 write("But you already have those instructions!\n");
		 return 1;
	      } */
	ob = clone_object(CITY_PATH+"finnclub/instructions");
    } else if (str == "kossu") {
	ob = clone_object(CITY_PATH+"finnclub/kossu");
    }

    if (!ob) {
	this_player()->tell_me("This object is not available yet.");
	return 1;
    }

    this_player()->tell_me("Ok.");

    if (!tpl->add_weight((int) ob->query_weight())) {
	this_player()->tell_me("Oops, that was a heavy thing. You dropped it.");
	tell_here((string) tpl->query_name() + " drops " + ob->query_name() + ".",
	  this_player());
	move_object(ob, environment(tpl));
    } else move_object(ob, tpl);

    tpl->add_money(-cost);
    return 1;
}
