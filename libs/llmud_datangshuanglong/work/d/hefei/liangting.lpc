
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","小凉亭");
  set ("long", @LONG
这里是座凉亭，供游客休息之用。你来到这里，清风迎面而来，不
觉精神一振。旁边有一条清澈的小河从桥底留过，你在这里呼吸着自由
的空气，仿佛来到了世外桃源。
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaoqiao",
         ]));
   set("objects",([
       __DIR__"npc/gongzi":1,
       ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}
