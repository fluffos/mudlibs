//Added to the Cevahir temple because of RP and expense by Uriah - Klieth
#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Cevahir Training Grounds");
   set_short("%^RESET%^%^MAGENTA%^Training Grounds%^RESET%^");
   set_long("%^C167%^A huge training ground unfolds before you. Individuals and small organized groups run and take part in %^C186%^exercise %^C167%^to improve their strength and endurance. You can see as you scan the area that %^C019%^soldiers%^C167%^, %^C196%^adventurers%^C167%^, and %^C190%^mercenaries%^C167%^ alike are making good use of the facilities and trainers that are available. There are individual areas where professional highly skilled trainers work to improve participants skills in various %^C093%^close combat %^C167%^weapons and what combinations work and don't work well against different types of armor and how to disarm most any opponents. The the north lies a %^C222%^archery range %^C167%^for perfecting ranged weapon skills including archery, crossbow, and javelin. The the south, a %^C065%^training dummy %^C167%^can be seen. Opposite the weapons training areas are stations to improve one's skills with a shield both defensively and offensively. Next to it is an area that teaches unarmed combat. Beyond this is a %^C036%^large field %^C167%^with walls and terrain features for small group training in both offensive and defensive maneuvers in how to best use terrain to one's advantage or make it an oppenent's disadvantage and taking or defending a wall. Small group tactical situations can be worked and reworked here. A small group makes it's way around the complex and %^C028%^field areas %^C167%^taking particular interest in places that might give good cover and advantageous view positions. %^CRST%^%^RESET%^\n");
   set_items(([
      ({"cliff","sea","ocean"}) : "The flat, rocky outcropping overlooks the sea hundreds of feet below. The sparkling waves of the ocean stretch as far as the eye can see.",
      ({"marble","white marble","floor","ceiling"}) : "This building is crafted from white marble shot through here and there with subtle veins of %^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e%^RESET%^ that seem almost out of place, given the color scheme of the temple. Those who know their history might recognize the marble as a relic of the temple to the departed moon goddess that once stood here.",
      ({"walls","wall","mosaic","mosaics"}) : "Most of the walls of the temple are covered with inlaid mosaics made from polished and painted fragments. A closer look reveals that the pieces seem to be an eclectic collection of items - pottery, stone, and even metal. They have been artfully arranged to depict different battlefields, complete with various styles of armor, weapons, and combat.",
      ({"wall hanging","wall hangings"}) : "Crafted from rich %^MAGENTA%^purple velvet%^RESET%^, the slender wall hangings offer pops of color along the white walls framing the square archways. Each has a border of %^BOLD%^white %^RESET%^bound by %^ORANGE%^thread of g%^YELLOW%^o%^RESET%^%^ORANGE%^ld %^RESET%^. The slim rectangles dangle from %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den rods%^RESET%^ and narrow to a delicate point, ending in %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d fringe%^RESET%^.",
      ({"altar","marble altar","helm","crested helm","sword","greatsword","bowl","golden bowl"}) : "The %^MAGENTA%^ma%^BOLD%^r%^RESET%^%^MAGENTA%^ble a%^BOLD%^l%^RESET%^%^MAGENTA%^tar %^RESET%^is deep purple shot though with lighter veins and flecks of %^RESET%^%^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^. It has been carved smooth and is spartan in design, supporting a wide but shallow %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den b%^RESET%^%^ORANGE%^o%^BOLD%^wl %^RESET%^filled with a smattering of offerings including game pieces carved from gemstones and gold coins from faraway lands. Beside the bowl is a battered helm with a %^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple p%^BOLD%^l%^RESET%^%^MAGENTA%^ume%^RESET%^. Strangely, the helm has no opening for the face, not even a narrow eye slit. Driven into the marble is a towering greatsword that seems nearly as wide as a halfling with an enormous %^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^th%^RESET%^y%^MAGENTA%^st %^RESET%^set into the pommel. Hanging from the crossguard is a simple sign bearing Cevahir's charge.",
      ({"chair","chairs"}) : "Like much of the temple, the chairs are somewhat impressive in their simplicity. They are crafted from burnished oak that gleams like gold, and thin %^MAGENTA%^purple cushions %^RESET%^line their seats. The backs are fitted with %^BOLD%^white %^RESET%^fabric hangings lined in %^MAGENTA%^purple %^RESET%^and %^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^, each bearing the symbol of Cevahir. During ceremonies, these chairs are filled with the ranking priests of the Warlord.",
      ({"candlestick","candlesticks"}) : "The golden candlesticks are fashioned to look like greatswords poised tip down, just like the one on the altar. Each holds a single thick pillar candle in brilliant white",
      ({"pew","pews"}) : "Crafted from burnished oak, the pews are arranged in rigid rows to offer seating to many members of the faith.",
      ({"case","glass case","weaponry","armor"}) : "The %^CYAN%^glass case %^RESET%^along the northern wall seems to be of gnomish make, given its transparency and impeccable design. The true treasure lies inside, where weapons and pieces of armor from all across the realms are on display alongside small markers detailing their origin.",
      ({"table","colorful figures","figures","maps"}) : "The simple oak table to the south is rectangular and surrounded by several stools. Its surface is covered with a stack of maps, some old and weathered, others new and pristine. A woven basket perched on the edge has carved wooden pieces in a variety of colors and shapes so that the faithful can strategize the placement of different units in battle."
   ]));
   set_smell("default","The salty sea air carries an occasional whiff of incense and oil.");
   set_listen("default","The distant sound of the ocean is obscured by the clash of weapons and the murmur of voices.");
   set_exits(([
	  "west": "/d/magic/temples/cevahir/cevahir",
	  "south": "/d/magic/temples/cevahir/dummyroom",
	  "north": "/d/magic/temples/cevahir/archery",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
	if(avatarp(TP)) return 1;
	write("You realize that would be really dumb as you start to cross the line.");
	return 0;
}