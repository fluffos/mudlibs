
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是西大街。东面是九江的中心，从东边传了阵阵的热闹声音。
北面有一家钱庄，南面有一家饭庄。里面传来阵阵的菜香，店小二正在
门前热情地招呼着客人。
LONG);

  set("exits", ([ 

  "south":__DIR__"fanzhuang",
  "north":__DIR__"qianzhuang",
  "east":__DIR__"center",
  "west":__DIR__"xidajie2",
         ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

