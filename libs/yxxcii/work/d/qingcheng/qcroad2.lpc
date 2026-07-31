//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "青泥小道");
	set("long", @LONG
你走在青泥小道上。左边不远传来阵阵水响，原来那里就是天下知名
都江堰。拦河分流，使岷江之水分注到无数小小溪流中，才免了连年的水
祸，灌溉出了这富饶的成都平原。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"north" : __DIR__"qcroad3",
		"east"  : __DIR__"qcroad1",
	]));

	setup();
	replace_program(ROOM);
}

