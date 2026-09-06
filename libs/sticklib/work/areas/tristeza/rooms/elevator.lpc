#include "/sys/configuration.h"

#include <room.h>
#include <areas.h>
#include <generic_items.h>

#include <npc_defs.h>

object cash, boy;

#define STILL	0
#define DOWN	1
#define UP	2

int level;
int door_is_open;
int dest;
int moving_time;

status press(int i);
string tell_floor(int f);
status close_door();
status open_door();

status
talk(string str)
{
    tell_here("Boy says: " + str);
    return 1;
}

varargs string
query_SIR(object ob)
{
    int g;
    if (!ob && !(ob = this_player())) return "Sir";
    if ((g = (int) ob -> query_gender()) == G_MALE) return "Sir";
    else if (g == G_FEMALE) return "Mylady";
    else return "Mighty Worm";
}

void
init_room()
{
    if (!this_player() -> query_invis())
	call_out("greet", 1, this_player());
}

void
greet(object ob)
{
    if (!ob || environment(ob) != this_object()) return;
    talk("Greetings, " + query_SIR(ob) + ". Up or down?");
}

void
reset_room()
{
    door_is_open = 0;
    if (!cash) {
	cash = clone_object(GENERIC_MONEY_OBJECT);
	cash -> set_money(random(25) + 15);
	move_object(cash, this_object());
    }
}

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set_short("A strange small room");
    set_long("You are in a strange small room. On the wall is a lever.\
 A boy is here to operate the lever.");
    set_items(([
	"door" : "<who cares>",
	"boy" : "He is here to operate the lever.",
	"lever" : "Boy operates it."
      ]));
    set_commands(([
	"up"	: "up",
	"down"	: "down",
	"east"	: "go_east"
      ]));
    level = dest = 2;
    moving_time = 0;
    set(NO_PK);
    set(IN_CITY);
    reset_room();
}

status
query_closed_door()
{
    return !door_is_open;
}

varargs string
query_long(string str, object who)
{
    if (!str) return ::query_long(str, who) + "There is an "
	+ (door_is_open ? "open" : "closed") + " door to the east.";
    if (str == "door") {
	if (door_is_open) return "It is open.";
	else return "It is closed.";
    }
    return ::query_long(str, who);
}

status
up()
{
    if (level == 3)
	talk("But " + query_SIR() + ", there is no upper floor.");
    else if (moving_time > 0)
	talk("We are still moving, " + query_SIR() + ".");
    else {
	if (door_is_open) close_door();
	talk("Very well, " + query_SIR() + ".");
	press(level + 1);
    }
    return 1;
}

status
down()
{
    if (level == 1)
	talk("But " + query_SIR() + ", there is no lower floor.");
    else if (moving_time > 0)
	talk("We are still moving, " + query_SIR() + ".");
    else {
	if (door_is_open) close_door();
	talk("Very well, " + query_SIR() + ".");
	press(level - 1);
    }
    return 1;
}

status
press(int b)
{
    dest = b;
    if (dest > level) {
	moving_time = dest - level;
	tell_here("The room jerks upward.");
    }
    if (level > dest) {
	moving_time = level - dest;
	tell_here("The room starts moving downward.");
    }
    if (dest == 1 || level == 1) moving_time += 10;
    moving_time++;
    configure_object(this_object(), OC_HEART_BEAT, 1);
    return 1;
}

void
heart_beat()
{
    if (moving_time <= 0) return;
    moving_time--;
    if (moving_time > 0) {
	tell_here("Boy winds the lever and the room continues to move...");
	return;
    }
    configure_object(this_object(), OC_HEART_BEAT, 0);
    tell_here("The elevator slows down and stops.\n\
Boy says: Here we are! The " + tell_floor(dest) + ".");
    open_door();
    level = dest;
}

string
query_room(int floor)
{
    if (floor == 3) return AREA_TRISTEZA+"rooms/attic";
    if (floor == 2) return "/room/church";
    return AREA_TRISTEZA+"rooms/wiz_hall";
}

string
tell_floor(int floor)
{
    if (floor == 1) return "hall of the wizards";
    if (floor == 2) return "temple yard";
    return "tower";
}

status
open_door()
{
    door_is_open = 1;
    tell_here("Boy opens the door.", boy);
    query_room(dest)->tell_here("The door swings open.");
    return 1;
}

status
close_door()
{
    door_is_open = 0;
    tell_here("Boy closes the door.", boy);
    query_room(level)->tell_here("The door swings shut.");
    return 1;
}

status
go_east()
{
    if (moving_time > 0) this_player() -> tell_me(
	  "Boy says: " + query_SIR() + ", you can't go anywhere when the elevator is moving.");
    else if (!door_is_open) this_player() -> tell_me("The door is closed.");
    else this_player() -> move_player("east", query_room(level));
    return 1;
}

int
query_level()
{
    return level;
}

status
call_elevator(int button)
{
    if (door_is_open && button != level) close_door();
    if (moving_time > 0) {
	this_player() -> tell_me("Boy tells you: I have a customer with\
 me at the moment, " + query_SIR() + ".\nCould you please try again a little\
 later?");
	return 1;
    }

    dest = button;
    if (dest == level) {
	if (door_is_open) this_player() -> tell_me("Boy tells you: But "
	      + query_SIR() + ", I am there and the door is open.");
	else open_door();
	return 1;
    } else this_player() -> tell_me("Boy tells you: I will be there in a\
 moment, " + query_SIR() + ".");
    if (dest > level) moving_time = dest - level;
    if (level > dest) moving_time = level - dest;
    if (dest == 1 || level == 1) moving_time += 10;
    moving_time++;
    configure_object(this_object(), OC_HEART_BEAT, 1);
    return 1;
}

int
is_moving()
{
    if (level == dest) return 0;
    if (level > dest) return 1;
    return 2;
}

