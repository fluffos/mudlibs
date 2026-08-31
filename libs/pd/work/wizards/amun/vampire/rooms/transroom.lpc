#include <std.h>
#include <sindarii.h>
#include <vampq.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("Quest Vision");
    set_long("%^BOLD%^%^BLACK%^You are in a trance and can see nothing else.%^RESET%^");
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
void reset() {
    ::reset();
    if (!present("vampire"))
	new(ROOMS"cemetary/mon/vamp")->move(this_object());
}
int start_fmv(string str) {
    write("%^BOLD%^%^RED%^You are pulled into a vision.%^RESET%^");
    destination = str;
    switch (destination) {
    case "quest":
	time = 9;
	call_out("quest1", time);
	break;
    }
}
int quest1() {
    write("%^BOLD%^%^RED%^The Pale-skinned man shows you a player infront of a campfire that is one with nature.%^RESET%^ \n\n %^BOLD%^%^WHITE%^'%^BLACK%^You must find them and get a poisoning liquid of some kind. This is vital for continuing.%^WHITE%^'%^RESET%^\n\n");
    call_out("quest2", time);
}

int quest2() {
    write("%^BOLD%^%^RED%^You see yourself in a land of good, a land of the holy, in front of a hidden altar drenched in blood. In your hand is a vial.%^RESET%^ \n\n %^BOLD%^%^WHITE%^'%^BLACK%^Use it wisely and you will see.%^WHITE%^'%^RESET%^\n\n");
    call_out("quest3", time);
}

int quest3() {
    write("%^BOLD%^%^RED%^You see yourself consuming something with a look of disgust on your face and then the altar opens.%^RESET%^ \n\n %^BOLD%^%^WHITE%^'%^BLACK%^It must open for you to move on.%^WHITE%^'%^RESET%^\n\n");
    call_out("quest4", time);
}

int quest4() {
    write("%^BOLD%^%^WHITE%^'%^BLACK%^For helping me I will do one last thing.%^WHITE%^'%^RESET%^ \n\n %^BOLD%^%^RED%^The Pale-skinned man pulls out a blood stained fang from his pocket.%^RESET%^\n\n ");
    this_player()->move(ROOMS"cemetary/coffin7");
    this_player()->add_hp(-100);
    this_player()->add_sp(-200);
    this_player()->add_mp(-200);
    this_player()->set_paralyzed(5);
    return 1;
}
