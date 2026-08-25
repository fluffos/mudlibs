/* 
 * /std/workroom.c
 *
 * Generic workroom, just change it to your fit your tastes 
 */

#pragma save_binary
#pragma strict_types

inherit "/std/room";

#include <stdproperties.h>
#include <macros.h>
#include <std.h>

#define NAME_WIZ capitalize(creator(this_object()))

/*
 * Prototypes
 */
object load_board();

/*
 * Function name: create_workroom
 * Description  : Called to create the workroom. You may redefine this
 *                function to create your own.
 */
void
create_workroom()
{
    set_short(NAME_WIZ + "'s workroom");
    set_long("This is " + NAME_WIZ + "'s workroom.\n");
    add_exit("@@goto_start@@", "startloc", 0);
    add_exit("/d/Genesis/wiz/lounge", "lounge");

    string domain = SECURITY->query_wiz_dom(creator(this_object()));
    if (domain && strlen(domain) > 0 && domain != "Wiz")
        add_exit("/d/" + domain + "/workroom", lower_case(domain));

    if (SECURITY->query_domain_number(creator(this_object()))>=0)
	load_board();

    add_prop(ROOM_I_INSIDE, 1);
}    

/*
 * Function name: create_room
 * Description:   Create the room
 */
nomask void
create_room()
{
    create_workroom();
}

/*
 * Function name: reset_workroom
 * Description  : Called to make the room reset from time to time. You
 *                should redefine this function if you want your workroom
 *                to reset.
 */
public void
reset_workroom()
{
}

/*
 * Function name: reset_room
 * Description  : Called to make the room reset from time to time.
 */
nomask void
reset_room()
{
    reset_workroom();
}

/*
 * Function name: load_board
 * Description  : Load a bulletin board into the room.
 * Returns      : object - the bulletin board.
 */
object
load_board()
{
    object bb;
    string *file;
    string name;

    file = explode(MASTER + "/", "/");
    file = slice_array(file, 0, sizeof(file) - 2);

    seteuid(getuid());
    bb = clone_object("/std/board");

    name = implode(file, "/") + "/log";
    if (file_size(name) != -2) 
	mkdir(name);

    bb->set_board_name(name + "/board_data");
    bb->set_num_notes(30);
    bb->set_silent(0);
    bb->set_show_lvl(0);
    bb->set_no_report(1);
    bb->move(this_object());

    return bb;
}

/*
 * Function name: goto_start
 * Description  : Find and return the default start location of the player
 *                who uses the 'startloc' exit.
 * Returns      : string - the filename of that room.
 */
string
goto_start()
{
    return this_player()->query_default_start_location();
}
