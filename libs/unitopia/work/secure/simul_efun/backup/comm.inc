// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /secure/simul_efun/comm.inc
// Description: Hier werden alle Kommunikations-Efuns ueberlagert
// Author:      
// Modified by:
//
// $Log: comm.inc,v $
// Revision 1.8  2010-01-23 15:03:59  gnomi
// tail ist jetzt in deprecated.inc
//
// Revision 1.7  2009-06-06 23:47:39  gnomi
// cat()-sefun zur vollstaendigen Simulation von cat() eingebaut.
//
// Revision 1.6  2007/08/15 08:19:06  gnomi
// Sefun cat und tail, um die VT100-Eingabezeile vorher umzuschalten.
//
// Revision 1.5  2001/08/28 23:03:42  freaky
// hart auf das message-system umgestellt.
//
// Revision 1.4  2001/05/14 11:55:34  gnomi
// 1. Parameter von tell_room kann auch ein String sein.
//
// Revision 1.3  2001/04/07 00:34:44  gnomi
// Header eingebaut.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma save_types
#pragma strict_types

#include <message.h>

nomask void tell_object(object ob, string str)
{
    ob->receive_message(MT_UNKNOWN,MA_UNKNOWN,previous_object(),str);
}

nomask varargs void tell_room(mixed ob, string str, object *exclude)
{
    object room;
    if(objectp(ob))
	room=ob;
    else if(stringp(ob))
	room=touch(ob);
    else
	raise_error("Bad argument 1 type to simul-efun tell_room()\n");
    filter_objects(exclude ? all_inventory(room) - exclude : all_inventory(room),
    	"receive_message",MT_UNKNOWN,MA_UNKNOWN,previous_object(),str);
    room->receive_message(MT_UNKNOWN,MA_UNKNOWN,previous_object(),str);
}

nomask varargs void say(string str, mixed exclude)
{
    object ob;

    if (living(previous_object()) || !this_player())
    	ob = previous_object();
    else
    	ob = this_player();
    if (environment(ob))
    {
    	if (objectp(exclude))
	    exclude = ({ exclude, ob });
	else if (exclude)
	    exclude += ({ ob });
	else
	    exclude = ({ ob });
	tell_room(environment(ob),str,exclude);
    }
}

nomask void write(string str)
{
    if (this_player())
	this_player()->receive_message(MT_NOTIFY,MA_UNKNOWN,
	    	previous_object(),str);
}

nomask varargs void printf(varargs mixed *args)
{
    if (this_player())
	write(apply(#'sprintf,args));
}

#if 0
// TODO: Beide nomask machen.
void tail(string file)
{
    int res;
    
    if(this_player() && call_resolved(&res, this_player(), "show_func_result",
	bind_lambda(unbound_lambda(0,({#'efun::tail, file})),
	    previous_object())))
	return;
    else
    {
	set_this_object(previous_object());
	efun::tail(file);
    }
}

varargs int cat(string file, int start, int num)
{
    int res;
    
    if(this_player() && call_resolved(&res, this_player(), "show_func_result",
	bind_lambda(unbound_lambda(0,({#'efun::cat, file, start, num})),
	    previous_object())))
	return res;
    else
    {
	set_this_object(previous_object());
	return efun::cat(file, start, num);
    }
}
#endif