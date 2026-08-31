#include <std.h>
#include <nwvforest3.h>
 
inherit VIRTUALROOM;
 
void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "west" : ROOMS"room02", 
                "north" : ROOMS"room03", 
                "southeast" : ROOMS"room00",
  ]) );
}
