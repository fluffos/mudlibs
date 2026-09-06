/*
** The basic 'Left-Right' room
** Creator: Mica 24Jan97
** NOTES: ExitList assumes that this_player() queries the exits!
**        Currently only north, south, west and east are supported for
**        AddLrExit
*/

#pragma strict_types

#include <rooms.h>
#include <moving.h>
#include <config.h>
#include <macros.h>

inherit "/std/room";

/*
** Variables
*/

mapping efrom; /* the directions players enter from are noted here */
mapping lrexits; /* the possible exits are stored here */

/*
** Exits handling
*/

private string _opposite( string dir ) {
  if ( dir == "north" ) return "south";
  else if ( dir == "south" ) return "north";
  else if ( dir == "west" ) return "east";
  else return "west";
}

/* Convert left, right etc. based on room ENTER direction */
private string _evaluatedir2( string ifrom, string lrdir ) {
  int a, b, d;

  a = member( ({ "north", "west", "south", "east" }), ifrom ) + 1;
  b = member( ({ "back", "left", "forward", "right" }), lrdir ) + 1;
  if ( ( a < 0 ) || ( b < 0 ) ) return 0;

  d = a-b;
  if ( d < 0 ) d += 4;

  return ({ "north", "west", "south", "east" })[d];
}

/* Convert direction into left, right etc. */
private string _evaluatedir( string ifrom, string dir ) {
  int a, b, d;

  a = member( ({ "north", "west", "south", "east" }), ifrom ) + 1;
  b = member( ({ "north", "west", "south", "east" }), dir ) + 1;
  if ( ( a < 0 ) || ( b < 0 ) ) return 0;

  d = a-b;
  if ( d < 0 ) d += 4;

  return ({ "back", "left", "forward", "right" })[d];
}

/* Evaluate the possible directions */
/* efrom has to be a mapping and has to exist */
private string * _evaluatedirs( object pl ) {
  string * ret, * dirs, ts;
  int i;

  ret = ({});

  if ( ( ! mappingp( lrexits ) ) || ( ! sizeof( lrexits ) ) )
    return ret; /* just in case... */

  dirs = m_indices( lrexits );

  for( i = 0; i < sizeof( dirs ); i ++ ) {
    if ( ts = _evaluatedir( efrom[pl], dirs[i] ) ) {
      ret += ({ ts });
    }
  }

  return ret;
}

public mixed * ExitList () {
  mixed * e;
  object pl;

  /* Query the ExitList and remove our (dummy)exits */
  e = ::ExitList();
  e[0] -= ({ "left", "right", "back", "forward" });
  e[1] -= ({ "left", "right", "back", "forward" });
  pl = this_player();

  if ( ( ! pl ) ||
       ( ! mappingp( efrom ) ) ||
       ( ! efrom[pl] ) )
    return e;

  e[0] += _evaluatedirs( pl );

  return e;
}

/*
** Entered from handling
*/

private void _insertfrom( object pl, string dir ) {
  if ( ! mappingp( efrom ) )
    efrom = ([ pl : dir ]);
  else
    efrom[ pl ] = dir;
}

private void _removefrom( object pl ) {
  if ( ! mappingp( efrom ) ) return;
  m_delete( efrom, pl );
  if ( ! sizeof( efrom ) ) efrom = 0;
}


public mapping QueryFrom() { return efrom; }
public mapping SetFrom( mapping x ) { return efrom = x; }
public void AddFrom( object pl, string dir ) {
  _insertfrom( pl, dir );
}

/*
** Custom IssueEnterMessages and IssueLeaveMessages
*/

private int _invis_filter( object ob, object pl ) {
  if ( ! ({int})ob->QueryIsLiving() )
    return 0;

  if ( query_user_level(ob) )
    return 1;

  if ( ( ! query_user_level( pl ) ) &&
       ( ({int})ob->Query( P_SEE_INVIS ) ) )
    return 1;

  return 0;
}

