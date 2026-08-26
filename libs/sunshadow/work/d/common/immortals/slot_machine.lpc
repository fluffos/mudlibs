// Chernobog (10/4/22)
// Slot Machine for Avatars

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_id(({"slot machine", "machine"}));
	set_name("slot machine");
	set_short("%^RESET%^%^CRST%^%^C060%^A slot machine%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C060%^Flashing lights and ringing bells decorate the slot machine. Go ahead and %^C255%^<play slots> %^C060%^to get a nice payout.%^CRST%^");
	set_weight(1000000);
	set_value(0);
	set_property("no animate",1);
}

void init(){
    ::init();
    add_action("slots_fun", "play");
}

int slots_fun(string str){
    if(!str) return 0;
    if(str != "slots") return 0;
    
    tell_object(this_player(), "Hey, you're a winner! Here's 5,000,000 gold coins.");
    tell_room(environment(this_object()), ""+this_player()->query_cap_name()+" is playing the slot machine!", this_player());
    this_player()->add_money("gold", 5000000);
    return 1;
}

