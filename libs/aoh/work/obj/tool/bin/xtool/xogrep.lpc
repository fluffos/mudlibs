/*
** xogrep - grep global object list
*/

#define MAX_A 500

#include "../bincmd.h"

inherit BASICXCMD;

int norm;
mixed * aarray;
string expr, file;


QueryAbrev() { return "xogre"; }

int main( string str ) {
  string * sx;
  int cnt, cnt2, acnt;
  object ob;

  notify_fail( "xogre(p) [-p] [-f <file>] <pattern>\n"), 0;

  if ( (!str) || ( str == "?" ) )
    return 0;

  if ( ! sizeof ( sx = explode( str, " " ) - ({ "" }) ) )
    return 0;

  file = 0; norm = 0;
  if ( sizeof( sx ) > 1 ) {
    while( sx[0][0] == '-' ) {
      /* test for known params */
      switch( sx[0] ) {
      case "-p":
	norm = 1;
	break;
      case "-f":
	if ( sizeof( sx ) > 2 ) {
	  sx = sx[1..]; /* remove -f */
	  file = MASTER->make_path_absolute( sx[0] ); /* expand ~ etc. */
	}
	else
	  tell_object( cloner, "Invalid -f parameter - using default filename.\n" );
	break;
      default:
	break;
      }
      sx = sx[1..]; /* remove param */
    }
    if ( ! sizeof( sx ) )
      return 0;
  }

  str = implode( sx, " " );

  if ( ! ( regexp( ({ "dummy" }), str ) ) ) {
    tell_object( cloner, "Bad regular expression.\n" );
    return 1;
  }

  expr = str; /* save it for global access */

  SetDestruct( 0 ); /* We work with callouts to prevent too long evals */
  
  acnt = 0;
  aarray = ({ allocate( MAX_A ) }) ; /* alloc MAX_A entries */
  cnt2 = 0;
  cnt = 0;
  while( ob = debug_info( 2, cnt ) ) {
    aarray[acnt][cnt2] = ob;
    cnt2++;
    if ( cnt2 >= MAX_A ) {
      acnt++;
      cnt2 = 0;
      aarray += ({ allocate( MAX_A ) });
    }

    cnt++;    
  }

  tell_object( cloner, "Total number of processed objects: "+cnt+"\n" );
  tell_object( cloner, "Now calling out with "+(acnt+1)+" passes.\n" );

  if ( ! file )
    file = "/players/"+getuid(cloner)+"/xogrep.results";

  if ( ! norm ) {
    if ( file_size( file ) > 0 )
      rm( file );
  }

  call_out( "dump_objects", 1, 0 );

  return 1;
}

dump_objects( int cnt ) {
  int i;
  string * fnames;

  tell_object( cloner, "xogrep processing pass "+cnt+"\n" );

  /* allocate filenames array */
  fnames = allocate( sizeof( aarray[cnt] ) );

  /* get all filenames */
  for( i = 0; i < sizeof( aarray[cnt] ); i ++ ) {
    if ( objectp( aarray[cnt][i] ) )
      fnames[i] = object_name( aarray[cnt][i] );
    else
      fnames[i] = 0;
  }
    
  /* filter all filenames with expr */
  fnames = regexp( fnames, expr );

  for( i = 0; i < sizeof( fnames ); i ++ ) {
    if ( fnames[i] ) {
      write_file( file, fnames[i] + "\n" );
    }
  }

  fnames = 0; /* free the memory */
  aarray[cnt] = 0; /* free the memory */

  cnt++;
  if ( cnt < sizeof( aarray ) )
    call_out( "dump_objects", 1, cnt );
  else {
    tell_object( cloner, "xogrep callout processing finished.\n" );
    if ( file_size( file ) > 0 ) {
      tell_object( cloner, "xgrep result dumped to "+short_path(file)+"\n" );
    }

    remove();
  }
}

