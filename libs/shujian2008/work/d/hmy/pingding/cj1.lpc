// cj1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "长街");
        set("long", @LONG
这是平定州内的一条长街，路上人来人往，热闹非凡。因为此地和日月教
总坛黑木崖相去不远，所以城中有颇多教众来往。东边是平定州郊外。
LONG
        );
        set("exits", ([ 
          "west" : __DIR__"gate1",
          "east" : __DIR__"cj2",
	]));
	set("objects",([
		__DIR__"npc/jiaozhong" : 2,
	]));
        set("outdoors", "平定州");
        setup();
}
