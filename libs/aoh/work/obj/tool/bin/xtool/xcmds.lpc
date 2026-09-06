#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xcm"; }

int main( string str ) {
  object obj;
  string file;
  mixed *cmds;
  string * sx;
  object tgt;
  int i, s;

  notify_fail( "xcm(ds) [-o <target>] [object]\n"), 0;

  if ( str == "?" )
    return 0;
  
  tgt = 0;
  if ( str ) {
    sx = explode( str, " " ) - ({ "" });
    if ( sizeof( sx ) ) {
      while( ( sizeof(sx) ) && ( sx[0][0] == '-' ) ) {
	/* test for known params */
	switch( sx[0] ) {
	case "-o":
	  if ( sizeof( sx ) > 1 ) {
	    sx = sx[1..]; /* remove -o */
	    if ( ! tgt = XFindObj( sx[0] ) )
	      return 1;
	  }
	  else {
	    tell_object( cloner, "Invalid -o parameter.\n" );
	    return 1;
	  }
	  break;
	default:
	  break;
	}
	sx = sx[1..]; /* remove param */
      }
    }

    if ( sizeof( sx ) )
      str = implode( sx, " " );
    else
      str = 0;
  }

  if ( ! tgt )
    tgt = cloner;

  if ( ! str ) 
    obj = environment( tgt );
  else if ( ! ( obj = XFindObj( str ) ) )
    return 1;

  file="/players/"+getuid(cloner)+"/.tmp";
  if ( file_size( file ) > 0 ) rm( file );

  write_file( file, PrintShort( "Target object: ", tgt, 1 )+"\n" );
  write_file( file, PrintShort( "Action object: ", obj, 1 )+"\n" );
  write_file( file, "\n" );

  s=sizeof( cmds = query_actions( tgt, 1|2|4|8|16 ) );
  for(i=0; i<s; i+=5) {
    if(cmds[i+3]==obj) {
      write_file(file, sprintf( "%-15.15'.'s", cmds[i]+" " )+
		 (cmds[i+1] ? " * " : " . ")+cmds[i+4]+"()\n");
    }
  }
  XMoreFile(file, 0);

  return 1;
}




