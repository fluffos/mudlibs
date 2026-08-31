#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
mapping players;
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
    set_name("Guild TOwn Prayer Room");
    set_short("Guild Prayer Room");
    set_long("%^RESET%^%^ORANGE%^%^This is a small cave that holds a small %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^terfall%^RESET%^%^ORANGE%^. Water trickles down the walls into a pool of %^BOLD%^%^WHITE%^crystal clear water%^RESET%^%^ORANGE%^. Small %^BOLD%^%^WHITE%^s%^CYAN%^p%^WHITE%^arkl%^CYAN%^e%^WHITE%^s %^RESET%^%^ORANGE%^of light looking almost like falling %^BOLD%^%^WHITE%^g%^CYAN%^l%^WHITE%^itt%^CYAN%^e%^WHITE%^r %^RESET%^%^ORANGE%^float across the water. Travelers come from many places to %^CYAN%^enter%^ORANGE%^ this %^CYAN%^pool%^ORANGE%^ of water.%^RESET%^");
    set_listen("default", "The sound of a soft falling water filters the area.");
    set_items((["cave" : "The cave is small and holds a pool of water.", "water" : "The water trickles down the walls into the pool.", "pool" : "The pool looks like it could be entered.", "walls" : "The walls are littered with falling water.", "waterfall" : "The waterfall falls hard into the pool." ]));
    set_exits((["west" : GROOM"board_room"]));
}
void init() {
    ::init();
    add_action("enter_pool", "enter");
}
int enter_pool() {
    int x;
    if(this_player()->query_money("platinum")<50) {
	notify_fail("A platinum coin with a 50 in the center floats up from the bottom of the pool, then falls back down into the water.\n");
	return 0;
    }
    else
    {
	this_player()->add_money("platinum", -50);
	message("room", this_player()->query_cap_name()+" throws a coin into the water, and the water begins to swirl."
	  ,environment(this_player()),this_player());
	message("tp", "You throw 50 platinum coins into the enchanted pool.",this_player());
    }
    x = this_player()->query_max_hp() - this_player()->query_hp();
    this_player()->add_hp(x);
    x = this_player()->query_max_sp() - this_player()->query_sp();
    this_player()->add_sp(x);
    x = this_player()->query_max_mp() - this_player()->query_mp();
    this_player()->add_mp(x);
    this_player()->set_paralyzed(3);
    write("%^BOLD%^%^YELLOW%^Your body feels regenerated.%^RESET%^");
    return 1;
}
