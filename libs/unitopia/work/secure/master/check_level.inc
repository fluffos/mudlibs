// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/check_level.inc
// Description: Levelcheck und Playercheck
//
// $Log: check_level.inc,v $
// Revision 1.6  2002/01/12 21:23:36  gnomi
// gci existiert nicht mehr.
//
// Revision 1.5  2001/02/11 04:18:58  sissi & gnomi
// Neues Levelsystem
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types


static string * valid_shells;

private void get_valid_shells()
{
   valid_shells = ({ "/obj/player", "/obj/newplayer" });
}

int playerp(object ob)
{
    int junk;
    if(!objectp(ob))
	return 0;
    return sscanf(object_name(ob),"/obj/player#%d",junk)==1 ||
	   sscanf(object_name(ob),"/obj/newplayer#%d",junk)==1 ||
	   sscanf(object_name(ob),"/obj/wizard_shell#%d",junk)==1;
}

int wizardshellp(object ob)
{
    int junk;

    return sscanf(object_name(ob),"/obj/wizard_shell#%d",junk)==1;
}

string * query_valid_shells()
{
   return ({})+valid_shells;
}


/*
 * Function name:   query_real_player_level
 * Parameter:	    Objekt oder Name eines Objektes.
 * Description:     Returns 0 if object isn't an interactive player
 *		    else returns the Level.
 */

int query_real_player_level(object player) {
    if (objectp(player) && playerp(player))
	return ({int})player->query_level();
}
