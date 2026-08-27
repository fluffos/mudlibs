/*
  /std/combat/humunarmed.c

  Humanoid unarmed initialization routines.

  These routines can inherited by all living objects that need
  humanoid unarmed combat values of a standardized type.

  For player objects which normally use a locked combat system, ie where
  the hitlocations and attacks can not be added or removed, this file
  is normally inherited for unarmed initialization purposes.

  Revision history:

 */
#pragma save_binary
#pragma strict_types

inherit "/std/combat/unarmed";

#include "/sys/wa_types.h"
#include "/sys/ss_types.h"
#include "/sys/macros.h"
#include "/sys/formulas.h"

#define QEXC (this_object()->query_combat_object())

/*
 * Function name: cr_configure
 * Description:   Configures basic values for this humanoid.
 */
public nomask void
cr_configure() 
{
    ::cr_configure();

    if (query_attackuse())
	QEXC->cb_set_attackuse(query_attackuse());
    else
	QEXC->cb_set_attackuse(100);
}

/*
 * Function name: cr_reset_attack
 * Description:   Set the values for a specific attack. These are called from
 *		  the external combat object.
 * Arguments:     aid: The attack id
 */
public nomask void
cr_reset_attack(int aid)
{
    int wchit, wcpen, uskill;

    ::cr_reset_attack(aid);

    if (!sizeof(query_ua_attack(aid)))
    {
	wchit = W_HAND_HIT;
	wcpen = W_HAND_PEN;
	if (uskill = this_object()->query_skill(SS_UNARM_COMBAT))
	{
	    wchit += F_UNARMED_HIT(uskill, this_object()->query_stat(SS_DEX));
	    wcpen += F_UNARMED_PEN(uskill, this_object()->query_stat(SS_STR));
	}
	
	if (uskill < 1)
	   uskill = -1;

	switch(aid)
	{
	case W_RIGHT:
	    QEXC->cb_add_attack(wchit, wcpen, W_BLUDGEON, 25, aid, uskill + 6);
	    break;
	case W_LEFT:
	    QEXC->cb_add_attack(wchit, wcpen, W_BLUDGEON, 25, aid, uskill + 6);
	    break;
	case W_BOTH:
	    /*
             * We use the hands separately in unarmed combat
             */
	    QEXC->cb_add_attack(0, 0, W_BLUDGEON, 0, aid, uskill + 6);
	    break;
	case W_FOOTR:
	    QEXC->cb_add_attack(wchit, wcpen, W_BLUDGEON, 25, aid, uskill);
	    break;
	case W_FOOTL:
	    QEXC->cb_add_attack(wchit, wcpen, W_BLUDGEON, 25, aid, uskill);
	    break;
	}
    }
}

/*
 * Function name: cr_reset_hitloc
 * Description:   Set the values for a specific hitlocation
 * Arguments:     hid: The hitlocation (bodypart) id
 */
public nomask void
cr_reset_hitloc(int hid)
{
    ::cr_reset_hitloc(hid);

    if (!sizeof(query_ua_hitloc(hid))) 
    {
	switch(hid)
	{
	case A_HEAD:
	    QEXC->cb_add_hitloc(A_UARM_AC, 15, "glowe", hid);
	    break;
	case A_L_ARM:
	    QEXC->cb_add_hitloc(A_UARM_AC, 10, "lewe ramie", hid);
	    break;
	case A_R_ARM:
	    QEXC->cb_add_hitloc(A_UARM_AC, 10, "prawe ramie", hid);
	    break;
	case A_TORSO:
	    QEXC->cb_add_hitloc(A_UARM_AC, 45, "korpus", hid);
	    break;
	case A_LEGS:
	    QEXC->cb_add_hitloc(A_UARM_AC, 20, "nogi", hid);
	    break;
	}
    }
}

/*
 * Function name: cr_try_hit
 * Description:   Decide if a certain attack fails because of something
 *                related to the attack itself.
 * Arguments:     aid:   The attack id
 * Returns:       True if hit, otherwise 0.
 */
public nomask int
cr_try_hit(int aid) { return 1; }

/*
 * Function name: cr_attack_desc
 * Description:   Gives the description of a certain unarmed attack slot.
 * Arguments:     aid:   The attack id
 * Returns:       string holding description
 */
public nomask string
cr_attack_desc(int aid)
{
    switch(aid)
    {
    case W_RIGHT:return (random(100)<80 ? "prawa piescia" : "prawym lokciem");
    case W_LEFT:return (random(100)<80 ? "lewa piescia" : "lewym lokciem");
    case W_BOTH:return "joined hands";
    case W_FOOTR:return (random(100)<80 ? "prawa stopa" : "prawym kolanem");
    case W_FOOTL:return (random(100)<80 ? "lewa stopa" : "lewym kolanem");
    }  
    return "mind"; /* should never occur */
}

/*
 * Function name: cr_got_hit
 * Description:   Tells us that we got hit. It can be used to reduce the ac
 *                for a given hitlocation for each hit.
 * Arguments:     hid:   The hitloc id
 *                ph:    The %hurt
 *                att:   Attacker
 *		  aid:   The attack id
 *                dt:    The damagetype
 *		  dam:   The damage in hit points
 */
public void
cr_got_hit(int hid, int ph, object att, int aid, int dt, int dam)
{
    /* We do not tell if we get hit in any special way
    */
}

/*
 * Function name: set_all_attack_unarmed
 * Description:   Set up all unarmed attack basics
 * Arguments:     hit - the hit value
 * 		  pen - the pen value
 */
public nomask void
set_all_attack_unarmed(int hit, int pen)
{
    set_attack_unarmed(W_RIGHT, hit, pen, W_BLUDGEON, 25, "");
    set_attack_unarmed(W_LEFT, hit, pen, W_BLUDGEON, 25, "");
    set_attack_unarmed(W_FOOTR, hit, pen, W_BLUDGEON, 25, "");
    set_attack_unarmed(W_FOOTL, hit, pen, W_BLUDGEON, 25, "");
}

/*
 * Function name: set_all_hitloc_unarmed
 * Description:   Set up all unarmed hit location basics
 * Arguments:     ac - an int or an array to modify the ac....
 */
public nomask void
set_all_hitloc_unarmed(mixed ac)
{
    set_hitloc_unarmed(A_BODY, ac, 45, "korpus");
    set_hitloc_unarmed(A_HEAD, ac, 15, "glowe");
    set_hitloc_unarmed(A_LEGS, ac, 20, "nogi");
    set_hitloc_unarmed(A_R_ARM, ac, 10, "lewe ramie");
    set_hitloc_unarmed(A_L_ARM, ac, 10, "prawe ramie");
}

/*
 * Function name: update_procuse()
 * Description:   use this to update the percent usage of attacks
 */
public nomask void
update_procuse()
{
    QEXC->cb_modify_procuse();
}
