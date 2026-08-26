/*
// File:	visible.c
// Mudlib:	TMI-II
// Author:	Pallando
// Real Name:	Douglas Reay
// Syntax:      varargs int visible( object detectee, object detector )
// Returns:     1 if detector may be allowed to know that the detectee exists
//		0 if detector may not penetrate detectee's invisibility.
// Purpose:	Should be called by any command that might let one user know
//              whether another user is logged on.
// Date V1.0:   1992 December 22
//      V1.1:   Ideas about generality from Mobydick.
// Date V2.0:   1994 August 28 - Pallando allows objects to see themselves
//      V3.0:   1998 October 18 - Cyanide overhauled to account for 
//              'see_invis'.
*/

#include <uid.h>

varargs int visible( object detectee_obj, object detector_obj )
{
    string detector_euid;
    int see_invis, nondetection, lvl;
    int detector_rank, detectee_vis;
    int flag = 1;

    if( !detectee_obj ) return 0;
    if( !detector_obj )
    {
	detector_euid = "TEMP";
    } else {
	// An object can always find itself.
	if( detector_obj == detectee_obj ) return 1;
	detector_euid = geteuid( detector_obj );
    }

    detectee_vis = detectee_obj->query("invisible");

    // Find the detector's rank
    if (detector_obj ) detector_rank = wizardp( detector_obj );
    if (adminp( detector_euid ) ) detector_rank = 2;
    if (member_group(detector_euid, "root")) detector_rank = 3;
    if (detector_euid == "cyanide") detector_rank = 4;

    if (detector_rank)
    {
	flag = (detector_rank >= detectee_vis);
    } else {
	if (detector_obj)
	    see_invis = detector_obj->query("see_invisible");
	else
	    see_invis = 0;

	nondetection = detectee_obj->query_skill("Nondetection");
	if (!nondetection)
	    nondetection = detectee_obj->query("nondetection");
	if (detectee_vis) {
	    if (see_invis && !nondetection) {
		flag = 1;
	    } else {
		flag = 0;
	    }
	} else {
	    flag = 1;
	}
    } // if (detector_rank)
    return flag;
}

/* EOF */
