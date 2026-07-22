// by mayue

inherit ROOM;

void create()
{
	set("short", "卧龙岗上");
	set("long", @LONG
山顶有一大片开阔地，蓝蓝的天上飘着几朵白云，脚下是绿
油油的草地，浅浅的刚好可以盖过脚面,散发着一种诱人的芳香
舒服的人直想躺在上面打滚。前面有几间简陋的竹舍。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
		"south" : __DIR__"zhushe",
//		"west" : __DIR__"wumiao",
		"northdown" : __DIR__"shanlu3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

