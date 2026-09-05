
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
		"northwest" : __DIR__"hubian2",
		"east" : __DIR__"road4",
        "west" : __DIR__"matou",
		//"south" : "/d/murong/hubian1",
        //"west" : __DIR__"hubian1",
	]));
	/*set("objects",([
		"/d/murong/npc/guo" : 1,
		"/d/murong/npc/cui" : 1,
		]));*/
    set("couldfish",1);
	set("outdoors", "suzhou");
	setup();

}

