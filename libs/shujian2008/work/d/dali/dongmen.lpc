// Room: //dali/dongmen.c
// bbb 1997/06/11 
// Modify By River 98/12
inherit ROOM;


void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着几张官
府告示。官兵们警惕地注视着过往行人，你最好小心为妙。一条笔直的青石板
大道向东西两边延伸。东边是郊外，隐约可见一片一望无际的树林，神秘莫测。
西边是城里。
LONG
	);
	set("outdoors", "大理"),

	set("exits", ([
		"east" : __DIR__"dalieast/shanlu7",
		"west" : __DIR__"dongjie4",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}
