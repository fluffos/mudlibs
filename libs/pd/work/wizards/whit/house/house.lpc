//  Whits House

#include <std.h>
#include <daemons.h>

inherit OBJECT;

int lock;

void create() {
    ::create();
    set_name("whits house");
    set_short("Whit's House");
    set_long("This is Whit's house.  A sign on the door to Whit's house says: "
      "\"For those who wish to enter must recite the words of the ages which will "
      "only appear in the morning.\"  A small golden plaque lays on the ground.");
    set_id(({ "house", "whit house", "whits house", "whit's house" }));
    lock=1;
}

void init() {
    ::init();
    add_action("enter", "enter");
    add_action("recite", "recite");
    add_action("read", "read");
}

string query_long() {
    if(EVENTS_D->query_time_of_day() != "dawn")
	return "This is Whit's house.  A sign on the door to Whit's house says: "
	"\"For those who wish to enter must recite the words of the ages which will "
	"only appear in the morning.\"  A small golden plaque lays on the ground.";
    return "This is Whit's house.  A sign on the door to Whit's house says: "
    "\"For those who wish to enter must recite the words of the ages which will "
    "only appear in the morning.\"  A small golden plaque with gold "
    "letteringlays on the ground.";
}

int enter(string s) {
    if(!s || !this_object()->id(s)) return notify_fail("Enter what?\n");
    if(lock) {
	write("The door is locked.\n");
	message("", this_player()->query_cap_name()+" fails to enter.", 
	  environment(this_player()), ({ this_player() }));
	return 1;
    }
    this_player()->move_player("/wizards/whit/house/entrance", "into the house");
    return 1;
}

int recite(string s) {
    int ok=1;

    if(!s || lower_case(s)!="inari farcavi") ok=0;
    if(!s || s=="") return notify_fail("Recite what?\n");
    if(!ok || !lock) {
	write("%^BOLD%^%^CYAN%^You recite:%^RESET%^  "+s+", but nothing happens.");
	message("", "%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()+
	  " recites: %^RESET%^ "+s+", but nothin happens.", 
	  environment(this_player()), ({ this_player() }));
	return 1;
    }
    write("%^BOLD%^%^CYAN%^You recite:%^RESET%^  "+s+"");
    message("", "%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()+
      " recites: %^RESET%^ "+s+"", 
      environment(this_player()), ({ this_player() }));
    message("", "Something clicks next to the house.", environment(this_object()));
    lock=0;
    return 1;
}

void reset() {
    ::reset();
    if(!lock) message("", "Something clicks next to the house.", environment(this_object()));
    lock=1;
}

int read(string s) {
    if(!s || s!= "plaque") return notify_fail("Read what?\n");
    if(EVENTS_D->query_time_of_day() != "dawn") return notify_fail("There is "
	  "nothing on the plaque.");
    write("The text reads:\n\n");
    write("     By the light of the dawn, one will read the ancient text and gain "
      "entrance to the house.  By speaking \"Inari Farcavi\" one shall gain "
      "entrance.");
    return 1;
}

