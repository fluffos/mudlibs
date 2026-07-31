// Room: /d/yandang/yuanluo.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "院落");
  set ("long", @LONG
这里是芙蓉客栈的院子,中间是一条青砖路,路两边是两个花圃,栽
着几株梅花,北面靠着院墙是一条明廊,向两边分别延伸出去,就是店中
的客房了,男左女右,可别搞错了.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sunerniang.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"kezhan",
  "north" : __DIR__"nvkefang",
  "south" : __DIR__"nankefang",
]));
  set("outdoors", "/d/yandang");

  setup();
}
int valid_leave(object me,string dir)
{
	object npc;

	npc=present("sun erniang",this_object());
	if(dir=="out")	{
		if( me->query_temp("rent_paid"))	me->delete_temp("rent_paid");
		return ::valid_leave(me,dir);
	}	

	if((me->query("gender")=="男性"&&dir=="north")||(me->query("gender")=="女性"&&dir=="south")) {
	return notify_fail("看清楚方向！！\n");
	}
	if (!me->query("rend_paid") && objectp(npc))  {
	return notify_fail("孙二娘道：想住店先给老娘二两白银！自已弟兄嘛就减半吧。\n"); 
	}
	return ::valid_leave(me,dir);
}

