/*
 * Chatting monster
 *
 * Made by Nick
 */

inherit "/std/monster";

/*
 * The following include is needed to let the chatter chat like normal elves
 * If normal 'says' are agreeable to you, you can skip it.
 */
#include "/d/Genesis/login/login.h"
#include <macros.h>

void
create_monster()
{
    set_name("chatter");
    set_adj("chatting");
    set_long("An example of a chatting monster.\n");
    set_race_name("elf");

    /* This chatter will say something every now and then... :) */

    set_chat_time(5); /* Interval between chat */

    /* And the list we will run through, it will be randomized but our chatter
     * won't say something he has already said from the list again until the
     * whole list is gone through, and randommized again. 
     */
    add_chat("Hi, how are you?");
    add_chat("I'm talking to you ;-)");
    add_chat("Don't you think this is fun?");
}

/*
 * The rest of the code is added to let the mobile 'say' the same way normal
 * elves talk, i.e. 'sings' to some races while 'says' to others.
 */
public int
communicate(string str) /* Must have it here for special with ' */
{
    string verb;

    verb = query_verb();
    if (str == 0)
        str = "";
    if (strlen(verb) && verb[0] == "'"[0])
        str = extract(verb, 1) + " " + str;

    say(QCTNAME(this_object()) + " @@race_sound:" + file_name(this_object()) +
	"@@: " + str + "\n");
    write("Ok.\n");
    return 1;
}

string
race_sound()
{
    object pobj;
    string raceto, racefrom;

    pobj = previous_object();

    raceto = pobj->query_race();
    if (member_array(raceto, RACES) < 0)
        return "says";

/* NOTA BENE: the mobile must be of a standard race for this to work, otherwise
 * You must yourself invent what differrent races should see.
 */
    return RACESOUND[this_object()->query_race_name()][raceto];
}




