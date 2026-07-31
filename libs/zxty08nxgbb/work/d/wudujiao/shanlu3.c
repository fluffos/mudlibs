// by mayue

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
这是一条上山的小路，脚下是青石砌成的台阶，湿漉漉的长
满了青苔，四周全是茂密的竹林。前面似乎就快到小山顶上了。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
		"southup" : __DIR__"caoping",
//		"west" : __DIR__"wumiao",
		"northdown" : __DIR__"shanlu2",
	]));
        set("objects", ([
                __DIR__"npc/qiaofu": 2,
	]));

	setup();
	replace_program(ROOM);
}

