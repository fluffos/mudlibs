/*
  /std/combat/chumlock.c

  These are some routines to lock out adding of new attacks or hitlocations
  after they have been configured. This is normally used for player objects.

  This is the locked version of /std/combat/chumanoid.c

*/
#pragma save_binary
#pragma strict_types

inherit "/std/combat/chumanoid";

/*
* Function name: create_chumanoid
* Description:   Reset the combat functions
*/
public nomask void
create_chumanoid()
{
    this_object()->create_chumplayer();
}

/*
 * Function name: cb_add_attack
 * Description:   Add an attack to the attack array.
 * Arguments:	  
 *             wchit: Weapon class to hit
 *             wcpen: Weapon class penetration
 *	       dt:    Damage type
 *             %use:  Chance of use each turn
 *	       id:    Specific id, for humanoids W_NONE, W_RIGHT etc
 *	       skill: Skill to use
 *
 * Returns:       True if added.
 */
public nomask int
cb_add_attack(int wchit, mixed wcpen, int damtype, int prcuse,
              int id, int skill)
{
    /* Allow modification only of known attacks */
    if (member_array(id, query_attack_id()) >= 0)
	return ::cb_add_attack(wchit, wcpen, damtype, prcuse, id, skill);
    else
	return 0;
}

/*
 * Description:   Stops removal of attacks
 */
public nomask int cb_remove_attack(int id) { return 0; }

/*
 * Description:   Add a hitlocation to the hitloc array
 */
public nomask int
cb_add_hitloc(int *ac, int prchit, string desc, int id)
{
    /*
     * Allow modification only of known hit locations
     */
    if (member_array(id, query_hitloc_id()) >= 0)
	return ::add_hitloc(ac, prchit, desc, id);
    else
	return 0;
}

/*
 * Function name: cb_remove_hitloc
 * Description:   Removes a specific hit location
 * Arguments:     id: The hitloc id
 * Returns:       True if removed
 */
public nomask int
cb_remove_hitloc(int id) { return 0; }

