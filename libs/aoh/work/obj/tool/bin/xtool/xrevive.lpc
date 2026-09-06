#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xre"; }

int is_player(object obj) {
  return obj&&obj==find_player(getuid(obj));
}

int main( string str ) {
  object obj;

  if ( str == "?" )
    return notify_fail( "xre(vive) <player>\n"), 0;

  if ( obj = XFindObj(str) ) {
    if ( is_player(obj) ) {
      tell_object( cloner,"Reviving player "+capitalize(obj->QueryRealName()+".\n" ));
      obj->turn_heart_beat(0);
      obj->turn_heart_beat(1);
      if(member(heart_beat_info(), obj) < 0)
        tell_object( cloner, "Reviving failed.\n");
    } else
      tell_object( cloner, "Specified object is not a player.\n" );
  }
  return 1;
}



