//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "天然图画");
	set("long", @LONG
这里岩壁矗立，绿树映辉，牌阁在山垭间巍然屹立。四顾峰奇石异，
云雾缥缈，远近观赏，如在画中。阁左“天生桥”，一石丈余飞插石壁之
间，十分险峻。
LONG
);
	set("exits", ([
		"eastdown" : __DIR__"path1",
		"westup"   : __DIR__"path2",
		"north"	: __DIR__"zhuhezhuang",
	]));

	setup();
	replace_program(ROOM);
}

