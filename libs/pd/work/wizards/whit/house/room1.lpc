//  Whits House

#include <std.h>
#include <daemons.h>

inherit ROOM;

int open;
int ct=6;
string *dawn= ({"^",">","<",">","^",">"});
string *day=  ({">",">","<","<","<","^"});
string *dusk= ({"^",">",">","<","^",">"});
string *night=({"<","<","^",">",">","<"});
string *cur;

int query_open() { return open; }
void set_open(int i) { open=i; }

void create() {
    ::create();
    set_name("whits house");
    set_short("Whit's House");
    set_exits(([ "up":"/wizards/whit/house/entrance"]));
    open=0;
    cur=({});
}

string query_long() {
    if(!open)
	return "The tunnel seems a bit small.  Standing to the north "
	"is a large stone door.  Carvings of an unknown language "
	"cover the door.  The door is surrounded by 3 touch stones, "
	"one being to the left, right, and above the door.  A "
	"stone tablet is on a pedistal to the right of the door.";
    return "The tunnel seems a bit small.  Standing to the north "
    "is a large opening from which a door once stood blocking "
    "passage.  The opening is surrounded by 3 touch stones, "
    "one being to the left, right, and above the opening.  A "
    "stone tablet is on a pedistal to the right of the opening.";
}

void init() {
    ::init();
    add_action("touch", "touch");
    add_action("look", "look");
}

int touch(string s) {
    string tim;
    string *c;
    tim=EVENTS_D->query_time_of_day();
    if(open) return notify_fail("The door is already open.\n");
    switch(s) {
    case "<":
    case ">":
    case "^":
	break;
    default: write("Touch which stones? (indicate with the arrow symbols)\n"); return 1; break;
    }
    switch(tim) {
    case "dawn":
	c=dawn;
	break;
    case "day":
	c=day;
	break;
    case "dusk":
	c=dusk;
	break;
    case "night":
	c=night;
	break;
    }
    cur += ({s});
   write("You touch the stone in the direction of "+s+".");
    say(this_player()->query_cap_name()+" touchs the stone in the direction of "+s+".\n");
    if(sizeof(cur) >= sizeof(c)) {
	if(implode(cur, "") != implode(c, "")) {
	    write("The writing on the stone tablet disappears.\n");
	    say("The writing on the stone table disappears.\n");
	    cur=({});
	    return 1;
	}
	message("", "The door opens.\n", this_object());
       "/wizards/whit/house/room2"->add_exit("/wizards/whit/house/room1", "south");
	open=1;
	add_exit("/wizards/whit/house/room2", "north");
	cur=({});
	return 1;
    }
    message("", "The symbol "+s+" appears on the stone tablet.\n", this_object());
    return 1;
}

int look(string s) {
    int i;
    string out;
    if( s!="door" && s!="tablet") return 0;
    if(s=="tablet") {
	if(cur==({}) || !cur || !sizeof(cur)) {
	    write("There is nothing on the tablet.\n");
	    return 1;
	}
	out="The tablet displays: ";
	for(i=0; i < sizeof(cur); i++) out += cur[i]+" ";
	out += "\n";
	write(out);
	return 1;
    }
    if(open) return 0;
    write("The language on the door is unknown, however, some of the text is "
      "descernable:");
    write(@ENDTEXT
    D.a.      ^
              |>
             <|
              |>
	      ^
              |>
    .ay       |>
              |>
             <|
             <|
             <|
              ^
    d...      ^
              |>
              |>
             <|
              ^
              |>
    .igh.    <|
             <|
              ^
              |>
              |>
             <|

ENDTEXT);
    return 1;
}
void reset() {
   ::reset();
   if(open) message("", "The door slides back closed.\n", this_object());
   open=0;
}


