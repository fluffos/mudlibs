// Petrarch
// Merentha Lib 1.0

#include <std.h>
inherit SHOP;

void create() {
    ::create();
    set_short("A supply shop in the Cabeiri courtyard");
    set_long("This is a rather popular supply shop.  The basics which \
are needed for day to day living can all be bought here.  Cloths, \
armour, weapons and accessories fill the shelves on the walls.  A \
shopkeeper stands behind the counter ready to help anyone.");
    set_items(([
        "shop":"The shop is full of items for sale.",
        "supplies":"Supplies include cloths, weapons and accessories.  The shopkeeper can help you further.",
        "cloth":"There is cloths of all sizes and colours in racks behind the counter.",
        "armour":"There are several pieces of armour here for sale.",
        "weapon":"There are some weapons on sale, for the right price.",
        "shelves":"The shelves are full of items for sale.",
      ]));
    set_exits(([
        "south":"/domains/Cabeiri/square",
      ]));
    set_supply_room("/domains/Cabeiri/general_supply");
    set_currency("gold");
}

void load_simon() {
    object mon;
    mon=new(MONSTER);
    mon->set_name("simon");
    mon->set_short("Simon the Shopkeeper");
    mon->set_long("Simon stands behind the counter ready to help anyone make a purchase.  As you look at him he points to the sign on the counter.");
    mon->set_id(({"simon", "shopkeeper"}));
    mon->move(this_object());
    mon->set_level(1);
    mon->set_race("human");
}

void reset() {
    object ob;
    ::reset();
    if(!present("simon")) load_simon();
    if(!present("sign")) {
        ob=new(SIGN);
        ob->set_name("sign");
        ob->set_short("a sign sitting upon the counter");
        ob->set_long("The sign is here to help those who need it.");
        ob->set_message(border("%^ORANGE%^\
             list %^YELLOW%^:%^RESET%^%^GREEN%^ Lists all items for sale\n\
      list <item> %^YELLOW%^:%^RESET%^%^GREEN%^ Lists all items for sale which match <item>\n\
     value <item> %^YELLOW%^:%^RESET%^%^GREEN%^ Simon will tell you what he will pay for <item>\n\
      show <item> %^YELLOW%^:%^RESET%^%^GREEN%^ Simon will show you the <item> in detail\n\
      sell <item> %^YELLOW%^:%^RESET%^%^GREEN%^ Simon will buy the <item> from you\n\
       buy <item> %^YELLOW%^:%^RESET%^%^GREEN%^ Simon will sell you the <item>\n\
", "Welcome to Simon's Shop"));
        ob->set_id(({"sign", "shop sign"}));
        ob->move(this_object());
    }
}

void init() {
    ::init();
    if(!present("simon")) load_simon();
}

