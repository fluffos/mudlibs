/* Room with new board to only allow priests, priest guests, and coders to read/write to it. */
#include  "priest_room.h"
#include <bboard_defs.h>
#include <generic_items.h>

int valid_board_access(object me);

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set_short("The inner study of the Priests' Quarters");
    set_long(
      "The soft woolen carpets and well oiled, overstuffed leather chairs are \
highlighted by softly glowing oil lamps, making this the ideal \
spot for weary Priests to relax and perhaps read the latest news on the \
board. There are several doors leading off this room. As everywhere \
else in the Priests' Quarters, light oak with fine grained ash trim \
is used, adding to the overall beauty of the room. There is a small \
plaque on the wall."
    );
    set_exits(([
	"up" : PRIEST_ROOM_DIR "1tower",
	"north" : PRIEST_ROOM_DIR "vg_aud",
	"south" : PRIEST_ROOM_DIR "library",
	"down" : PRIEST_ROOM_DIR "nave",
      ])),

    set_items(([
	"carpets" : "They are made of wool and are very soft, making you feel \
comfortable and warm.",
	"chairs" : "They look very inviting and comfortable. There are enough of \
them even for lots of people and they are placed so that they are not in the \
way but still not too far away to keep company to people on other chairs.",
	({"lamps", "oil lamps"}) : "These lamps are made of silver and green glass. \
They create a nice athmosphere, glowing softly green light and adding a nice \
oil smell to this room.",
	"doors" : "They are made of light oak with fine grained ash trim. They look \
massive, but are extremely well oiled and can be opened or closed with almost \
no effort or sound.",
      ]));
    /* Bulletin board */
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, ([
	    BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access,
	  ]), "priest_guild_main", 0 }),
      }), 0, 1);
    // let's load zagyg and vintner
    call_other(PRIEST_ROOM_DIR "library", "???");
    call_other(PRIEST_ROOM_DIR "wine_cellar", "???");
}


status
read_cmd(string str)
{
    if(str == "plaque") {
	this_player()->tell_me("It says: this room can be used as a start \
location. See <help starthere>.");
	return 1;
    }
    return 0;
}

status
query_is_start_location() {
    return IS_PRIEST(this_player());
}

int valid_board_access(object me)
{
    if(IS_PRIEST(me) || GUEST_D->query_guest(me) || me->query_coder_level())
	return 1;
    return 0;
}
