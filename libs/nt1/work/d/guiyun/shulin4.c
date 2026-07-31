// Room: /guiyun/shulin4.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密
的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的
啸声使人不觉犹豫了前进的脚步。
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shanlu1",
		"west"  : __DIR__"shulin3",
	]));
	set("objects", ([
		__DIR__"npc/dabei" : 1,
	]));
	setup();
	replace_program(ROOM);
}
