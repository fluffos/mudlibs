
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。据说这里经常有土匪出没，你不禁小心起来。这里
风景秀丽，山水如画，空气清新。不时有野兔从你的脚旁跳过。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing3",
  "southeast":__DIR__"shanlu2",
  "southup":__DIR__"shanbao",
       ]));
  set("objects",([
       __DIR__"npc/tufei":1,
       ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

