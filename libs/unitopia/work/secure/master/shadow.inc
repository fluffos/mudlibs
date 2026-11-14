// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/shadow.inc
// Description:
// Modified by: Freaky (29.11.95) Shadowen nur noch moeglich von Objekten
//		aus ALLOWED_SHADOW_DIRS
//
// $Log: shadow.inc,v $
// Revision 1.5  2007/10/24 21:57:58  gnomi
// Man sich nicht in einen Shadow bewegen bzw. ein Objekt mit Inhalt darf nicht
// Shadow werden.
//
// Revision 1.4  2001/11/18 16:56:20  freaky
// an ldmud-3.2.9dev363 angepasst.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

#define ALLOWED_SHADOW_DIRS ({"obj","d","map","p","room","w","z"})
#define NO_SHADOW_DIRS ({"/i/","/apps/"})

/*
 * The master object is asked if it is ok to shadow object ob. Use
 * previous_object() to find out who is asking.
 *
 * In this example, we allow shadowing as long as the victim object
 * hasn't denied it with a query_prevent_shadow() returning 1.
 */

private int no_shadow_path(string *path)
{
    foreach (string s: NO_SHADOW_DIRS)
    {
	if (member(path,s) != -1)
	{
	    return 1;
	}
    }
}

int query_allow_shadow(object ob)
{
    string *path;
    
    // Das Shadow darf keinen Inhalt haben.
    if(first_inventory(previous_object()))
	return 0;

    path = explode(object_name(ob),"/");
    if (member(ALLOWED_SHADOW_DIRS,path[1]) != -1)
	if (!no_shadow_path(path))
	    return !ob->query_prevent_shadow(previous_object());

    write_file("/log/sys/SHADOW",sprintf("OB: %O.\nPO: %O.\nTP: %O.\n\n",
	ob,previous_object(),this_player()));
}
