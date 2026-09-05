
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "太湖湖边");
	set("long", @LONG
这里是太湖的湖边，波光粼粼。傍晚时分，不少渔家已升起炊烟。
LONG );

    set("no_task",1);
	set("exits", ([
		"northeast" : "/d/guiyunzhuang/caodi",
		"southeast" : __DIR__"hubian1",
        
		
	]));
	set("objects",([
		"/d/song/npc/jietou" : 1,
		
		]));
    set("couldfish",1);
	set("outdoors", "suzhou");
	setup();

}

