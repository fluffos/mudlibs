/*
 * /doc/workroom.c
 * Written 920624 by Quis
 * 
 * This function serves two main purposes.  First, it is example coding
 * of a workroom.  Second, it gives the apprentice wizard an easy way to
 * get back to the wizard island.
 */

inherit "/std/workroom";

/*
 * The following macros are intended to prevent lines from wrapping
 * around the screen, and avoid the wizard from having to put in explicit 
 * \n's.
 */

#define BSN(s) break_string((s) + "\n",70)
#define BSNN(s) break_string((s) + "\n\n",70)


/*
 * This function is called when the workroom is loaded.  It sets up the
 * description of the room, and its exits.
 */
create_workroom()
{
    /* Here is an example of VBFC in the long description.  The long
     * description will be the string returned by the function "long_desc"
     */
    set_long("@@long_desc");
    set_short("Apprentice's workroom");

    /* Here are to examples of "pseudo-items" -- these can be looked at
     * with the "look at" or "exa" commands.
     */
    add_item(({"desk","desks"}),
        BSN("These desks are quite old and worn, not much more than tables."));

    add_item(({"field", "shimmering field"}),
        BSN("You can make out the faint image of the main foyer of the " +
            "domain tower through this."));

    /* Finally we add an exit */
    add_exit("/d/Genesis/wiz/domain", "enter", 0, 0);
}

/* 
 * This function simply returns a string.  Complex descriptions based on
 * the state of the room are possible.
 */

string
long_desc()
{
    return BSNN("This workroom is quite spartan. " +
         "There are many desks scattered throughout. " + 
         "There is a shimmering field in the center of the room. ");
}
