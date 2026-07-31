//Room: /d/foshan/northgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","北门");
	set("long",@LONG
这里是佛山镇的北门。出北门向北，翻过南岭可达中原。南面
一条东西向的大街是佛山镇的主要街道。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street3",
	    "north"  : __DIR__"nanling",
	]));
	setup();
}

