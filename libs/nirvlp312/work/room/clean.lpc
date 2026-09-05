/*
 *      File:              /room/clean.c
 *      Function:          Performs room cleaning.     
 *      Author(s):         Earwax@Nirvana
 *      Copyright:         Copyright (c) 2004 Earwax/David Halek
 *                                 All Rights Reserved.
 *      Source:            03/17/06
 *      Notes:             This should be called by the driver.
 *      Change History:    03/17/06:  recoded, added check for
 *                         players being in room.
 *****************************************************************
 */

/* Global Variables */
int no_clean,     /* 1 means don't clean here   */
    cast_here;    /* Room is safe to destruct() */

/* Parameters */
set_no_clean(arg){ no_clean = arg; }

/* Query no_clean */
int query_no_clean() { return no_clean; }

/** Gnar - this is to keep objs from cleaning in the room. See /obj/clean.c **/
int query_dont_clean_obs_here() { return no_clean; }

/* 
 * Function name:  clean_up: 
 * Description:    called by the driver to clean a room 
 * Returns:        0 : never call cleanup on this object again
 *                 1 : always returns 1, heh
 */

clean_up() 
{
  cast_here = 0; 
  if(query_no_clean() || present("GlobalPlayerId", this_object())) return 1;
  log_file("CLEAN",
           ctime()[4..15] + " " + ctime()[20..23] + " " +
           object_name(this_object())+" room Cleaned: "+no_clean+".\n");
  dest_inv();
  if(!cast_here) destruct(this_object());
  return 1;
}

/* 
 * Function name: dest_inv
 * Description:   Nuke the inventory of this object
 * Returns:       1
 */

dest_inv()
{
  object ob, ob2;

  ob = first_inventory(this_object());

  while(ob)
  {
    ob2 = next_inventory(ob);

    if ((int)ob->is_castle()) 
    {
      cast_here = 1;
      return 1;
    }
    if ( !((status)ob->query_interactive()) )
      destruct(ob);

    ob = ob2;
  }
  return 1;
}


