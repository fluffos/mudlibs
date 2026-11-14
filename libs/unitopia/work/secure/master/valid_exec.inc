// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_exec.inc
// Description:
//
// $Log: valid_exec.inc,v $
// Revision 1.5  2007/08/11 23:32:03  gnomi
// Telnet-States in beide Richtungen tauschen.
//
// Revision 1.4  2007/08/11 16:32:47  gnomi
// Bei exec() die Telnet-States uebertragen, sofern vorhanden.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

/*
 * Function name:   valid_exec
 * Description:     Checks if a certain 'program' has the right to use exec()
 * Arguments:       name: Name of the 'program' that attempts to use exec()
 *                        Note that this is different from object_name(),
 *                        Programname is what 'function_exists' returns.
 *                  NOTE, the absence of a leading slash in the name.
 * Returns:         True if exec() is allowed.
 */
int valid_exec(string name, object ob, object obfrom) {
    if(name==(LOGIN_OB".c")[1..] || name=="secure/chsh.c")
    {
	mapping tsfrom = ({mapping}) obfrom->transfer_ts();
	mapping tsto = ({mapping}) ob->transfer_ts();
	if(tsfrom)
	    ob->transfer_ts(tsfrom);
	if(tsto)
	    obfrom->transfer_ts(tsto);
	return 1;
    }
}
