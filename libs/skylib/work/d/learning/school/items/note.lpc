/*
* A note that you can tear apart
* Created for the add_command section
* of the cre school.
* 27 Feb '02 by Avelan
*/

inherit OBJECT_OBJ;
int do_tear();

void setup(){
    set_name("note");
    set_short("small note");
    add_adjective(({"small"}));
    set_long("This is a small note that says:\n"
      "'tear note' to tear this apart.\n");

} /* setup() */

void init(){
    add_command("tear");
} /* init() */

int do_tear(){
    add_succeeded_mess("$N $V $D\n");
    TO->move("/room/rubbish");
    return 1;
} /* do_tear() */
