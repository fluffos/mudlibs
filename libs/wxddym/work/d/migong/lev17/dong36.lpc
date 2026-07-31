
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
                "west" : __DIR__"dong3"+(random(4)+5),
		"east" : __DIR__"dong3"+(random(4)+5),
		"south" : __DIR__"dong37",
                "north" : __DIR__"dong35",
	]));
if (random(2)==0)
	set("exits", ([
"south" : __DIR__"dong37",
                "west" : __DIR__"dong3"+(random(4)+4),
		"east" : __DIR__"dong3"+(random(4)+5),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

