// Room: /d/yeyangzai/nroad.c

inherit ROOM;

void create()
{
	set("short","荒效小路");
	set("long", @LONG
四周一遍荒抚，看不见什么人。听说这条南下北上的必经之路不怎么太
平，还是小心为妙。南面则是南下之路，西面杂草丛生，似乎也是南下
之路，但不知为何少有人迹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caocong",
  "south" : __DIR__"huangye",
]));
	set("outdoors","野羊寨");

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="south") me->set_temp("where_to","south");
	return ::valid_leave(me,dir);
}
