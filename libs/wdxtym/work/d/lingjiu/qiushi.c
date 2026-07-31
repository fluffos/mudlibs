// ROOM qiushi.c

inherit ROOM;
void create()
{
	set("short", "囚室");
	set("long",@LONG
这是『灵鹫宫』关押犯人的地方，屋中光线昏暗，气味难闻。
LONG );
	set("exits", ([
		"east" : __DIR__"men1",
	]));

	setup();
}
