#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_west", "west");
}
void create() {
    ::create();
    set_short("store");
    set_long("%^BOLD%^%^RED%^The heat from the forge at the center of this "
      "room is intense %^BOLD%^%^RED%^and the glow %^BOLD%^%^YELLOW%^ill"
      "%^RESET%^%^ORANGE%^umi%^BOLD%^%^RED%^nates the room, throwing "
      "dancing %^BOLD%^%^BLACK%^shadows%^BOLD%^%^RED%^ %^BOLD%^%^RED%^upon "
      "the walls. Weapons in various stages of repair stand in %^BOLD%^"
      "%^RED%^racks. Flint stands over his forge %^BOLD%^%^YELLOW%^pou"
      "%^RESET%^%^ORANGE%^nd%^BOLD%^%^RED%^ing on the edge of a %^BOLD%^"
      "%^RED%^giant battle axe, cursing loudly every now and then as sweat "
      "%^BOLD%^%^RED%^pours down his face and his muscles strain with "
      "effort. The loud%^BOLD%^%^RED%^%^BOLD%^%^YELLOW%^rin%^RESET%^"
      "%^ORANGE%^gi%^BOLD%^%^RED%^ng of his hammer can be heard all "
      "throughout the guild. %^RESET%^");
    set_items(([
	"forage" : "%^BOLD%^%^YELLOW%^Illuminates the room.%^RESET%^",
	"axe" : "%^BOLD%^%^RED%^A battle axe worn from battle.%^RESET%^"]) );
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
    set_exits(([
	"south" : AoD"hall"
      ]));
}

void reset() {
    ::reset();     
    if(!present("flint"))
	new(AoD"mon/flint")->move(this_object());
}

int go_west() {
    if(!wizardp(this_player())) {
	message("my_action", "Flint holds you back.",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is held back from going west.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}

