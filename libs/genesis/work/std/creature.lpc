/*
  /std/creature.c

  This is the base for all nonhumanoid livings.

*/
#pragma save_binary
#pragma strict_types

inherit "/std/mobile";

#define QEXC query_combat_object()

void
create_creature() { ::create_mobile(); }

nomask void
create_mobile()
{
    create_creature(); 
}

void
reset_creature() {  ::reset_mobile(); }

nomask void
reset_mobile() { reset_creature(); }

/*
 * Description:  Use the plain (no tools) combat file
 */
public string
query_combat_file() { return "/std/combat/cplain"; }

/*
 * Function name:  default_config_npc
 * Description:    Sets some necessary values for this creature to function
 *                 This is basically stats and skill defaults.
 */
varargs public void
default_config_creature(int lvl)
{
    default_config_mobile(lvl);
}

/*
 * Function name: add_attack
 * Description:   Add an attack to the attack array.
 * Arguments:	  
 *             wchit: Weapon class to hit
 *             wcpen: Weapon class penetration
 *	       dt:    Damage type
 *             %use:  Chance of use each turn
 *	       id:    Specific id, for humanoids W_NONE, W_RIGHT etc
 *
 * Returns:       True if added.
 */
public int
add_attack(int wchit, int wcpen, int damtype, int prcuse, int id)
{
    if (!QEXC)
	return 0;
    return (int)QEXC->cb_add_attack(wchit, wcpen, damtype, prcuse, id);
}

/*
 * Function name: remove_attack
 * Description:   Removes a specific attack
 * Arguments:     id: The attack id
 * Returns:       True if removed
 */
public int
remove_attack(int id)
{
    if (!QEXC)
	return 0;
    return (int)QEXC->cb_remove_attack(id); 
}

/*
 * Function name: add_hitloc
 * Description:   Add a hitlocation to the hitloc array
 * Arguments:	  
 *	      ac:    The ac's for a given hitlocation
 *	      %hit:  The chance that a hit will hit this location
 *	      desc:  String describing this hitlocation, ie "head", "tail"
 *	      id:    Specific id, for humanoids A_TORSO, A_HEAD etc
 *
 * Returns:       True if added.
 */
public int
add_hitloc(int *ac, int prchit, string desc, int id)
{
    if (!QEXC)
	return 0;
    return (int)QEXC->cb_add_hitloc(ac, prchit, desc, id);
}

/*
 * Function name: remove_hitloc
 * Description:   Removes a specific hit location
 * Arguments:     id: The hitloc id
 * Returns:       True if removed
 */
public int
remove_hitloc(int id)
{
    if (!QEXC)
	return 0;
    return (int)QEXC->cb_remove_hitloc(id); 
}

/*
 * Function name: query_humanoid
 * Description  : Since this is not a humanoid, we mask this function so
 *                that it returns 0.
 * Returns      : int - 0.
 */
public int
query_humanoid()
{
    return 0;
}

