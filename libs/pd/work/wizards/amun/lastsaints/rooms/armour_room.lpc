#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_west", "west");
}
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Saints Armoury");
    set_long(
      "%^BOLD%^%^YELLOW%^Last Saints Armory%^RESET%^\n"
      "%^BOLD%^%^WHITE%^This is a place for you to sell your armour and get money for your travels.  Conner has a list posted on the wall for all to read.%^RESET%^");
    set_items( ([ "shop": "This is a place for you to sell your armour and get money for your travels.", "sign": "Propety of Conner. All goods approved and commissioned for sale.", "list": "look_at_list" ]) );
    set_invis_exits( ( { "east", "west" } ) );    
    set_exits( ([ "northeast" : GUILDROOM+"level3_main", "west": GUILDROOM+"armour_storage" ]) );
}

void reset() {
    ::reset();
    if(!present("conner")) 
	new(GUILDMOB+"conner")->move(this_object());
}
int go_east() {
    if(!wizardp(this_player())) {
	message("my_action", "What are you thinking?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
