// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_seteuid.inc
// Description:
//
// $Log: valid_seteuid.inc,v $
// Revision 1.9  2002/06/24 22:50:50  gnomi
// Objekte mit UIDs, die mit "Root:" beginnen, duerfen sich beliebig EUIDs
// setzen.
//
// Revision 1.8  2001/06/03 11:18:21  freaky
// Neues UID-Handling eingebaut.
//
// Revision 1.7  2001/05/21 21:56:10  freaky
// altes UID handling mit <pre>:<post> rausgeschmissen.
//
// Revision 1.6  2001/04/19 23:06:28  freaky
// bugfix im logging
//
// Revision 1.5  2001/04/19 22:38:38  freaky
// logging eingebaut.
//
// Revision 1.4  2001/04/15 01:03:07  freaky
// kleiner Tweak.
//
// Revision 1.3  2001/04/15 00:24:13  freaky
// nobody-uid eingebaut.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
 
/*
 * Function name:   valid_seteuid
 * Description:     Checks if a certain user has the right to set a certain
 *                  objects effective 'userid'. All objects has two 'uid'
 *                  - Owner userid: Wizard who caused the creation.
 *                  - Effective userid: Wizard responsible for the objects
 *                    actions.
 *                  When an object creates a new object, the new objects
 *                  'Owner userid' is set to creating objects 'Effective
 *                  userid'.
 *                  
 * Arguments:       ob:   Objekt to set 'effective' user id in.
 *                  user: Wizard responsible for the setting.
 * Returns:         True if set is allowed.
 */
int valid_seteuid(object ob, string str)
{
    /*
     * An object can always be itself.
     */
    if (getuid(ob) == str)
        return 1;

    /*
     * Root can be anyone it pleases.
     */
    if (getuid(ob) == ROOT_UID || !strstr(getuid(ob),ROOT_UID+":"))
	return 1;

    /*
     * Jedes Objekt darf die EUID auf ("n:" + getuid()) setzen
     * aber nicht, wenn es schon "n:..." als UID hat.
     * Dies ist eine quasi Nobody-UID, da sie nichts besonderes darf.
     */
    if ((str == ("n:" + getuid(ob))) && strstr(getuid(ob),"n:"))
	return 1;

    return 0;
}
