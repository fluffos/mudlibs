/*
 * A butterfly for the creator school.
 * October '01 by Avelan
 */

#include "defs.h"

inherit NPC_OBJ;

void setup(){
    set_name("butterfly");
    set_short("butterfly");
    set_determinate("a ");

    set_long("This is a beautiful butterfly fluttering about "
        "with spotted, colourful wings and sad little eyes.  The wings "
        "make an image that looks like the face of some larger "
        "creature.\n");

    /*
     * Here we define which chats the NPC will use.
     * Please see 'help load_chat' for more info on this.
     */
    load_chat( 40, ({
        1, ":flutters about.",
        1, ":flutters closer to you.",
        1, ":lands to rest on a nearby flower.",
        1, ":makes no noise at all."
        }));
    load_a_chat( 60, ({
        1, ":makes an effort to fly as far as possibly from you.",
        1, ":looks dazed.",
        1, ":flutters its wings threateningly."
        }));

    /*
     * Here we make the NPC move around in the NPC school.
     *
     * The set_move_after() function determines the time after
     * which the NPC will move next.  The first argument to
     * set_move_after() is the minimum time after which the
     * NPC will move, and the second argument is the extra
     * random amount of time, that is added to the minimum,
     * when deciding when to move next.  In this case it will
     * take at least 120 seconds for the NPC to move and
     * 360 seconds at the most. ( 120 + random( 240 ) ).
     *
     * add_move_zone() determines the rooms the NPC can wander
     * into, the rooms need to have set_zone() set in order for
     * this to work.
     */
    set_move_after( 120, 240 );
    add_move_zone("npc_school");

    /*
     * basic_setup sets up the main properties of an NPC -
     * its race, level and gender.
     * We will use the 'insect' race, because there is
     * no butterfly race at the moment.
     */
    basic_setup("insect", 1 + random( 5 ), "male");

} /* setup() */
