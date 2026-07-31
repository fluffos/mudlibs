// Room: /d/songshan/songyueta.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "嵩岳寺");
	set("long", @LONG
这里原是北魏离宫。孝明帝舍为佛院，至隋方有今名，寺围阔
大，僧舍连云。院内风动旌扬，松摇竹乱，别有一般清静。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

