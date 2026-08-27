//#pragma save_binary
/*
// File     :  _call.c
// Syntax   :  int cmd_call( string a );
// Purpose  :  allow wizards to call functions in objects
// 92-06-00 :  Douglas Reay (aka Pallando @ many muds) wrote a bin based wizard
//             tool for Ephemeral Dale lpmud (LPC2)
// 92-10-00 :  Pallando wrote a basic multi-reference tracer for this
// 93-01-02 :  Pallando changed refs to be stored on player not in daemon
//             This file is now part of the TMI-II mudlib distribution.
//             Please retain this header if you use any of this code.
// 93-03-19 :  Pallando changed refs over to get_objects()
// 93-07-17 :  Robocoder switched call_other to arrays, ie ({ func, args... })
// 93-08-20 :  Grendel allowed admins to call with any euid
// 93-08-23 :  Pallando changed it to inherit REF_D
// 93-10-21 :  Annihilator added a new format: call obj->function(arg,..)
*/
#include <daemons.h>
#include <mudlib.h>
#include <logs.h>
#include <uid.h>

inherit DAEMON;
inherit REF_D;

#define FUNC_LIST ({ "query_skills", "query_nicknames", "query_aliases" })
#define TAB "\t"

mixed do_call( object ob, string func, mixed args );
int help();

cmd_datacall( string a )
{
	string str, ob_name, *exp_a;
	mixed objs, funcs, args, tmp, ret, rets;
	object ob, act_ob;
	int i, s, fi, fs;

	if( !a ) { return help(); }

#ifdef WIZ_DATA_CHANGE_LOG
	seteuid(ROOT_UID);
	if(!member_group(geteuid(this_player()), "admin"))
		log_file(WIZ_DATA_CHANGE_LOG, "************\n" +
			extract(ctime(time()), 4, 15) +
			" [" + geteuid(this_player()) + "] call'd: " + a + "\n");
#endif

	// do this first in case something bombs out below
	seteuid( geteuid( previous_object() ) );

	if( sscanf(a, "%s->%s(%s)", ob_name, funcs, args) == 3 ) {
		args = explode( args, "," );
	} else
	    return help();

        if( ob_name == "me" ) {act_ob = this_player(); seteuid(ROOT_UID);}
	else act_ob = find_living( ob_name );
	if( !act_ob ) return notify_fail("No such living object!\n");
	if( member_group(geteuid(this_player()), "admin") || !act_ob->query("user") )
		objs = ({ act_ob });
	else
		objs = ({ this_player() });

	funcs = resolv_ref( funcs );
	if( !pointerp( funcs ) ) funcs = ({ funcs });
	tmp = ({ });
	s = sizeof( funcs );
	for( i = 0 ; i < s ; i ++ )
	{
		if( stringp( funcs[i] ) ) tmp += ({ funcs[i] });
		else write( wrap( "Can't identify " + identify( funcs[i] )+
			" as a string." ) );
	}
	if( !sizeof( tmp ) ) return 1;
	funcs = tmp;

	if( pointerp( args ) && ( s = sizeof( args ) ) )
		for( i = 0 ; i < s ; i++ )
			args[i] = resolv_ref( resolv_str( args[i] ) );

	rets = ({ });
	s = sizeof( objs );
	fs = sizeof( funcs );
	for( i = 0 ; i < s ; i++ )
	{
		str = identify( objs[i] );
		for( fi = 0 ; fi < fs ; fi++ )
		{
			ret = do_call( objs[i], funcs[fi], args );
			if( ret[0] ) rets += ({ ret[0] });
			if( fs == 1 ) str = wrap( str + ret[1] );
			else str += (fi?"":"\n") + wrap( ret[1] );
		}
		write( str );
	}
	switch( sizeof( rets ) )
	{
		case 0: rets = 0; break;
		case 1: rets = rets[0];
	}
	set_ref( "default", rets );

	return 1;
}

do_call( object ob, string func, mixed args )
{
	mixed ret, err;
	int i, s;
	string str;
	object shad;

	if( !function_exists( func, ob ) )
	{
		for( shad = shadow( ob, 0 ) ; shad ; shad = shadow( shad, 0 ) )
			if( function_exists( func, shad ) ) { ob = shad; break; }
//		if( ob != shad ) return ({ 0, "- does not contain " + func + "()" });
	}
	str = "-> " + func;
	if( pointerp( args ) && ( s = sizeof( args ) ) )
	{
		str += "( ";
		for( i = 0 ; i < s ; i++ )
		{
			if( i ) str += ", ";
			str += identify( args[i] );
		}
		str += " )";
	} else str += "()";
		
	if (!s) {
			err = catch(
				ret = call_other(ob, func)
			);
	} else {
			err = catch(
				ret = call_other(ob, ({ func }) + args)
			);
	}
	if( err ) return ({ 0, str + TAB + "= ERR(" + identify( err ) + ")" });
	return ({ ret, str + TAB + "= " + identify( ret ) });
}

int help()
{
	write( @HELP_MSG
Syntax: datacall <obj_name>-><function>(<arg>,<arg>.....)

Effect: Calls the function <function> in obj data,
        passing as many arguments <arg> as you give.
        eg:
             datacall me->query("short")
HELP_MSG
	);
	return 1;
}
