//yanyitang.c -- 燕怡堂
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"燕怡堂"NOR);
  set("long", @LONG
这里是个四合院，四面都有房间，几个年轻貌美个姑娘不时穿梭往来
。院子中央，一个年级稍大的师傅，正带着三个徒弟练习舞蹈，旁边的房
间里传来阵阵丝竹之声。本来，以王爷的身份，家里豢养个把伶人，也算
不得什么大事，但这里的人似乎多了一些。
LONG
  );

  set("exits", ([     
      "east" : __DIR__"huilang",
      "west" : __DIR__"houhuayuan",
  ]));

  
 set("objects", ([
		__DIR__"npc/mm1" : random(4) + 2,
		__DIR__"npc/mm2" : random(4) + 1,
		__DIR__"npc/mm3" : random(4) + 1,
		__DIR__"npc/mm4" : 1,
	]));
	
	set("no_clean_up", 0);
  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);  
}

/*
void init() 
{ 
object here = this_object();
}
*/
