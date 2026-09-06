

#include <daemons.h>
#include <room_defs.h>
#include <drink_defs.h>
#include <npc_defs.h>

inherit "lib/pub";

#include "dirs.h"

#define TP this_player()

void init_drinks() {
    /* ids, container, short, alco value, heal, cost, long desc, drink msg */
    drinks = ({
      ({"beer","dark beer"}),
      "bottle","Bottle of Dark Beer",	2,1,60,
      "This REAL beer is certainly a product of some illegal brewery.\n" +
      "The authorized Tristeza breweries just can't make the real stuff!\n",
      "That feels VERY good",
      ({"cocktail", "thieven cocktail"}),
      "bottle","Cocktail",8,10,300,
      "This bottle contains a drink which is a mixture of liquor and herbs.\n",
      "A tingling feeling goes through your body",
      ({"booze", "bottle of booze"}),
      "bottle","Bottle of Booze",15,27,885,
      "This bottle contains some clear liquid. There's \"XXX\" on the label.\n",
      "HNKK! GHH! HGGN! This stuff is STRONG"
    });
}

/* Non-thieves: 50% more expensive */
int
modify_cost(int c) {
    if (!present("tmark", this_player()))
	return (((::modify_cost(c)) * 15) / 10);
    return c;
}

string query_drink_obj_object_name() { return DRINK_FILE; }
string query_default_drink() { return "booze"; }

int
check_hours() {
    object gc;
    int hour;

    hour = NATURE_D->query_24_hour();
    if (hour >= 10 && hour < 16) return 0;

    return 1;
}

/* No bartender, doesn't care about crimes (costs will be higher though) */
int
pub_open() {
    return 1; // Who cares about hours
    return check_hours();
}

int
check_open() {

    if (!TP) return 0;
    if (!pub_open()) return 0;

    if (!check_hours()) {
	write("The Cloak and Dagger is closed from 10 AM to 4 PM.\n");
	write("Would you please leave.\n");
	TP->move_player(GDIR + "rooms/guild");
	return 0;
    }

    return 1;
}

void create_pub() {
    set_short("The Cloak and Dagger");

    set_light_level(LT_DIM);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    add_exit("south", GDIR + "rooms/guild");

    //add_permanent("/lib/bench");
}

/* Got to have long separately to get correct drink list :-(... */
varargs string
query_long(string arg, object who)
{
    mixed x;

    if (arg) return ::query_long(arg, who);

    return
    "You are in the Cloak and Dagger, the pub of Thieves. You can order "+
    "drinks here, and we got much better drinks than the other pubs! You "+
    "can now also sell empty bottles (nothing else). The available drinks:\n\n"+
    list_drinks(0) +
    "\nThe 'fill' command can also be used (check city pub for more info).\
\nOnly obvious exit is south.";

}

mixed
query_property(string str) {
    if (!str) return "player_killing_allowed";

    return str == "player_killing_allowed";
}

void init_room() {
    add_action("sell","sell");
}

int query_drop_castle() { return 1; }

int sell(string str) {
    object ob;
    int c;

    if (!check_open()) return 0;

    if (!present("tmark", this_player())) return 0;

    if (str && (str != "empty bottle" && str != "bottle")) {
	write("Sorry, but we only buy empty bottles here.\n");
	return 1;
    }

    ob = present("bottle",TP);
    if(!ob) {
	write("You don't have any empty bottles.\n");
	return 1;
    }

    if((int)ob->query_value() != 10) {
	write("That is not a normal empty bottle.\n");
	return 1;
    }

    if (present("tmark", this_player())) c = 10;
    else c = 2;

    write("Ok. You get " + c + " gold pieces.\n");
    TP->add_money(c);
    TP->add_weight(-((int)ob->query_weight()));
    destruct(ob);
    say((string)TP->query_name() + " sells an empty bottle.\n");

    return 1;
}
