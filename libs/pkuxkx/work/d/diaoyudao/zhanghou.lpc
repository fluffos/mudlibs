// Room: /d/diaoyudao/zhanghou.c 帐后
// hongdou 98.09.20

inherit ROOM;

void create()
{
	object me;
	string zhang;
	me=this_player();
	zhang="hzhang";

	set("short", "帐后");
	set("long", @LONG
这里是主帅大帐的后面，旁边全是大大小小荒废的营帐，帐篷
经过长期的风吹日晒，大部分已经残破不堪。这么多的营帐，看来
当年韦小宝驻扎在此岛的士兵人数实在不少。你从这里可以随便进
入各个营帐。
LONG
);
	if (me->query_temp("marks/问")) zhang="hzhang1";
	set("exits", ([
		  "enter": __DIR__+zhang,
	          "southeast" : __DIR__"zhangout",

	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

