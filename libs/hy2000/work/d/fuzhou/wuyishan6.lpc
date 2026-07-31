// Room: /d/fuzhou/wuyishan6.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "大王峰");
	set("long", @LONG
大王峰又称纱帽峰，山形如宦者纱帽，独具王仪而得名。四
周悬崖壁立，上丰下敛，气势雄浑。远远望去，宛若擎天巨柱，
与玉女遥遥相望。石壁上刻有“居高思危”四字。
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuyishan2",
	]));
	set("objects", ([
		"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 

//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

