// qjc 2000/5/3 

inherit ROOM;

void create()
{
     set("short", "天星堂大堂");
     set("long", "这里是啸天会天星堂大堂，正中墙上写着一个“雨”字。
不少冷堂弟子正在进进出出忙碌着，江湖中很多人士也慕名而
来。冷月堂堂主经常在这里招待四方来客，公论天下大事。这
里向西就是冷月堂大厅了，北面是新手救济处，南面则是新手
支援处。\n");

	set("exits", ([
                "north" : __DIR__"xs1",
		"south" : __DIR__"xs2",
                "east" : __DIR__"yt1",
                "northwest" : __DIR__"sclk",

	]));
	setup();
	replace_program(ROOM);
}

