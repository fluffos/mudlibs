//zhishichu.c -- 执事处
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"执事处"NOR);
  set("long", @LONG
这里是汝阳王府的执事处，平日王府的公文往来、日常政务，都要由
这里的执事先行处理后，再转交王爷裁夺。这里并排摆着四张桌子，每张
桌子上都放着不少纸张、文册，一名王府的执事正趴在其中一张桌子上飞
快地写着什么。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"xiaojiaochang",   
      "north" : __DIR__"yibinguan", 
      "east" : __DIR__"zoulang-w1",
  ]));

	set("objects", ([
		__DIR__"npc/zhishi" : 1,
	]));

  setup();
  replace_program(ROOM);
}
