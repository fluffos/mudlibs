#include "../bincmd.h"

inherit BASICXCMD;

int main(string str ) {
  object obj;

  if ( (!str) || ( str=="?" ) )
    return notify_fail( "xtran(s) <object>\n"), 0;

  if((obj=XFindObj(str))&&environment(obj)) {
    tell_room(environment(obj), obj->QueryName()+" vanishes.\n", ({ obj }) );
    tell_room(environment(cloner), obj->QueryName()+
              " is teleported into this room by "+cloner->QueryName()+".\n");
    MoveObj(obj, environment(cloner), 1);
    tell_object(obj, "You've been teleported to "+cloner->QueryName()+".\n");
    obj->LookAfterMove();
  } else
    tell_object( cloner, "Failed to teleport object.\n" );

  return 1;
}



