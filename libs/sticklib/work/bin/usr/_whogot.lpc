/*
**	Command:	whogot
**	Arguments:	<item id>
**	Used for:	Searching players for <item>
**	Coded by:	Silly
**	Coded on:	17th April 1999
**
**	Updates:	None as yet!
**
*/

#define TP	this_player()

nomask int whogot_cmd(string strArgs) {
    int intCount, intFound;
    object *objUsers, objFound;
    string strBuildString;
    
    if(!strArgs) {
	notify_fail("USAGE: whogot <item id>\n");
	return 0;
    }
    
    objUsers = users();
    if(!sizeof(objUsers)) {
	notify_fail("ERROR: No players?\n");
	return 0;
    }
    
    TP->tell_me("Players holding item "+strArgs+" are:\n");
    intFound = 0;
    for(intCount = 0; intCount < sizeof(objUsers); intCount++) {
	strBuildString = "";
	objFound = present(strArgs, objUsers[intCount]);
	if(objFound) {
	    strBuildString = sprintf("%-20s", capitalize(objUsers[intCount]->query_real_name()));
	    strBuildString += objFound->query_name();
	    strBuildString += "\n                    "+object_name(objFound);
	    TP->tell_me(strBuildString);
	    intFound += 1;
	}
    }
    
    if(!intFound)
	TP->tell_me("No players are holding item "+strArgs+"!");
    return 1;
}
