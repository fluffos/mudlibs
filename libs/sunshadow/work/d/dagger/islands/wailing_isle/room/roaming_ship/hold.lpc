// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Cargo Hold

#include <std.h>
#include "../../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("the cargo hold");
    set_short("The Cargo Hold");
    set_long("%^RESET%^%^CRST%^%^C058%^This is a %^C059%^bleak%^C058%^ area of the ship where goods to be carted off to far away destinations are stashed, and where supplies for the long sea journey ahead are kept. The broad hold is nearly empty presently, although there are a few %^C101%^crates%^C058%^ and %^C101%^barrels%^C058%^ tucked here and there, as well as some %^C060%^empty cages%^C058%^ that are likely used to hold livestock. The %^C065%^d%^C066%^a%^C060%^m%^C059%^p %^C065%^f%^C066%^l%^C060%^o%^C059%^o%^C065%^r%^C058%^ is not nearly as well kept as the rest of the ship, and shows certain signs of a %^RESET%^%^C064%^ro%^C059%^de%^C064%^nt in%^C059%^f%^C064%^e%^C059%^sta%^C064%^t%^C059%^i%^C064%^on%^RESET%^%^C058%^. The %^C059%^moist scent%^C058%^ of the %^C024%^sea%^C058%^ mingled with the stench of %^C244%^livestock%^C058%^ and other %^C064%^pu%^C070%^ng%^C064%^en%^C070%^t o%^C064%^do%^C070%^rs%^RESET%^%^C058%^ makes your eyes water.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C064%^D%^C065%^a%^C064%^mp a%^C065%^n%^C064%^d r%^C065%^o%^C064%^tt%^C065%^e%^C064%^n, t%^C065%^h%^C064%^e sm%^C065%^e%^C064%^ll is b%^C065%^a%^C064%^re%^C065%^l%^C064%^y t%^C065%^o%^C064%^lera%^C065%^bl%^C064%^e.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C060%^The ship %^C061%^groans%^C060%^ and %^C061%^creaks%^C060%^ as waves clap against its hull.%^CRST%^");
    set_items(([
        ({"crates", "barrels", "cages"}) : "%^RESET%^%^CRST%^%^C100%^The cargo is lashed in place to ward against being shifted about the hold with the sway of the ship, though a few %^C101%^crates%^C100%^ sit out haphazardly while docked. The %^C243%^cages%^C100%^ are empty now, but some %^C250%^feathers%^C100%^ and the stench of %^C058%^chicken stool%^C100%^ gives a good indication of what has been kept here.%^CRST%^",
		"floor" : "%^RESET%^%^CRST%^%^C064%^The floor has probably never seen a dry day since this ship's maiden voyage. %^C058%^Bilge rats%^C064%^ scurry about, hiding in the %^C059%^dark spaces%^C064%^ between the cargo.%^CRST%^",
        ]));
    set_exits(([
        "up" : SHIP"hallway",
        ]));
    set_search("crates", (:this_object(),"search_crates":));
}

void search_crates(){
    object player, crate;
    
    player = this_player();
    if(player->query("wailing isle quest") != 11 ){
        tell_object(player, "You don't see anything of interest among the crates.");
        return;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^There it is, the %^C136%^case of %^C130%^rum %^C101%^that Mae mentioned. You slide it out from the rest of the cargo and set it on the floor of the hold.%^CRST%^");
    crate = new(OBJ"crate");
    crate->move(environment(player));
    player->set("wailing isle quest", 12);
    return;
}

