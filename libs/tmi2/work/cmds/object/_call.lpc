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
// 93-10-22 : Mobydick added the ADMIN_ONLY define.
*/
#include <daemons.h>
#include <mudlib.h>
#include <logs.h>
#include <uid.h>

#define NO_USER_CALLS 1

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: call [-<uid>] <object>;<function>;<arg>;<arg>\n"
#define FUNC_LIST ({ "query_skills", "query_nicknames", "query_aliases" })
#define TAB "\t"

protected
string * do_call( object ob, string func, mixed args );

int cmd_call( string a )
{
  string str, *exp_a;
  mixed objs, funcs, args, tmp, ret, rets;
  object ob;
  int i, s, fi, fs;

  if( !a ) { notify_fail( SYNTAX ); return 0; }

#ifdef ADMIN_ONLY
  if (!adminp(geteuid(this_player()))) {
    write ("Sorry, this command can only be used by admins.\n") ;
    return 1 ;
  }
#endif


#ifdef EVAL_CALL_LOG

    seteuid(ROOT_UID);
    if (!adminp(geteuid(this_player())))
        log_file(EVAL_CALL_LOG, "************\n" +
             extract(ctime(time()), 4, 15) +
            " [" + geteuid(this_player()) + "] call'd: " + a + "\n");
#endif

  // do this first in case something bombs out below
  seteuid( geteuid( previous_object() ) );

  if(a[0] == '-')
  {
    if(a[1] == '-')
      a = a[2..<1];
    else if (geteuid(previous_object())
	     && adminp(geteuid(previous_object()))
	     && previous_object() == this_player()
	     && this_player() == this_player(1))
    {
      i = strsrch(a, ' ');
      if(i != -1)
      {
	seteuid(a[1..(i-1)]);
	a = a[(i+1)..<1];
      } else {
	notify_fail("call: seteuid: bad euid\n");
	return 0;
      }
    } else {
      notify_fail("call: seteuid: permission denied\n");
      return 0;
    }
  }

  exp_a = explode( a, ";" );
  s = sizeof( exp_a );
  objs = exp_a[0];
  if( s > 1 ) funcs = exp_a[1];
  else funcs = FUNC_LIST;
  if( s == 3 ) args = ({ exp_a[2] });
  if( s > 3 ) args = exp_a[2..(s-1)];

  objs = resolv_ref( objs );
  if( objs == "users" ) objs = users();
  if( !pointerp( objs ) ) objs = ({ objs });
  tmp = ({ });
  s = sizeof( objs );
  for( i = 0 ; i < s ; i++ )
  {
    if( stringp( objs[i] ) ) ob = get_objects( objs[i],0,1 );
    else if( objectp( objs[i] ) ) ob = objs[i];
    if( !ob ) write( wrap( "Can't identify " + identify( objs[i] ) +
      " as an object." ) );
    else tmp += ({ ob });
  }
  if( !sizeof( tmp ) ) return 1;
  objs = tmp;

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

protected
string *do_call( object ob, string func, mixed args )
{
  mixed ret, err;
  int i, s;
  string str;
  object shad;

  if( !function_exists( func, ob ) )
  {
    for( shad = shadow( ob, 0 ) ; shad ; shad = shadow( shad, 0 ) )
      if( function_exists( func, shad ) ) { ob = shad; break; }
    if( ob != shad ) return ({ 0, "- does not contain " + func + "()" });
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
    
#ifdef NO_USER_CALLS
  if (!adminp(getuid(this_player()))) {
    if (userp(ob) && getuid(ob)!=getuid(this_player())) {
	return ({ 0, str+" = Illegal operation." }) ;
    }
  }
#endif
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
  write( SYNTAX +
    "Effect: Calls the function <function> in object <object>,\n"+
    "passing as many arguments <arg> as you give.\n"+ 
    "If no function is specified a dump of the object is given.\n"+
    "<object> and <function> can be arrays (eg \"users\")\n"+
    "Any of them can be references (qv help refs)\n"+
  "" );
  return 1;
}

