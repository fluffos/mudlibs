
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"水上之馆"NOR);
	set("long", BLU @LONG
    你正走在海堤上，海堤往南、北方向延申。海堤旁种满一排排的防风林，枝干
不硬，细细软软的，像木麻黄一类的植物。东边是一片汪洋的大海，海浪不停地拍
打著坡堤。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong4"+(random(9)+1),
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong48",
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/lev7" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

