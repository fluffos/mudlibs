/*
** The basic binary command
**
** 02Feb97 [Mica] Initial creation
** 06Sep98 [Softbyte] QueryAuthor stuff
** 18Sep98 [Softbyte] Help support
**
*/

#include <config.h>

object cloner;
object dispatcher;
int pDestruct;

object QueryDispatcher() {return dispatcher;}
object QueryCloner() {return cloner;}

/*
** QueryIsBinCommand returns always 1
*/

public int QueryIsBinCommand() { return 1; }

/*
** QueryEUIDRequired needs to return 1 if the command needs EUID
** Default is 0
*/

public int QueryEUIDRequired() { return 0; }

/*
** No shadowing of binary commands is default
*/

public int prevent_shadow( object by ) { 
  return 1; 
}

/*
** Binary commands support remove() and clean_up() to fit the game drivers
** needs. Modify these to fit YOUR needs.
*/

public int remove() {
  if ( this_object() ) {
    destruct( this_object() );
  }
  return 1;
}

public int clean_up( int ref ) {
  remove();
  return this_object() && 1;
}

/*
** QueryDestruct returns true default, which means that the clone is auto-
** matically destroyed by the command dispatcher after execution.
** Change this if you want to do that yourself
*/

public int QueryDestruct() { 
  return pDestruct; 
}

public int SetDestruct( int n ) { 
  return pDestruct = n;
}

/*
** Provide dummy Author and version for modules not defining them
*/
string QueryVersion() {return "V0.0";}
string QueryAuthor() {return "Unknown";}

/*
** Create checks the previous object chain for other uids/euids than getuid()
** We do not TP==TI check here, as the above detects that too and that should
** be done by the command dispatcher.
*/

public int create() {
  int poc;
  object prev;

  if ( ! is_clone( this_object() ) )
    return 1;

  cloner = this_player();
  dispatcher = previous_object(); /* get the object of the dispatcher */
  pDestruct = 1;

  if ( QueryEUIDRequired() ) {
    seteuid( getuid() );

    for ( poc = 0; prev = previous_object( poc ); poc++ ) { 
      if ( ( getuid( prev ) != ROOTID ) &&
	   ( ( getuid( prev ) != getuid() ) ||
	     ( geteuid( prev ) != geteuid() ) ) ) {
	tell_object( cloner, sprintf( "Security violation detected in [%O].\n  previous_object( %O ) has uid %O and euid %O\n", this_object(), poc, getuid( prev ), geteuid( prev ) ) );
	destruct( this_object() );
	return 1;
      }
    }
  }
  else {
    seteuid( 0 );
  }

  return 0;
}

/*
** The help checker
*/
public int CheckHelp(string str)
{
string verb;
  verb=query_verb();
  if (!str || !verb || !dispatcher) return 0;
  if (-1!=member(({"?","help","/?","--help","-h","-?"}),str))
  {
    return dispatcher->cmd_binhelp(verb); 
  }
  return 0;
}
