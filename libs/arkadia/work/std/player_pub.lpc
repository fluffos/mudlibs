/*
 * /std/player_pub.c
 *
 * This is the customizable part of the old player.c. Inherit this object
 * to make your race object. That race dependant object should then be 
 * inherited by the guild dependant object. 
 *
 * This file inherits the player_sec object statically to ensure the 
 * protection of all lower level routines.
 */

#pragma save_binary
#pragma strict_types

inherit "/std/player_sec";

#include <macros.h>
#include <config.h>

public int
check_player_pub() { return 1; }  /* Security, checked by /secure/login */

public void
start_player()
{
    /* Get the soul commands */
    this_object()->load_command_souls();
    this_object()->do_glance();
    say(QCIMIE(this_object(), PL_MIA) + " wchodzi do swiata Arkadii.\n");
}

/*
 * Function name: death_modify_stat
 * Description:   Modification function for free stats on death
 * Returns:       The modified stat.
 */
int
death_modify_stat(int stat) { return query_stat(stat); }

/*
 * Function name: death_sequence
 * Description:   Defines what happens to the player after death
 */
void
death_sequence()
{
    object death_mark;
    if (!query_ghost()) return;
    
    death_mark = clone_object(DEFAULT_DEATH);
    death_mark->move(this_object(), 1);
}

/*
 * Function:    query_new_title
 * Description: Returns the title of the player calculated from stats
 *
 */
public string
query_new_title()
{
    return "kompletny nowicjusz";
}

/*
 * Function:    query_new_al_title
 * Description: Returns the al_title of the player calculated from stats
 *
 */
public string
query_new_al_title()
{
    return "neutral";
}

public int *
query_orig_stat()
{
    /*        STR, DEX, CON, INT, WIS, DIS */
    return ({ 10,  10,  10,  10,  10,  10 });
}

public int *
query_orig_learn()
{
    /*        STR, DEX, CON, INT, WIS, DIS */
    return ({  17,  16,  16,  17,  17,  17 });
}
