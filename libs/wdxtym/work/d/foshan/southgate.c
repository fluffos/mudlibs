//Room: /d/foshan/southgate.c
inherit ROOM;
void create()
{
	set("short","南门");
	set("long",@LONG
这里是佛山镇的南门。出南门向南，就到达南海之滨了。北面
一条东西向的大街是佛山镇的主要街道。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street3",
	    "south"  : "/d/xiakedao/xkroad3",
	]));
	setup();
}

