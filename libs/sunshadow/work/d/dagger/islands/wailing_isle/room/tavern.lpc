// Chernobog & Titania (2/2/22)
// The Wailing Isle - General Store

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("The Tavern");
    set_short("%^RESET%^%^CRST%^%^C246%^The Tavern%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C246%^Your senses are assaulted by an onslaught of %^C064%^ex%^C058%^ec%^C059%^ra%^C065%^bl%^C064%^e s%^C058%^ce%^C059%^nt%^C065%^s%^RESET%^%^C246%^ and a %^C060%^ra%^C059%^mbun%^C060%^ct%^C059%^ious %^C060%^co%^C059%^ngre%^C060%^ga%^C059%^tion%^RESET%^%^C246%^ in this old tavern. %^C058%^Archways%^RESET%^%^C245%^ made from %^C101%^strong wood%^C246%^ and %^C243%^st%^C059%^o%^C243%^ne%^RESET%^%^C246%^ loom over a %^C243%^battered%^C246%^ collection of %^C058%^tables%^C246%^ and %^C058%^benches%^C246%^. The floor is covered in a layer of %^C101%^s%^C100%^a%^C101%^nd%^RESET%^%^C246%^ that someone long ago gave up on sweeping. A %^C059%^ha%^C243%^z%^C244%^e of sm%^C243%^o%^C059%^ke%^RESET%^%^C246%^ drapes the room, shrouding the %^C059%^h%^C058%^ea%^C059%^vy %^C058%^wo%^C059%^od%^C058%^en c%^C059%^ha%^C058%^n%^C059%^d%^C058%^el%^C059%^ie%^C058%^rs%^RESET%^%^C246%^ that hang from the ceiling. They provide the only lighting to the dim room beyond what manages to filter in through the %^C243%^s%^C244%^m%^C245%^u%^C243%^dg%^C245%^e%^C243%^d w%^C245%^i%^C243%^nd%^C244%^o%^C245%^w%^C243%^s%^RESET%^%^C246%^.\n%^CRST%^");
    set_smell("default","%^CRST%^%^RESET%^%^C144%^It smells like %^C094%^cheap booze%^C144%^, %^C243%^tobacco smoke%^C144%^ and %^C245%^unwashed bodies%^C144%^.%^CRST%^");
    set_listen("default","%^CRST%^%^RESET%^%^C146%^Songs %^C139%^and %^C146%^bawdy laughter%^C139%^ rise over the %^C138%^drunken clamor%^C139%^ of the crowd.%^CRST%^");
    set_items(([
        ({"tables", "chairs", "barrels", "benches"}) : "%^RESET%^%^CRST%^%^C094%^The tables are made from thick, sturdy wood, but they are old and have seen better days. Their surfaces are now scarred with the wounds of several brawls, and stained with decades' worth of spills. Around the tables are situated some old chairs, benches and barrels, whatever gets the job done.%^CRST%^",
        "walls" : "%^RESET%^%^CRST%^%^C060%^Are the walls half painted, or half peeled? It's clear they have seen much in their time, with crumbling pockets hastily patched up or simply covered with %^C101%^wood planks%^C060%^.%^CRST%^",
        "windows" : "%^RESET%^%^CRST%^%^C243%^The wide windows across the front of the tavern have been locked behind wrought iron bars, likely to keep anyone from falling through them. However, the smudged glass is cracked in places, and you even notice some damage that looks suspiciously like bullet holes.%^CRST%^",
        ({"bar", "bar top"}) : "%^RESET%^%^CRST%^%^C075%^Though cracked beyond repair, the surface of the bar is covered in patterned %^C074%^g%^C073%^r%^C072%^e%^C071%^e%^C072%^n and b%^C073%^l%^C074%^u%^C068%^e t%^C073%^i%^C072%^l%^C071%^e%^RESET%^%^C075%^ that was probably very nice once upon a time.%^CRST%^",
        "chandeliers" : "%^RESET%^%^CRST%^%^C058%^Fashioned from old ship's steering wheels, they are suspended by %^C059%^iron chains%^C058%^ from the ceiling. Wax %^C243%^candles%^C058%^ have been affixed to the extending spokes, left to melt and ooze around the wood as they struggle to light the %^C059%^gloom%^C058%^.%^CRST%^",
        ({"parrot", "turnbuckle"}) : "%^RESET%^%^CRST%^%^C158%^This old %^C160%^c%^C088%^o%^C160%^l%^C154%^o%^C155%^r%^C154%^f%^C082%^u%^C083%^l %^C083%^m%^C160%^a%^C088%^c%^C160%^a%^C154%^w%^RESET%^%^C158%^ always has to get in the last word. He's been Astley's faithful companion for as long as anyone can remember.%^CRST%^",
        ({"floor", "sand"}) : "%^RESET%^%^CRST%^%^C021%^The %^C019%^blue tiled%^C021%^ floor is lost beneath the %^C100%^sand%^C021%^ and %^C100%^dirt%^C021%^ tracked in over the years.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"marketsquare",
        ]));
}

void reset(){
    if(!present("astley")) new(MON"astley")->move(this_object());
    if(!present("grace")) new(MON"grace")->move(this_object());
}

