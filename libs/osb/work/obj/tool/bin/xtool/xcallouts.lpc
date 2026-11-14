#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xcallo"; }

int main(string str ) {
  object obj, obj2;
  mixed callouts, args, fun;
  string tmp, file, *sx;
  int delay, i, s, cnt, verbose_mode;

  notify_fail( "xcallo(uts) [-v] <.|search pattern>\n");

  if ( (!str) || ( str == "?" ) )
    return 0;

  if ( ! sizeof ( sx = explode( str, " " ) - ({ "" }) ) )
    return 0;

  verbose_mode = 0;
  if ( sizeof( sx ) > 1 ) {
    while( sx[0][0] == '-' ) {
      /* test for known params */
      switch( sx[0] ) {
      case "-v":
	verbose_mode = 1;
	break;
      default:
	break;
      }
      /* remove params */
      sx = sx[1..];
    }
    if ( ! sizeof( sx ) )
      return 0;
  }

  str = implode( sx, " " );

  file = "/players/"+getuid(cloner)+"/.tmp";
  if ( file_size( file ) > 0 ) 
    rm( file );
  if(!str) str="^\\[~/";
  else if(!regexp(({"dummy"}), str)) {
    tell_object( cloner, "Bad regular expression.\n" );
    return 1;
  }
  callouts=call_out_info();
  s=sizeof(callouts);
  cnt = 0;
  for(i=0; i<s; i++) {
    if(callouts[i]&&pointerp(callouts[i])) {
      fun = callouts[i][1];
      obj = closurep(fun) ? to_object(fun) : callouts[i][0];
      tmp=ObjFile(obj)+" "+callouts[i][2]+"s "+ sprintf( "%O", fun )+"("+
      (sizeof(callouts[i])>3?"/lib/string"->mixed_to_string(callouts[i][3], 6):"")
        +")";
      if(sizeof(regexp(({tmp}), str))) {
        if ( verbose_mode ) {
          write_file(file, PrintShort("",obj,1)+"\n");

          if ( obj2 = environment(obj) )
            write_file(file, PrintShort(" (E) ",obj2,1)+"\n");
          else
            write_file(file, " (E) <no environment>\n" );

          write_file(file," (I) "+callouts[i][2]+"s "+sprintf("%O",fun)+"("+(sizeof(callouts[i])>3?"/lib/string"->mixed_to_string(callouts[i][3], 6):"")+")\n");
	}
        else
          write_file(file, tmp+"\n");
        cnt++;
      }
    }
  }
  write_file(file,"\nTotal matching callouts to '"+str+"': "+to_string(cnt)+"\n"); 

  XMoreFile(file, 0);
  return 1;
}



