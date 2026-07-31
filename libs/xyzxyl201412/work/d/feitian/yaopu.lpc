// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。一个漂亮的医师正忙碌的给病人看病在柜台前还贴着
一张广告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店现急需人手，如要帮工的可以向阿惠打听工作。\n",
	]));
	set("objects", ([
		__DIR__"npc/gaohehui" : 1,
		__DIR__"npc/baixing" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"jiedao1",
		]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

