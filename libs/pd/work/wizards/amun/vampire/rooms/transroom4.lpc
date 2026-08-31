#include <std.h>
#include <sindarii.h>
#include <vampq.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set("short", "Layer");
    set_long("%^BOLD%^%^BLACK%^The bottom area of the lair is black as night. The only thing that can be seen is a black stone altar that is placed in the middle of the room. The altar is %^RED%^glowing %^BLACK%^softly as if inviting anyone around to move closer for a better look. There is no sound in the room at all, it is as if all life does not exist.%^RESET%^");
    set_items((["altar" : "%^BOLD%^%^BLACK%^The st%^RED%^o%^BLACK%^ne al%^RED%^t%^BLACK%^ar sits in the middle of the room. It is beckoning anyone around to come forward. It's so pretty to look at, but how does it feel to the touch?%^RESET%^" ]));
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

void init() {
    ::init();
    add_action("cmd_suck", "suck");
}
int start_fmv(string str) {

    write("%^BOLD%^%^RED%^A seductive voice begins to speak.%^RESET%^ \n\n");
    destination = str;
    switch (destination) {
    case "vampire":
	time = 9;
	call_out("vampire1", time);
	break;
    }
}
int vampire1() {
    write("%^BOLD%^%^WHITE%^'%^BLACK%^Long ago we Vampires were made, and long ago we were forgotten.%^RESET%^ \n\n %^BOLD%^%^BLACK%^In the shadows we've always been, and in the shadows we've drank.%^RESET%^ \n\n %^BOLD%^%^BLACK%^Drank those who drove us away, and drank those that were lesser to our powers.%^RESET%^\n\n");
    call_out("vampire2", time);
}

int vampire2() {
    write("%^BOLD%^%^BLACK%^Now you stand in fear wondering where I am.%^RESET%^ \n\n %^BOLD%^%^BLACK%^I am in the darkness that lies within you.%^RESET%^ \n\n %^BOLD%^%^BLACK%^Tell me, do you wish to have the power of the night? The power of the shadows? The power of the darkness?%^RESET%^ \n\n %^BOLD%^%^BLACK%^Do you wish to be Immortalized and ripped of your human flesh? Forever walking as a creature of the night.%^RESET%^ \n\n %^BOLD%^%^BLACK%^Say yes and you shall be free. Say no and you shall die.%^WHITE%^'%^RESET%^\n\n");
    input_to("confirm_response");
}
int confirm_response(string str) {
    int maxhp, newhp;
    if (str == "no") {
	write("%^BOLD%^%^RED%^Your stomach begins to to churn and you feel as though something is trying to rip it's way out!%^RESET%^ \n\n %^BOLD%^%^RED%^Leaving your stomach bloody and open, the bat you ate long ago slithers out of you.%^RESET%^ \n\n %^BOLD%^%^RED%^After turning into the Head Vampire, he looks at you with hatred in his eyes.%^RESET%^ \n\n %^BOLD%^%^RED%^With no warning he grabs your neck and bites you draining your blood, killing you.%^RESET%^");
	this_player()->die();
	return 1;
    }
    if (str != "yes") {
	write("That is not a valid choice.");
	return 0;
    }
    write("%^BOLD%^%^RED%^Your stomach begins to to churn and you feel as though something is trying to rip it's way out!%^RESET%^ \n\n %^BOLD%^%^RED%^Leaving your stomach bloody and open, the bat you ate long ago slithers out of you.%^RESET%^ \n\n %^BOLD%^%^RED%^After turning into the Head Vampire, he looks at you with triumph in his eyes.%^RESET%^ \n\n");
    call_out("vampire3", time);

}

int vampire3() {
    write("%^BOLD%^%^RED%^The Vampire transfixes you with his eyes and pulls you close to him.%^RESET%^ \n\n %^BOLD%^%^RED%^He grabs your neck and whispers in your ear, %^WHITE%^'%^BLACK%^Your blood will boil, your blood will churn. After two nights in the realm you will have fully healed. If you leave your grave before then, you will cease to exist and your transformation will not take place.%^WHITE%^'%^RESET%^ \n\n");
    call_out("vampire4", time);
}


int vampire4() {
    write("%^BOLD%^%^RED%^With that he lowers his head and bites your neck.%^RESET%^ \n\n %^BOLD%^%^RED%^Sucking your life from you, making you feel as if you are just his prey.%^RESET%^ \n\n %^BOLD%^%^RED%^Just before you die he stops and pulls back his cloak and slits his wrist with his fingernail.%^RESET%^ \n\n %^BOLD%^%^WHITE%^'%^BLACK%^Feed off of my blood and you will become immortal. All you have to do is suck my blood.%^WHITE%^'%^RESET%^ \n\n");
    return 1;
}
int cmd_suck(string str) {
    if (!str || str == "" || str != "blood") return notify_fail("Suck what?\n");
    write("%^BOLD%^%^RED%^You suck the Vampire's blood and feel your blood boil.%^RESET%^ \n\n %^BOLD%^%^RED%^You are left weakend.%^");
    this_player()->set_hp(20);
    this_player()->move(ROOMS"cemetary/coffin7");

    return 1;
}
