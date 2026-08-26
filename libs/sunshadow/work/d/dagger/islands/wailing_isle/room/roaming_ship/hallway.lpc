// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Hallway

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
    set_name("below deck");
    set_short("%^RESET%^%^CRST%^%^C108%^Below Deck of a Merchant's Ship");
    set_long("%^RESET%^%^CRST%^%^C108%^Small %^C114%^gl%^C120%^as%^C156%^s sc%^C120%^onc%^C114%^es%^RESET%^%^C108%^ nestled into %^C109%^shallow alcoves%^C108%^ along the wall provide %^C114%^dim lighting%^C108%^ to this claustrophobic hallway. The walls and floor are made from unadorned %^C101%^wooden planks%^C108%^ that creak as the ship bobs on the water. A few %^C095%^mahogany doors%^C108%^ line the hall, each as uninteresting as the next as the passage leads onward, past the crew's quarters and into the galley. Austere stairs lead to the upper deck, while a short %^C101%^ladder%^C108%^ descends deeper into the bowels of the ship.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C130%^There is a lingering scent of %^C124%^meat%^C130%^ and %^C136%^spice%^C130%^ drifting in from the galley.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C138%^The gleaming walls creak in time with the rocking of the ship.%^CRST%^");
    set_items(([
        ({"sconces", "alcoves"}) : "%^RESET%^%^CRST%^%^C094%^Set into shallow alcoves, small %^C089%^f%^C088%^l%^C160%^a%^C166%^m%^C172%^e%^C178%^s%^RESET%^%^C094%^ dance within glass sconces, powered by %^C089%^magic%^C094%^ or %^C089%^alchemy%^C094%^.%^CRST%^",
		"doors" : "%^RESET%^%^CRST%^%^C095%^Each door, a sturdy mahogany fixture, looks quite the same as the other doors, and only %^C244%^silence%^C095%^ can be heard coming from behind them.%^CRST%^",
		({"steps", "ladder"}) : "%^RESET%^%^CRST%^%^C101%^You can go up to the main deck, or down into the ship's hold.%^CRST%^",
		({"walls", "floor"}) : "%^RESET%^%^CRST%^%^C094%^The wooden planks retain the level of sheen as the above deck.%^CRST%^",
        ]));
    set_exits(([
        "stairs" : SHIP"deck",
        "bunks" : SHIP"bunks",
        "down" : SHIP"hold",
        ]));
}

