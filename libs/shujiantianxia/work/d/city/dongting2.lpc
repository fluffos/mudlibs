//Yanqi 08/11/2k

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"盐局东厅"NOR);
	set("long", @LONG
这里是扬州盐局的东厅，四周装饰的非常简单，盐商们都在这里商讨一些
事情，是盐商们聚会的场所。中间正座着一个盐商，他就是这里的盐商头子。
LONG
        );
	set("indoors", "扬州");
    set("no_fight",1);
    set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"yanju",
	]));
	set("objects", ([
		__DIR__"npc/yanshang2" : 1,
	]));
	
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("incity",1);
	setup();

}
