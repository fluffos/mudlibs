
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","合肥广场");
  set ("long", @LONG
这里是合肥的中心广场了。这里是合肥最热闹的地段。你四处看看，
只见打把势、卖艺的三五成群，吆喝叫好的声音不断传来。右边还有个卖
唱的姑娘，歌声委婉动听，听词义大概是歌颂天下太平的，旁边拉二胡的
老者一边拉，一边不住地摇头叹气。
LONG);

  set("exits", ([ 
	  "north":__DIR__"beidajie1",
  "southwest":__DIR__"xidajie1",
  "southeast":__DIR__"nandajie1",
  "east":__DIR__"dongdajie1",
     ]));
set("objects",([
	__DIR__"npc/yiren":1,
	]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

