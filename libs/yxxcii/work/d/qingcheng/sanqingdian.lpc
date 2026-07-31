//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long", @LONG
古常道观的中心是三清殿。殿中供奉三清教主：玉清原始天尊、上清
灵宝天尊和太清太上老君。原始天尊手拿圆珠，象征洪元；灵宝天尊怀抱
太极图，象征混元；太上老君手持扇子，象征太初。殿旁有一对联(lian)，
著墨极浓。
LONG
);
	set("exits", ([
		"south"	: __DIR__"tianshidong",
	]));
	set("item_desc", ([
		"lian"	: @TEXT

	 一	  地
	 生	  法
	 二	  天
	 二	  天
	 生	  法
	 三	  道
	 三	  道
	 生	  法
	 万	  自
	 物	  然
TEXT
	]));

	setup();
	replace_program(ROOM);
}

