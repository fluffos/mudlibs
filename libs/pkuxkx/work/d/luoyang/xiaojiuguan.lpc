//xiaojiuguan.c -- 小酒馆
//Zone: 万安寺
//Created by ddid
//2009-6-20

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"小酒馆"NOR);
  set("long", @LONG
这是一家小酒馆，看来平时生意就很清淡，这个时间，更是没什么客
人，一个小酒保懒懒地趴在柜台后面，打着瞌睡。店内倒也干净，就是光
线不太好，老板为每个桌子添了一盏油灯，幽幽的灯光下，闻着淡淡的酒
香，一种游子之情黯然而生。

LONG
  );

  set("exits", ([     
      "north" : __DIR__"hutong5",   
  ]));

	set("objects", ([
		__DIR__"npc/fanyao" : 1,
	]));

  setup();
  replace_program(ROOM);  
}
