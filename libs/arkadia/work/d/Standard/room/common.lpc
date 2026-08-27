/*
 * This room contains the common board for all players, mortals as well as
 * immortals. A player who enters this room can only go back to the room
 * he just left, so there are no normal exits from this room.
 *
 * Nick, 921223
 */

#pragma save_binary

inherit "/std/room";
#include <stdproperties.h>

/*
 * Prototypes
 */
void    load_board();

void
create_room()
{
    set_short("In the common board room");
    set_long(break_string(
        "You are standing in the room where the common board is. It's common " +
        "for all races in Genesis, immortals as well as mortals. " +
        "You feel great magic at work here. You see no obvious exits but " +
        "somehow you feel you can always go back to where you came from." +
        "\n", 70));

    set_noshow_obvious(1);

    add_prop(ROOM_I_NO_STEAL, 1);
    add_prop(ROOM_I_NO_TELEPORT, 1);
    add_prop(ROOM_I_NO_ATTACK, 1);

    load_board();
}

void
load_board()
{
    object bb;

    seteuid(getuid(this_object()));
    bb = clone_object("/d/Standard/obj/board");
    bb->move(this_object());
}

void
init()
{
    add_action("back", "back");
    add_action("back", "return");
    add_action("back", "go");

    ::init();
}

int
back(string str)
{
    if (query_verb() == "go" && str != "back")
        return 0;

    if (!this_player()->query_prop(LIVE_O_LAST_ROOM))
	this_player()->move_living("back",
		this_player()->query_default_start_location());
    else
	this_player()->move_living("back",
                this_player()->query_prop(LIVE_O_LAST_ROOM));

    return 1;
}

/*
 * Function: enter_inv
 * Description: block non-interactives from entering.
 */
enter_inv(object ob, object from)
{
    ::enter_inv(ob, from);

    if (living(ob) && !interactive(ob))
        ob->move(from);
}