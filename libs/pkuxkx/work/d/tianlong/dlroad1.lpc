// /d/dalicheng/dlroad1.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "羊肠小路");
	set("long", @LONG
这是一条小路, 西南方通向大理段氏, 北面通向成都城。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
          "north" : "/d/chengdu/guandaosw2",
//		  "northeast" : "/d/wudang/wdroad6",  //大理由成都或昆明进入。
		  "southwest" : __DIR__"dlroad2",
		]));
    
        setup();
        
}

