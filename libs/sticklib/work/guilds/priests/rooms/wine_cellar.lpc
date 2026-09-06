/* 
 * The Official Priest's Guild Pub!
 *        Opened June 29, 1994  -Kel.
 */

#include "priest_room.h"
#include <pub.h>
#include <drink_defs.h>
#include <living_defs.h>

#define SECRET_ROOM CRYPT_DIR "virtual/tunnel1"
#define OPEN_DELAY 15.

status door_is_open;
int last_opening;

void init_drinks() {
    /* ids, container, short, alco value, heal, cost, long desc, drink msg */
    drinks = ({
      ({"ale","heather ale"}),
      "bottle", "Bottle of Heather Ale", 5, 5, 15,
      "This is a bottle of the famous Heather Ale brewed by the \
Holy Order. It's manufacturery is a closely guarded secret.",
      "You enjoy a pint of fine Heather Ale. Praise be to Boccob!",
      ({"amaretto","amaretto cordial","cordial","liqueor","amaretto_cordial"}),
      "Flask", "Flask of Amaretto Cordial", 10,15,150,
      "This sweet liqueor is the product of hours of careful labor by \
the Lay Borthers here. It has a rich orgeot flavor.",
      "With each sip, a pleasant warmth spreads through your body.",
      ({"wine","anthalas wine"}),
      "bottle", "Bottle of Anthalas Wine", 15, 35, 200,
      "This is the rare Anthalas Wine. It is the product of countless \
hours of painstaking labor performed by the Lay Brothers. It is \
truely a gift from Boccob the Generous!",
      "Strong and fruity: the clear essence of Anthalas bites through.",
    });
}

string query_default_drink() { return "wine"; }

status check_hours() {
    return VESPER_D->query_vespers() == 0;
    // Let's convert it from string just to be sure it works
}

int pub_open() {
    object ob;

    if (!(ob = present("bartender", this_object()))) {
	notify_fail("You can't see the bartender.\n");
	return 0;
    }
    if(!(IS_PRIEST(this_player()))){
	notify_fail("We don't serve the unwashed heathens. Be gone pagan!\n");
	return 0;
    }

    return check_hours();
}


int check_open(){
    if(pub_open()) return 1;
    if(!this_player()) return 0;
    if(!check_hours()){
	this_player()->tell_me(
	  "The Order has been called to Mass. Please leave.");
    }
    return 0;
}


string my_long() {
    return sprintf(
      "This is the superb wine cellar of the Holy Order. The walls are made \
of granite stones to keep the temperature suitable for wines. Even so this \
is a cozy place to sit and relax. The heady vapors from the vintner's \
craft help to cheer you. %sThese vintages are available:\n\n%s\n\
You can 'fill <container>' with any drink.",
      door_is_open ? "On the north wall there is an open granite door. " : "",
      list_drinks(0));
}

string door_long() {
    if(door_is_open) return "It's a magnificently hidden stone door. If it \
was closed there would be no way you could notice it.";
    return 0;
}


void
create_pub(){
    set_short("The Wine Cellar of the Cathedral");
    set_long(#'my_long);

    set_items(([
	({"wall", "walls"}) : "They are made of granite stones and are quite \
cold, as we are under the ground.",
	({"stone", "stones"}) : "They are of different sizes. One of \
them seems to be slightly darker than the others.",
	"dark stone" : "The stone has become darker than the others, and it \
looks like someone has pushed it hundreds of times over the years.",
	"door" : #'door_long,
      ]));

    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);

    add_exit("up", PRIEST_ROOM_DIR+"wine_stairway");

    add_monster(PRIEST_MON_DIR+"vintner","Claudius arrives from the back room.",1);

    add_command("push", "push_cmd");
}

status query_door_open() { return door_is_open; }

void close_the_door() {
    tell_here(({
	"The door to the north closes and merges perfectly into the wall.",
	"You hear a low piched humming sound.",
      }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
      0,0,0,0,0);
    SECRET_ROOM->tell_here(({
	"The door to the south closes.",
      }), ({LIV_CAN_SEE}),0,0,0,0,0);
    door_is_open = 0;
    remove_exit("north");
    SECRET_ROOM->remove_exit("south");
    SECRET_ROOM->set_light_level(LT_DARKNESS);
}

void open_the_door() {
    tell_here(({
	"A massive stone door opens with a low pitched humming sound.",
	"A massive stone door opens from the wall.",
	"You hear a low piched humming sound.",
      }), ({LIV_CAN_SEE | LIV_CAN_HEAR, LIV_CAN_SEE, LIV_CAN_HEAR}),
      0,0,0,0,0);
    SECRET_ROOM->tell_here(({
	"The door opens with a low pitched humming sound.",
	"The door opens.",
	"You hear a low piched humming sound.",
      }), ({LIV_CAN_SEE | LIV_CAN_HEAR, LIV_CAN_SEE, LIV_CAN_HEAR}),
      0,0,0,0,0);

    door_is_open = 1;
    add_exit("north", SECRET_ROOM);
    SECRET_ROOM->add_exit("south", object_name());
    SECRET_ROOM->set_light_level(LT_DIM);
    call_out(#'close_the_door, 15);
}

status push_cmd(string what) {
    if(!this_player()) return 0;
    if(!what) return notify_fail("Push what?\n"),0;
    if(!id(what)) return 
	notify_fail("You can't see anything called that here.\n"),0;
    if(what == "stone") return notify_fail("This room is build from stones. \
Are you trying to push all of them??\n"),0;
    if(what != "dark stone") return notify_fail("You push it, but nothing \
special happens.\n"),0;
    tell_here(({
	":%<me.capname>% push%<me.ending_es>% a stone on the wall.",
      }), ({LIV_CAN_SEE}),
      0,0,this_player(),0,0);
    if(!door_is_open)
	call_out(#'open_the_door, 2);
    return 1;
}
