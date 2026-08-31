#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_short("a magnificent statue of a white dragon");
   set_name("statue");
   set_long("This statue is unique in that it is carved in %^BOLD%^white "
            "%^RESET%^marble. The form is that of a beautiful female dragon her features "
            "rendered in detail that can only be described as complete perfection. Her face "
            "is a complete mask of compassion and her crystal scales sparkle in the light adding "
            "to the tranquil feel radiating from the oddly warm marble. Just looking at the statue "
            "brings a warm feeling to your heart and you smile. For some reason, you want to lick it. "
            "\nBeneath it, a plaque, plated in solid "
            "gold is inscribed.");
   set_weight(1);
   set_value(0);
   set_id(({ "statue" }));
set_prevent_get("The statue is too heavy.");
}
int readPlaque(string what) {
    if (!what || what != "plaque") return 0;
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " reads over the plaque on the statue.", ({ this_player()}));
    write("The gold plaque reads: ");
    write("To Azire, we'll never forget your wit, your humor, and your ability to smack Hermes.");
    this_player()->force_me("smile warmly");
    return 1;
    }
int statueLick(string str)
{
	if(!str || str != "statue") return 0;
	write ("The statue licked you back, how odd! But at the same time, you can't help but smile and feel that little warm ball in you get a little larger as you stand there dripping from statue saliva\n");
	tell_room(environment(this_player()), this_player()->query_cap_name() + " licks the statue, which amazingly enough licks back.");
	this_object()->force_me("lick " + this_player()->query_cap_name());
	return 1;
}
    void init() {
    ::init();
    add_action("readPlaque", "read");
    add_action("statueLick", "lick");
    set_heart_beat(1);
    }
    
/*
    void heart_beat()
    {
    	tell_room(environment(this_player()), "The statue sneezes.", ({ this_player()}));
    }
*/
