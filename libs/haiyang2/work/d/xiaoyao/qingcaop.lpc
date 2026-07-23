// qingcaop.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "青草坪");
        set("long", @LONG
这里是树林中的一片比较大的空地，名曰：青草坪。因为处于密林之中
所以这里平时很少有人来，但是不知道为什么，这里却经常有人迹出现。你
看，又一个来了。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	set("outdoors", "xiaoyao");
	set("objects", ([
		"quest/menpaijob/xiaoyao/suxingh": 1,
		"/d/biwu/champion_xy": 1,
		__DIR__"npc/xiaoyaozi": 1,
    "quest/menpai/xiaoyao/shi" : 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}
