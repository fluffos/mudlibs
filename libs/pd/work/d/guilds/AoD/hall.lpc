#include <daemons.h>
#include <std.h>
#include <guild.h>

inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
}

void create() {
    object oi;
    ::create();
    set_name("Army of Darkness");
    set_items((["bones"   : "Human bones",
        "blood"   : "%^BOLD%^%^RED%^Thick human blood%^RESET%^",             
        "walls"  : "%^BOLD%^%^RED%^Blood covers the black marble%^RESET%^",        
        "tables"   : "Tables made from human skulls", 
        "table"   : "%^BOLD%^%^BLACK%^A table formed from a black mist, is covered with thick human %^BOLD%^%^RED%^blood%^RESET%^",
        "floor"  : "%^BOLD%^%^RED%^BLOOD BLOOD BLOOD%^RESET%^"]));   

    set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no teleport" : 1,
        "no scry" : 1,
        "indoors" : 1,
        "no steal"    : 1 ]) );

    set_short("Army of Darkness");

    set_long("%^BOLD%^%^BLACK%^The Dark%^RESET%^%^WHITE%^ne%^BOLD%^%^WHITE%^ss%^BOLD%^%^BLACK%^ surrounds you. The Ar%^RESET%^%^WHITE%^m%^BOLD%^%^BLACK%^y of Dark%^RESET%^%^WHITE%^ne%^BOLD%^%^WHITE%^ss%^BLACK%^ comes here%^RESET%^ "
"%^BOLD%^%^BLACK%^to converse on the lastest kills. Bo%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^es are strewn about the%^RESET%^ "
"%^BOLD%^%^BLACK%^floor, B%^BOLD%^%^RED%^loo%^BOLD%^%^BLACK%^d covers the walls. Sk%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^ll tables lie on both sides%^RESET%^ "
"%^BOLD%^%^BLACK%^of the room. A table formed from a Black M%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^t lies in the%^RESET%^ "
"%^BOLD%^%^BLACK%^center of the room, Blood drips from the table. You feel%^RESET%^ "
"%^BOLD%^%^BLACK%^right at home.%^RESET%^");

    set_exits( ([
        "north" : AoD"store",
        "hall" : ALL"meeting",
        "south" : AoD"oilshop", 
        "west" : AoD"lockeraod",
        "out" : "/d/nopk/tirun/ghall",
        "down" : AoD"view_room",
        "east" : AoD"treasury",
      ]));
    oi = new("/std/bboard");
    oi->set_name("Blood Board");
    oi->set_id( ({ "board", "blood board", "darkness board" }) );
    oi->set_board_id("Blood_Board");
    oi->set_max_posts(100);
    oi->set_edit_ok(GUILD_D->post_able("aod"));
    oi->set_location(AoD"hall");
    oi->set("short", "%^BOLD%^%^BLACK%^B%^RED%^loo%^BLACK%^d B%^RED%^oar%^BLACK%^d%^RESET%^");
    oi->set("long", "%^BOLD%^%^BLACK%^The Army of Darkness spreads the news of the kills with this board.%^RESET%^");


}

int fstart(string str) {
    if (!str || str=="") {
        notify_fail("Start where?\n");
        return 0;
    }
    if (str!="here") {
        notify_fail("You cannot start there.\n");
        return 0;
    }
    if(this_player()->query_original_guild() == "illuminati")
        this_player()->set_primary_start("/d/guilds/illuminati/new/hall");
    else
    if(this_player()->query_original_guild() == "aod")
        this_player()->set_primary_start("/d/guilds/AoD/hall");
    else

this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}
