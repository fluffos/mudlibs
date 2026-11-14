#include "../bincmd.h"

inherit BASICXCMD;

int main(string str ) {
  string file;

  notify_fail( "xed <filename> [start]\n" );
  if ( ( ! str ) || ( str == "?" ) )
    return 0;
  
  if ( file = XFindFile(str) ) {
   dispatcher->IncreaseNostore();
   cloner->command_me( "ed "+file );
   dispatcher->DecreaseNostore();
  }

  return 1;
}



