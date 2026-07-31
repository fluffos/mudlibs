// Room: /d/tianshui/school.c

inherit ROOM;

void create()
{
	set("short", "小镇学堂");
	set("long", @LONG
学堂非常简陋，桌椅也已经破旧，但打扫得很干净。一位教
书先生正站在前面摇头晃脑地带着学生们念书。迎面墙上挂着一
幅山水画，旁边是一幅草书。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wroad1",
]));

	set("objects",([
	__DIR__"npc/teacher" : 1,
]));
	setup();
}

int valid_leave(object ob,string dir)
{
	if(ob->query_temp("school/李侍尧"))
		ob->delete_temp("school/李侍尧");
	return ::valid_leave(ob,dir);
}