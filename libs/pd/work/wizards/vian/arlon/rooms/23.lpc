#include <std.h>
#include <arlon2.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is present here.");
set_listen("default", "The sound of peddling merchants can be heard here.");
set_short("Arlon shopping district");
set_long("The shopping district, in the eastern part of the Diamond District, is home to the merchants and vendors of Arlon.  The shops are a place where you can buy and sell goods you acquire on your travels, and there is usually a shopping district in most cities.  For more information on how to use the shops, type <help shop>.");
    set_exits( ([
       "enter armour shop" : ROOMS "20",
       "west" : ROOMS "square",
       "enter weapon shop" : ROOMS "26",
       "enter supply shop" : ROOMS "27",
    ]) );
add_exit_alias("enter armour shop", "armour shop");
add_exit_alias("enter weapon shop", "weapon shop");
add_exit_alias("enter supply shop", "supply shop");
add_exit_alias("enter armour shop", "armour");
add_exit_alias("enter weapon shop", "weapon");
add_exit_alias("enter supply shop", "supply");
set_items(([
({"merchants", "vendors"}) : "Merchants and vendors hurry busily through the area, buying and selling their goods.",
]));
}
void reset() {
    ::reset();
    if(!present("arlonmerchant")){
        new(MOB"arlonmerchant")->move(this_object());
        new(MOB"arlonmerchant")->move(this_object());
}
    if(!present("arlonshopper")){
        new(MOB"arlonshopper")->move(this_object());
        new(MOB"arlonshopper")->move(this_object());
}
    if(!present("topmerchant")){
        new(MOB"topmerchant")->move(this_object());
}
}

