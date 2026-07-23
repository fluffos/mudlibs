
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","小凉亭");
  set ("long", @LONG
这里是座凉亭，供游客休息之用。你来到这里，清风迎面而来，不
觉精神一振。由于这里离扬州的北门不远，风景宜人，所以往来的游客
并不少。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"lvyinlu",
         ]));
   set("objects",([
     __DIR__"npc/xiaojie1":1,
     ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}
