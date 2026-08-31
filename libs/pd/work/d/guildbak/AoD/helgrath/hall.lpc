#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    object oi;
    ::create();
    set_name("Army of Darkness");
    set_items((["bones"   : "Human bones",
	"blood"   : "%^BOLD%^%^RED%^Thick human blood%^RESET%^",             
	"walls"  : "%^BOLD%^%^RED%^Blood covers the black marble%^RESET%^",
	"tables"   : "Tables made from human skulls", 
	"table"   : "%^BOLD%^%^BLACK%^A table formed from a black mist, "
	"is covered with thick human %^BOLD%^%^RED%^blood%^RESET%^",
	"floor"  : "%^BOLD%^%^RED%^BLOOD BLOOD BLOOD%^RESET%^"]));   

    set_properties(([
	"light"       : 2, 
	"night light" : 2, 
	"no teleport" : 1, 
	"no attack"   : 1,  
	"no magic"    : 1,
	"no bump"     : 1,
	"no steal"    : 1,
	"indoors"     : 1,
      ]));

    set_short("Army of Darkness");

    set_long("%^BOLD%^%^BLACK%^The Dark%^RESET%^ne%^BOLD%^%^WHITE%^ss"
      "%^BOLD%^%^BLACK%^ surrounds you. The Ar%^RESET%^m%^BOLD%^"
      "%^BLACK%^y of Dark%^RESET%^%^WHITE%^ne%^BOLD%^%^WHITE%^ss%^BOLD%"
      "^%^BLACK%^ comes here %^BOLD%^%^BLACK%^to converse on the lastest "
      "kills. Bo%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^es are strewn about "
      "the %^BOLD%^%^BLACK%^floor, B%^BOLD%^%^RED%^loo%^BOLD%^%^BLACK%^d "
      "covers the walls. Sk%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^ll tables "
      "lie on both sides %^BOLD%^%^BLACK%^of the room. A table formed from "
      "a Black M%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^t "
      "lies in the %^BOLD%^%^BLACK%^center of the room, B%^BOLD%^%^RED%^loo"
      "%^BOLD%^%^BLACK%^d drips from the table. You feel %^BOLD%^%^BLACK%^"
      "right at home.");

    set_exits( ([
	"north" : AoD"helgrath/store",
        "south" : AoD"helgrath/oilshop", 
	"out" : "/d/helgrath/rooms/cabin",
        "down" : AoD"helgrath/portal",
      ]));
    oi = new("/std/bboard");
    oi->set_name("Blood Board");
    oi->set_id( ({ "board", "blood board", "darkness board" }) );
    oi->set_board_id("Blood_Board");
    oi->set_max_posts(100);
    oi->set_edit_ok(GUILD_D->post_able("AoD"));
    oi->set_location(AoD"helgrath/hall");
    oi->set("short", "%^BOLD%^%^BLACK%^B%^BOLD%^%^RED%^loo%^BOLD%^%^BLACK%^d"
      " B%^BOLD%^%^RED%^oar%^BOLD%^%^BLACK%^d%^RESET%^");
    oi->set("long", "%^BOLD%^%^BLACK%^The Army of Darkness spreads the news "
      "of the kills with this board.%^RESET%^");


}

