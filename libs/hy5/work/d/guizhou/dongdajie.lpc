inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是贵阳城内东西的的主干线。形形色色的叫卖声在耳边此起彼伏，
连绵不绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。
LONG );

	set("exits", ([
                         "west"      : __DIR__"center",
                         "east"      : __DIR__"dongmen",
		
	]));
        set("objects",([
           __DIR__"npc/xiaojie":1,
           
           ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



