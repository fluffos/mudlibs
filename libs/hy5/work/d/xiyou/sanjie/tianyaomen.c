// sanjie tianyaomen.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天妖宫门");
  set ("long", @LONG
	
			＃＃＃＃＃
			＃天妖宫＃
			＃＃＃＃＃

一坐妖气冲天的宫殿，虽然没有魁丽堂皇的大殿，但里妖雾
弥漫，门上写着大大的三个字——〖天妖宫〗
LONG);

  set("exits", ([
  "north" : __DIR__"tianyaolang1",
  "south" : __DIR__"tianyaolu9",
]));
  set("outdoors", 1);

  setup();
}
