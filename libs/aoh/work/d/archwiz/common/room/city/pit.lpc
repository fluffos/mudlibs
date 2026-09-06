#include "path.h"
#include <moving.h>
#include <secure/wizlevels.h>
#include <rooms.h>

inherit "/std/room";

destruct_me(object ob) {
  ob->remove();
  if (ob) destruct(ob);
}

moveme(object ob) {
  if (!ob) return 0;
  ob->move(CITY("church"),M_SILENT);
  return 1;
}

Die(object pl) {
  write("You fall .. and fall .. and fall\n"
"You feel something sucking away your lifeenergy.\n");
  if (IS_IMMORTAL(pl)) {
    write("You can't die, but it is really boring here.\n");
    return;
    }
  pl->Die();
}

notify_enter(mixed from,int method,mixed extra) {
  object po;
  if(!living(po=previous_object())) {
    call_out(#'destruct_me,1,po);
    }
  else {
    if(objectp(from)) from = object_name(from);
    if ((from!=CITY("church")) || (po->QueryGhost())) {
      call_out(#'moveme,1,po);
      }
    else {
      call_out(#'Die,1,po);
      }
    }
  return ::notify_enter(from,method,extra);
}

create() {
  ::create();
  SetIntShort("A bottomless pit");
  SetIntLong("Darkness surrounds you.. you fall..\n");
  AddDetail("darkness","It is dark.\n");
  SetIntLight(-2000);
  SetTPort(TPORT_NO);
  SetIndoors(1);
}
