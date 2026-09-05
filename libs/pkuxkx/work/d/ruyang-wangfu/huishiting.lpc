//huishiting.c -- 回事厅
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"回事厅"NOR);
  set("long", @LONG
这里是王府的回事厅，有专人随时在这里候命，登门拜访的，需要由
专人入内向王爷禀告，只有获得了王爷的准许，才能进去觐见。一般人想
见汝阳王可没那么容易。公文往来，则有人指引着去执事处。若是家事，
则带去东院，由内宅的人再行接引。往日这里总是一片繁忙景象，但今天
却不太一样，只有一个人一声不吭地站在堂内。

LONG
  );
 
  set("exits", ([     
      "south" : __DIR__"mengang",   
      "north" : __DIR__"yishiting", 
      "east" : __DIR__"zoulang-e1",
      "west" : __DIR__"zoulang-w1",
  ]));

	set("objects", ([
		__DIR__"npc/zongguan_qianyuan" : 1,
	]));

  setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("zong guan", environment(me))) && dir == "north")
		return notify_fail("总管太监一把拦住了你：“要见王爷也要由我通禀啊～！况且王爷现在正在议事，不见客，您呐～，还是请回吧～～”\n\n");
	return ::valid_leave(me, dir);
}
