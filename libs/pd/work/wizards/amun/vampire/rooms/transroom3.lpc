#include <std.h>
#include <vampq.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("In a Trance");
    set_long("%^BOLD%^%^RED%^You %^RESET%^are %^BOLD%^%^RED%^in %^RESET%^the %^BOLD%^%^RED%^a %^RESET%^trance %^BOLD%^%^RED%^and %^RESET%^can %^BOLD%^%^RED%^not %^RESET%^see %^BOLD%^%^RED%^anything %^RESET%^else%^BOLD%^%^RED%^.%^RESET%^");
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
    write("%^BOLD%^%^RED%^You are pulled into a trance by an unknown force.%^RESET%^");
    destination = str;
    switch (destination) {
    case "vision":
	time = 9;
	call_out("vision1", time);
	break;
    }
}
int vision1() {
    write("%^BOLD%^%^BLACK%^A small voice begins to speak inside your head.%^RESET%^\n\n\n\n\n");
    call_out("vision2", time);
}

int vision2() {
    write("%^BOLD%^%^WHITE%^'%^RED%^You are probably wondering why you were brought here.%^RESET%^ \n\n\n%^BOLD%^%^RED%^You have passed the gate of %^BLACK%^f%^WHITE%^a%^BLACK%^ngs%^RED%^.%^RESET%^\n\n\n\n\n");
    call_out("vision3", time);
}

int vision3() {
    write("%^BOLD%^%^RED%^You have proven yourself worthy thus far in becoming a Vampire, but in the road ahead you must really choose.%^RESET%^ \n\n\n%^BOLD%^%^RED%^A choice to become a %^BLACK%^creature of the night%^RED%^, or stay immortal and shun our ways.%^RESET%^\n\n\n\n\n");
    call_out("vision4", time);
}

int vision4()
{
    write("%^BOLD%^%^RED%^By passing the gate, you have earned your %^BLACK%^f%^WHITE%^a%^BLACK%^ngs%^RED%^.%^RESET%^ \n\n\n%^BOLD%^%^Use them wisely, or die a painful death.'%^RESET%^ \n\n\n%^BOLD%^%^BLACK%^You awake from your vision.%^RESET%^\n\n\n\n\n");
    this_player()->move(VR"tier1_1");
    this_player()->add_hp(-200);
    this_player()->add_sp(-200);
    this_player()->add_mp(-200);
    this_player()->set_paralyzed(5);
    return 1;
}
