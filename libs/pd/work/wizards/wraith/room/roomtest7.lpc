#include <std.h>


inherit ROOM;

void create() {
    object ob;
    ::create();
     set_name("underworld");
     set_short("The Under World");
     set_day_long("%^BOLD%^BLACK%^The Meeting place of The Under World.\n 
%^BOLD%^%^BLACK%^An evil sort of people who's only wish is to bring pain and suffering to all of those not part of their Agreement.
%^RED%^F%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^BOLD%^BLACK%^burn and %^RED%^b%^BOLD%^%^RED%^%^r%^RESET%^%^RED%^i%^BOLD%^%^RED%^m%^RESET%^%^RED%^s%^BOLD%^%^RED%^t%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^flows around skulls embedded in the stone.\nIt looks like sombody acutally made a room in Hell itself!
\n%^BOLD%^%^BLACK%^A board made up of %^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^s%^RESET%^ %^BOLD%^%^BLACK%^and %^BOLD%^%^WHITE%^b%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^ can be see in the center of the room.%^RESET%^\n");
     set_night_long("%^BOLD%^BLACK%^A few disheartened slaves cleanup the mess left behind by the Underworlders.%^RESET%^ 
%^BOLD%^%^BLACK%^A board made up of %^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^s%^RESET%^ %^BOLD%^%^BLACK%^and %^BOLD%^%^WHITE%^b%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^ can be see in the center of the room.%^RESET%^\n");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "dessert"     : 1,
]));
   
  ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "underworld board" }) );
    ob->set_board_id("Underworld");
    ob->set_max_posts(99);
    ob->set_location("/wizards/wraith/room/roomtest7");
    ob->set("short", "%^BOLD%^%^BLACK%^U%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^r %^BOLD%^%^WHITE%^W%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^d %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^d %^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^f %^BOLD%^%^WHITE%^P%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^n%^RESET%^");
    ob->set("long", "A place to put any notions you might have in that empty salad bowl you call a head.\n");
    set_property("no steal", 1);
}
