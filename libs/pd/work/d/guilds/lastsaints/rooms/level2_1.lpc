#include <std.h>
#include <amun.h>
#include <guild.h>
inherit ROOM;
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
    set_name("Last Saints Prayer Room");
    set_short("Last Saints Prayer Room");
    set_long("%^BOLD%^%^CYAN%^You walk into a massive cavern with a ceiling that is riddled with crystals and sharp rocks coming out of it. Infront of you is a crystal clear lagoon that is so deep you cannot see the bottom. There are tiny rain drops falling from mid air that feel as if they are purifying you. The room is full of large white rocks that glow allowing you to see its beauty, you see something on the rocks. Maybe you could %^WHITE%^enter %^CYAN%^the %^WHITE%^lagoon.%^RESET%^");
    set_smell("default", "The smell of rain fills the air.");
    set_listen("default", "The sound of a soft rain fills your ears.");
    set_items((["ceiling" : "The ceiling is gorgeous with crystals and rocks protruding from it.", "lagoon" : "The shallow pools are filled with perfectly clear water.", "rocks" : "%^BOLD%^%^WHITE%^And shepherds we shall be, for thee my Lord for thee, power hath descended forth from thy hand, that our feet may swiftly carry out thy command. We shall flow a river forth to thee, and teeming with souls shall it ever be. In nomine patrie, Et fili, Spiritus sancti.%^RESET%^" ]));
    set_exits((["northeast" : GUILDROOM"last_saints_board"]));
}
void init() {
    ::init();
    add_action("enter_lagoon", "enter");
}
int enter_lagoon() {
    int x;
    this_player()->add_hp(random(5));
    this_player()->add_sp(random(5));
    this_player()->add_mp(random(5));
    this_player()->set_paralyzed(3);
    write("%^BOLD%^%^YELLOW%^Your body feels regenerated.%^RESET%^");
    return 1;
}
