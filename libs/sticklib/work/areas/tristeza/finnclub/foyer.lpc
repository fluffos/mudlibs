#include <room.h>
#include "../DEFS.h"

#define TP this_player()

int cost;
void
create_room()
{
    set_short("Foyer");
    set_long("You are standing outside a great wooden building. Above the \
ever-open door is a sign: 'FINNISH CLUB'. You can hear merry voices from the \
inside and see warm light in the windows.");
    set_exits(([
	"south"	: CITY_PATH+"finnclub/hall",
	"north" : CITY_DIR+"S11_7"
      ]));

    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS * 2);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set(IN_CITY);
    cost = 60;
    add_monster("/areas/tristeza/finnclub/portsari", "Portsari arrives.", 50);
    set_commands(([
	"south" : "south",
      ]));
}

#define PORTELL(x) TP->tell_me("Portsari tells you: " + x)

status
south()
{
    if (!TP || (TP->query_npc() && !TP->query_ctrl())) return 1;
    /* Controlled monsters can enter */

    if ((int)TP->query_level() >= 55)
    {
	PORTELL("Kato vip-kortti perkele! Tuu sissaeaen!");
    }
    else
    {
	if (!TP->query_coder_level() &&  present("portsari", this_object())) {
	    PORTELL("Narikkamaksu on " + cost + " kultarahaa! [It costs " +
	      cost + " gp to enter this club!]");
	    if (TP->query_money() < cost ) {
		PORTELL("Liikaa pohjia. Tulee sit joskus muulloin uusiks. \
[You don't have enough cash. Return later.]");
		return 1;
	    }
	    TP->add_money(-cost);
	    /* NEW, Portsari now GAINS the money! */
	    present("portsari",this_object())->add_money(cost);
	    TP->tell_me("You pay " + cost + " gp and Portsari lets you \
enter.");
	}
    }

    TP->move_player("south", CITY_PATH+"finnclub/hall");
    return 1;
}

void
raise_cost()
{
    cost += random(5) + 1; //increase 1-5
}
int query_cost() { return cost; }
