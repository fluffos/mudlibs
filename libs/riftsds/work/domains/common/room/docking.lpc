/* Do not remove the headers from this file! see /USAGE for more info. */

inherit INDOOR_ROOM;

/*
** This file can be inherited as ROOM_DOCKING. Make sure you add a "window" in your long description and a terminal.
** These two things are standard in all docking rooms.
** Also, call ::setup() in your setup() function.
*/

void setup()
{
   set_area("docking_room");
   add_item("window", (["look":"The windows provide " +
                                   "a breathtaking view of space. These windows line the walls of the room and give a "
                                   "clear view of the ships " +
                                   "as they approach and depart from the station.",
                          "read":"Someone wrote 'Killroy was here!' in the corner.", ]));
   set_objects((["^common/item/docking_terminal":1, "^common/item/airlock":1]));
}

// Handles ship descriptions in something is docked.
string get_extra_long()
{
   return present("docking_terminal_id") ? present("docking_terminal_id")->ship_state()
                                         : "The docking slot outside is under repair.";
}

int is_docking_room()
{
   return 1;
}