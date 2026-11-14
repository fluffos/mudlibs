// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/secure.inc
// Description: Security Funktionen / Gesperrte Funktionen
// Author:	Freaky
// Modified by:	Freaky (31.03.1999) set_environment, object_info hinzugefuegt
//		Freaky (26.06.1999) command hinzugefuegt
//
// $Log: secure.inc,v $
// Revision 1.8  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.7  2013/03/16 16:03:36  gnomi
// functionlist() freigegeben.
//
// Revision 1.6  2005/08/28 21:15:28  gnomi
// Funktionsdeklaration von garbage_collection aktualisiert.
//
// Revision 1.5  2003/11/11 03:13:35  gnomi
// input_to_info gesperrt (ermoeglicht direkten Zugriff auf die
// input_to-Closures.)
//
// Revision 1.4  2003/03/02 13:50:48  freaky
// variable_list eingebaut
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

//
// Dieser File ist der einizge Teil der Simul Efun mit
// nomask simul_efun Privileg.
// (siehe /secure/master/compiler_control::privilege_violation())
//

/* 
 * Nur der Shutdown-Daemon darf die efun shutdown verwenden!
 */

/*
 * Gesperrte efuns
 */
#if __EFUN_DEFINED__(shutdown)
nomask void shutdown() {}
#endif

/*
#if __EFUN_DEFINED__(set_next_reset)
nomask int set_next_reset(int delay) {}
#endif
*/

#if __EFUN_DEFINED__(heart_beat_info)
nomask object *heart_beat_info() {}
#endif

#if __EFUN_DEFINED__(debug_info)
nomask varargs mixed debug_info(int flag, mixed m) {}
#endif

#if __EFUN_DEFINED__(move_object)
nomask void move_object(object ob1, object ob2) {}
#endif

#if __EFUN_DEFINED__(set_this_player)
nomask void set_this_player(object ob) {}
#endif

#if __EFUN_DEFINED__(set_environment)
nomask void set_environment(object ob1, object ob2) {}
#endif

#if __EFUN_DEFINED__(efun308)
nomask void efun308(object ob1, object ob2) {}
#endif

#if __EFUN_DEFINED__(swap)
nomask void swap(object ob) {}
#endif

#if __EFUN_DEFINED__(break_point)
nomask void break_point() {}
#endif

#if __EFUN_DEFINED__(query_actions)
nomask mixed *query_actions(mixed ob, mixed flag) {}
#endif

#if __EFUN_DEFINED__(garbage_collection)
nomask varargs void garbage_collection(string filename) {}
#endif

#if __EFUN_DEFINED__(command)
nomask int command(string str) {}
#endif

#if __EFUN_DEFINED__(last_instructions)
nomask varargs string *last_instructions(int len, int verbose) {}
#endif

#if __EFUN_DEFINED__(command_stack)
nomask mixed *command_stack() {}
#endif

#if __EFUN_DEFINED__(command_stack_depth)
nomask int command_stack_depth() {}
#endif

#if __EFUN_DEFINED__(set_buffer_size)
nomask int set_buffer_size(int size) {}
#endif

/*
#if __EFUN_DEFINED__(restore_value)
nomask mixed restore_value(string str) {}
#endif

#if __EFUN_DEFINED__(save_value)
nomask string save_value(mixed m) {}
#endif
*/

/*
#if __EFUN_DEFINED__(clones)
nomask varargs object *clones(mixed m, int i) {}
#endif
*/

#if __EFUN_DEFINED__(set_connection_charset)
nomask void set_connection_charset(mixed a, int i) {}
#endif

#if __EFUN_DEFINED__(binary_message)
nomask varargs int binary_message(mixed m, int i) {}
#endif

#if __EFUN_DEFINED__(query_ip_number)
nomask varargs string query_ip_number(object who)
{
    return "0.0.0.0";
}
#endif

#if __EFUN_DEFINED__(query_ip_name)
nomask varargs string query_ip_name(object who)
{
    return "leider.nicht.mehr.verfuegbar";
}
#endif

#if __EFUN_DEFINED__(variable_list)
nomask varargs mixed *variable_list(object ob, int flag) {}
#endif

#if __EFUN_DEFINED__(input_to_info)
nomask mixed *input_to_info(object ob) {}
#endif

#if __EFUN_DEFINED__(dump_driver_info)
varargs int dump_driver_info(int what, string filename) {}
#endif

/*
#if __EFUN_DEFINED__(query_command)
nomask string query_command() {}
#endif
*/