private void _issue_movemsg( object pl, string dir, int lv ) {
  string movemsg, movemsg2, altmsg, ifrom, lto;
  int inv, i;
  object * tgt;
  mixed msgin;

  movemsg = RNAME(pl)||({string})pl->QueryShort();
  if ( !movemsg || ( movemsg == "" ) ) return;

  inv = ({int})pl->QueryInvis();

  if ( inv ) {
    movemsg = "("+CAP(movemsg)+")";
    tgt = filter( all_inventory(TO), SF(_invis_filter), pl );
  }
  else {
    movemsg = CAP( movemsg );
    tgt = filter( all_inventory(TO), "QueryIsLiving" );
  }

  tgt -= ({ pl });

  if ( lv )
    msgin = ({string})pl->Query( P_MSGOUT ) || "leaves";
  else
    msgin = ({string})pl->Query(P_MSGIN ) || "arrives";

  movemsg = movemsg+" "+(stringp(msgin) ? msgin : msgin[0]);

  altmsg = ({int})pl->QueryIsLiving() ? "Someone " : "Something ";
  altmsg = pointerp(msgin) ? msgin[1] : (altmsg+ (lv?"leaves":"arrives") );
  if(member(".!?", altmsg[<1]) == -1)
    altmsg += ".";

  for( i = 0; i < sizeof( tgt ); i ++ ) {
    if ( ( ifrom = efrom[tgt[i]] ) &&
	 ( lto = _evaluatedir( ifrom, dir ) ) ) {
      if ( lv )
	movemsg2 = movemsg + " "+lto+".";
      else
	movemsg2 = movemsg + " from "+lto+".";
      show_object( tgt[i], ({ movemsg2+"\n", altmsg+"\n" }) );
    }
    else {
      movemsg2 = movemsg;
      if(member(".!?", movemsg2[<1]) == -1)
	movemsg2 += ".";
      show_object( tgt[i], ({ movemsg2+"\n", altmsg+"\n" }) );
    }
  }
}

public void IssueEnterMessages( object pl, mixed from,
				int method, mixed extra ) {
  if ( ( method == M_GO ) &&
       ( stringp( extra ) ) &&
       ( member( ({ "north", "south", "west", "east" }), extra ) != -1 ) ) {
    extra = _opposite( extra );
    _insertfrom( pl, extra );
    _issue_movemsg( pl, extra, 0 );
  }
  else {
    if ( interactive( pl ) ) {
      tell_object( pl, "You somehow lost the orientation.\n" );
    }

    _insertfrom( pl, ({ "north", "south", "west", "east" })[random(3)] );

    ::IssueEnterMessages( pl, from, method, extra );
  }
}

public void IssueLeaveMessages( object pl, mixed to,
				int method, mixed extra ) {
  _removefrom( pl );

  if ( ( method == M_GO ) &&
       ( stringp( extra ) ) &&
       ( member( ({ "north", "south", "west", "east" }), extra ) != -1 ) ) {
    _issue_movemsg( pl, extra, 1 );
  }
  else
    ::IssueLeaveMessages( pl, to, method, extra );
}

/*
** Movement basics
*/

public int do_walk( string arg ) {
  string realdir, verb;

  notify_fail( "No way.\n", NOTIFY_NOT_VALID );
  if ( ! ( verb = query_verb() ) ) return 0;
  if ( ! mappingp( lrexits ) ) return 0;
  if ( ! TP ) return 0;

  if ( ! mappingp( efrom ) ) return 0;
  if ( ! efrom[TP] ) return 0;
  if ( ! ( realdir = _evaluatedir2( efrom[TP], verb ) ) ) return 0;
  if ( ! lrexits[realdir] ) return 0;

  if ( ({int})TP->move( lrexits[realdir], M_GO, realdir ) != ME_OK )
    return 0;

  return 1;
}

/*
** The Left-Right Exits
** dir is the REAL direction, has to be north, south, west or east
*/

public mapping QueryLrExits() { return lrexits; }
public mapping SetLrExits( mapping ex ) { return lrexits = ex; }

public void AddLrExit( string dir, string dest ) {
  if ( member( ({ "north", "south", "west", "east" }), dir ) == -1 )
    return 0;

  if ( ! mappingp( lrexits ) )
    lrexits = ([ dir : resolve_file( dest ) ]);
  else
    lrexits[ dir ] = resolve_file( dest );
}

/*
** Creation
*/

public varargs void create() {
  (::create());

  AddExit( ({ "forward", "left", "right", "back" }), SF( do_walk ) );
}
