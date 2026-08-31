#include <std.h>
#include <lodos.h>
#include <vampq.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("Inside the Mirror");
    set_long("%^BOLD%^%^WHITE%^You %^RESET%^are %^BOLD%^%^WHITE%^inside %^RESET%^the %^BOLD%^%^WHITE%^mirror. %^RESET%^Whisps %^BOLD%^%^WHITE%^of %^RESET%^thick %^BOLD%^%^WHITE%^liquid %^RESET%^swirl %^BOLD%^%^WHITE%^around %^RESET%^you%^BOLD%^%^WHITE%^.%^RESET%^");
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"no magic" : 1,
	"indoors" : 1,
	"outdoors" : 0,
	"no kill" : 1,
	"no attack" : 1,
	"no bump" : 1,
	"no steal" : 1
      ]));
}
int start_fmv(string str) {
    write("%^BOLD%^%^RED%^You are pulled into the mirror with an unknown force.%^RESET%^");
    destination = str;
    switch (destination) {
    case "mirror":
	time = 9;
	call_out("mirror1", time);
	break;
    }
}
int mirror1() {
    write("%^BOLD%^%^YELLOW%^Infront of you is a great %^BLACK%^Queen %^YELLOW%^surrounded by gold; she sits reading a %^BLACK%^black book%^YELLOW%^, while around her neck dangles a %^RED%^key%^YELLOW%^.%^RESET%^\n\n\n\n\n");
    call_out("mirror2", time);
}

int mirror2() {
    write("%^BOLD%^%^YELLOW%^Now you see a golden room filled with books.%^RESET%^\n\n\n\n\n");
    call_out("mirror3", time);
}

int mirror3() {
    write("%^ORANGE%^An island filled with crustations forms around you. Boats are either docked or wrecked on the land. The crabs seem to be moving away from one of the areas.%^RESET%^\n\n\n\n\n");
    call_out("mirror4", time);
}

int mirror4()
{
    write("%^BOLD%^%^RED%^You awaken from your vision feeling week.%^RESET%^\n\n\n\n\n");
    this_player()->move(ROOMS"secret3");
    this_player()->add_hp(-200);
    this_player()->add_sp(-200);
    this_player()->add_mp(-200);
    this_player()->set_paralyzed(5);
    return 1;
}
