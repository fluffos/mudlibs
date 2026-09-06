#include "../bincmd.h"

inherit BASICXCMD;

int main( string str ) {
  int i, n, s, rc;
  string *strs, cmd;

  notify_fail( "xdo [<number1>#]<command1>[;[<number2>#]<command2>] ...\n" );
  if( (!str)||(str=="?") )
    return 0;

  if(!(s=sizeof(strs=explode(str, ";")-({""})))) 
    return 0;

  for(i=0; i<s; i++) {
    if(strs[i]) {
      switch(sscanf(strs[i], "%d#%s", n, cmd)) {
      case 0:
	dispatcher->IncreaseNostore();
	rc = cloner->command_me( strs[i] );
	dispatcher->DecreaseNostore();
	if ( ! rc )
	  return 1;
	break;
      case 1:
	if ( cmd ) {
	  dispatcher->IncreaseNostore();
	  rc = cloner->command_me( cmd );
	  dispatcher->DecreaseNostore();
	  if ( ! rc )
	    return 1;
	}
	break;
      case 2:
	n= n<1 ? 1 : n;
	if(cmd) {
	  while(n--) {
	    dispatcher->IncreaseNostore();
	    rc = cloner->command_me( cmd );
	    dispatcher->DecreaseNostore();
	    if ( ! rc )
	      return 1;
	  }
	}
	break;
      }
    }
  }
  return 1;
}




