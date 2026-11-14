#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xhb"; }

int is_player(object obj) {
  return obj&&obj==find_player(getuid(obj));
}

int _check_netdead( object ob ) {
  if ( is_player(ob)&&!interactive(ob) )
    return 1;
  else if ( environment(ob) && 
	    ( is_player(environment(ob))&&!interactive(environment(ob))) ) 
    return 1;
  else
    return 0;
}

int main(string str ) {
  object obj, *hbeatinfo;
  string tmp, file, tx, *sx;
  int i, s, cnt, verbose_mode, netdead_mode;

  notify_fail("xhb(eats) [-v] [-n] <.|search pattern>\n");

  if ( (!str) || (str=="?" ) )
    return 0;

  if ( ! sizeof ( sx = explode( str, " " ) - ({ "" }) ) )
    return 0;

  netdead_mode = 0;
  verbose_mode = 0;
  if ( sizeof( sx ) > 1 ) {
    while( sx[0][0] == '-' ) {
      /* test for known params */
      switch( sx[0] ) {
      case "-v":
	verbose_mode = 1;
	break;
      case "-n":
	netdead_mode = 1;
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

  file="/players/"+getuid(cloner)+"/.tmp";
  if(file_size(file)>0) rm(file);
  if(!str) str=getuid(cloner);
  else if(!regexp(({"dummy"}), str)) {
    tell_object( cloner, "Bad regular expression.\n" );
    return 1;
  }
  s=sizeof(hbeatinfo=heart_beat_info());
  cnt = 0;
  for(i=0; i<s; i++) {
    if(hbeatinfo[i]&&objectp(hbeatinfo[i])) {
      tmp = ObjFile(hbeatinfo[i]);
      if(sizeof(regexp(({tmp}), str))) {
        if ( ( ! netdead_mode ) || ( _check_netdead( hbeatinfo[i] ) ) ) {
          if ( verbose_mode ) {
            write_file(file, PrintShort("",hbeatinfo[i],1)+"\n");

            if ( obj = environment(hbeatinfo[i]) )
              write_file(file, PrintShort(" (E) ",obj, 1)+"\n");
            else
              write_file(file, " (E) <no environment>\n" );
          }
          else
            write_file(file, tmp+"\n");
          cnt ++;
        }
      }
    }
  }
  write_file(file,"\nTotal matching hbeats to '"+str+"': "+to_string(cnt)+"\n");

  XMoreFile(file, 0);
  return 1;
}






