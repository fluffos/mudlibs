/* This object is given to the player and set autoloading when he/she
   leaves the game. It stores the original home of the player.
   It is used by any rooms which inherit /room/hotelroom. Please don't
   clone it, all settings will be done automatically by the hotelroom.
   (C) 1992 Randyandy@Nightfall */

#include <config.h>
#include <properties.h>
#include <stdrooms.h>

inherit "std/thing";

string hotelname, hotel_path, home;
int old_home;

varargs void create() {
	::create();
	SetShort("A Hotel-Card");
	AddId("hcard");
	AddId("card");
	AddId("hotelcard");
	AddId("hotel-card");
	SetLong(
"A hotel-Card. You can sleep at a hotel with it.\n");
        if (this_player()) {
        	hotelname = environment(this_player())->QueryHotelName();
        } else {
        	hotelname = environment(this_object())->QueryHotelName();
        }
        if(!hotelname) {
        	hotelname = "a hotel";
        }
        hotel_path = STARTROOM;
        /* This default setting will be overwritten */
        home = this_player()->QueryHome();
}

void simple_obj() { replace_program("/obj/hotelcard"); }

void init() {
	::init();
	call_out("wake_up",3);
}

int wake_up() {
	write("You wake up well rested in "+hotelname+". Welcome back to the game!\n");
	home=Query(P_AUTOOBJECT); /* Has been saved */
	this_player()->SetHome(home); /* Set the player's home back */
	call_out("zerstoere",1);
	return 1;
}

void zerstoere() {
	destruct(this_object());
}

void SetHotelFilename(string name, string path) {
	hotelname = name;
	hotel_path = path;
}

void SetNewHome(string str) {
	Set(P_AUTOOBJECT,(str)); /* Set this object as autoloading with
	                                the value str */
}
