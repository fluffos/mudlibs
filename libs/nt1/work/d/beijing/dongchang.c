inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", RED "东厂" NOR);
	set("long", @LONG
这里就是京城的特务机构——东厂。大厅内很是宽阔，这里警备深严，
穿着制服的东厂官兵和太监在这里来回走动。看来这里不宜久留，赶快离
开为妙。
LONG );
	set("exits", ([
		"north" : __DIR__"dongchang_men",
	]));
	set("objects", ([
		__DIR__"npc/bing2" : 4,
		__DIR__"npc/taijian" : 1,
	]));
	set("no_fight", 0);
	setup();
}
