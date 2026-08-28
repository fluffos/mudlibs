
/* -------------------------------------------------------------------------
 * G-LIB v0.0-alpha0                        GENERIC OBJECT LIBRARY FOR LPMUD
 * (see /doc/license before altering the code)
 * -------------------------------------------------------------------------
 * file name   : world/start.c
 * description : the default starting room for mortals
 * coder(s)    : namhas
 * -------------------------------------------------------------------------
 */

inherit ROOM;

create_room ()
{
    set_light (1);
    set_short ("Meeting hall of the Gods");
    set_long ("The meeting hall is plain and very simple. A circular table sits "+
      "in the middle of the room, lit by some unseen light source. There are "+
      "many chairs aruound the table, all empty.\n");

    add_exit("down","/world/city/start");
    add_exit("namhas","/home/namhas/workroom");
    add_exit("deicider","/home/deicider/workroom");
    add_exit("dranil","/home/dranil/workroom");
}

