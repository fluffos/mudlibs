#include <room.h>
#include <mud_name.h>
#include <bboard_defs.h>
#include <generic_rooms.h>
#include <generic_items.h>

int valid_board_access(object me);

void create_room()
{
    set_short("Grand Hall of Immortals");
    set_long("You are in the Grand Hall of Immortals, somewhere between "
      "reality and virtuality.  Floating in the center of the room "
      "is a board for writing ideas and comments that are vital to "
      "the survival of "+MUD_NAME+".  Inscribed above the board in "
      "glowing runes are the words \"Imagine what you will, and you "
      "can have it.\""  
    );
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);

    set_exits( ([
	"yard" : GENERIC_ROOM_CHURCH,
	"south": GENERIC_ROOM_ADV_GUILD
      ]) );

    add_object( ({ GENERIC_BBOARD,
	({ "set_board", 300, ([ BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access, ]), "immortal_main", 0 }),
      }), 0, 1);
}

status query_is_start_location() {
    return (this_player()->query_coder_level());
}

int valid_board_access(object me)
{
    /* Nope
    me->tell_me("Yup");
    */
    return (this_player()->query_coder_level());
}
