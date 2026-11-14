#include "../bincmd.h"

inherit BASICXCMD;

#define EXEC_LINES 10
#define EXEC_TIME 1

string * scriptline;
int scriptsize;

QueryDestruct() { return 0; }

void XExecFile(int line) {
  int i, rc;
  
  if ( ! scriptline ) { 
    remove();
    return;
  }

  for ( i = line; (i<scriptsize) && (i<line+EXEC_LINES); i++) {
    if ( ! scriptline[i] ) 
      continue;

    dispatcher->IncreaseNostore();
    rc = cloner->command_me( scriptline[i] );
    dispatcher->DecreaseNostore();

    if ( ! rc ) {
      remove();
      return;
    }
  }

  if ( i < scriptsize ) 
    call_out( SF( XExecFile ), EXEC_TIME, i );
  else
    remove();
}


int main( string str ) {
  notify_fail( "xsh <filename>\n" );
  if ( str == "?" ) return 0;

  SetDestruct( 0 ); /* prevent autodestruct */

  if ( ! ( str = XFindFile( str ) ) ) return 1;

  str = read_file( str, 1, 5000 );
  if ( ! ( scriptline = explode( str, "\n" ) ) ) {
    tell_object( cloner, "Bad script file\n" );
    return 1;
  }
  scriptsize = sizeof( scriptline );

  call_out( SF( XExecFile ), EXEC_TIME, 0 );
  return 1;
}




