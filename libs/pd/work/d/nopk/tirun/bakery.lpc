#include <std.h>
#include <tirun.h>

inherit ROOM;

void random_boo();
string do_listen(string);

void create()
{
    ::create();
    set_properties(([
        "light"     : 2,
        "indoors"   : 1,
        "no attack" : 1,
        "no magic"  : 1,
        "no bump"   : 1
    ]));
    set_short("Carolyn's Bakery");
    set_long("Carolyn's Bakery\n" +
        "Tables are set up to display various baked goods. A counter with a " +
        "sign on it cuts the room in two, the sales floor on one side, and " +
        "the baking area on the other. Several tables and large bags of " +
        "flour are on the far side of the counter. Two large brick ovens " +
        "line the back wall."
    );
    set_items(([
        "sign" : "Read the menu to see what's available.",
        ({ "table", "tables" }) : "The tables are covered with freshly " +
                "baked goodies.",
        ({ "oven", "ovens" }) : "The ovens are very hot!",
        ({ "bags", "flour" }) : "Several large bags of flour, obviously used " +
                "to prepare the baked goods.",
        "counter" : "The simple wooden counter divides the room. A sign " +
                "sits on it."
    ]));
    set_exits(([
        "out" : ROOMS + "whonin3"
    ]));
    set_listen("default", (: do_listen :));
    set_smell("default", "The scent of freshly baked bread fills the air.");
    set_post_exit_functions(({"out"}), ({"random_boo"}));
}

void reset()
{
    object mon;
    ::reset();
    if(!(mon = present("shopkeeper")) ) {
	   mon = new(MOB"carolyn");
            mon->move(this_object());
    }
}

string do_listen(string str)
{
    if( present("shopkeeper") )
        return "The cheerful humming of the shopkeeper can be heard.";
    return "The crackling fires of the ovens can be heard.";
}           

void random_boo()
{
    if( random(100) > 90 )
    {
        message("boo", "%^CYAN%^A faint, ghostly voice cheerfully exclaims:" +
                "%^RESET%^ Thank you, come again!", this_player());
    }
    
    return;
}

