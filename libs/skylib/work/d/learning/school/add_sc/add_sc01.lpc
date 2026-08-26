/*
* add_command examples for the cre school
* Feb 2 '02 by Avelan
*/

#include "defs.h"
inherit ROOM_OBJ;

/*
* The next line is called a prototype.
* It is needed in order for the
* add command to work properly.
*/
int do_smash();

/*
* Here we declare that the variable smashed
* is an integrer(number), and we then
* initialize it(set the value to 0 in this case)
*/
int smashed = 0;

void setup(){
    set_light(80);
    set_short("add_command school");
    set_long("So, let's make our first, very"
      " simple add_command.  Say we want to be"
      " able to smash the table that's standing"
      " in the room.  In this case, the table"
      " will be just an add_item and when we"
      " smash it, we'll just change the description"
      " of the item.\nThere's a table in the middle"
      " of the room.\n");

    /*
    * So, you wonder.. this isn't an add_command really,
    * what is it then?
    * well, here we're using a function pointer, so when you
    * do smash table, the do_smash function is called and
    * executed.
    */
    add_item("table",({"long","The table is nice and shiny.",
        "smash",({ (: do_smash :) , "<direct:object>" }) }) );

    add_exit("back",ADD_SC+"start","path");

} /* setup() */

void reset(){

    /*
    * Let's make the table nice and shiny again at every
    * reset so other's can smash it too.
    * Also, remember to set the smashed variable back to
    * 0 so the command will work. :)
    */
    modify_item("table",({"long","The table is nice and shiny.",
        "smash",({ (: do_smash :) , "<direct:object>" }) }) );
    smashed = 0;
} /* reset() */

int do_smash(){

    /*
    * So, if the smashed variable has been set to 1,
    * it means that the table has been smashed already
    * and can't be smashed again.
    * This line checks if the variable is anything other
    * 0, the command will fail.
    */
    if(smashed){
        add_failed_mess("The table has already been smashed.\n");
        return 0;
    }

    /*
    * Ok, everything seems to be fine, let's modify
    * the tables description to show that it's smashed.
    */
    modify_item("table",({"long","The table has been smashed into"
        " little pieces.",
        "smash",({ (: do_smash :) , "<direct:object>" }) }) );

    /*
    * Ok, another nice feature to add_command.
    * This line adds a message to use when we succeed in the
    * command.
    * The $N and $V expand to the person doing the command and
    * to the verb used.
    * ie. This would expand to 'You smash the table into little pieces.'
    * to you and others would see 'Avelan smashes the table into little
    * pieces'
    * help add_succeeded_mess for more information.
    */
    add_succeeded_mess("$N $V the table into little pieces.\n");

    /*
    * Let's set the smashed property to 1 so we can't
    * smash the table again before next reset() of the room.
    */
    smashed = 1;

    /*
    * Again, you need to return 1 which tells that the command
    * succeeded.
    */
    return 1;
} /* do_smash() */
