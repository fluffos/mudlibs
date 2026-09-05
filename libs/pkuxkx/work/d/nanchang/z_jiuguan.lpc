
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
这里是一家小酒馆，老板是宁王之乱避祸至此的汉人。既有本地极受欢迎的
烧酒也有很多汉人的吃食，因为价格低廉，极受欢迎。
LONG
	);
	set("exits", ([ 		
        "northeast" : __DIR__"z_guangchang",
        
		
    ]));
    set("objects", ([
		__DIR__"npc/laoban": 1,
        
        ]));
	set("no_task",1);
	setup();
	
}


