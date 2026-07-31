//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "上清宫");
	set("long", @LONG
上清宫是老君道场。宫前山门，矮树搭就，甚为灵动。宫内殿堂古色
清雅，正殿供奉太上老君、吕纯阳和张三丰塑像。山前摩崖石刻“天下第
五名山”气势浑厚，很是壮观。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"westdown" : __DIR__"sanwanjiudao",
		"westup"   : __DIR__"huyingting",
		"west"	 : __DIR__"yuanyangjing",
		"east"	 : __DIR__"maguchi",
		"south"	: __DIR__"songfengguan",
	]));
	setup();
	replace_program(ROOM);
}

