#include <localtime.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW+"浅滩"+NOR);
	set("long", @LONG
这里是鄱阳湖边的一处浅滩，极目远眺，浩瀚的鄱阳湖一望无际。天气晴朗
时却是一览无余，远处有小舟顺流漂下。
LONG );
	set("outdoors", "jiangzhou");
   
/*    set("item_desc", ([
		"lake" : "碧波荡漾的湖面，谁还能想起这里曾是本朝太祖和陈友谅大战的主战场？\n", 
        "boat" : "一只小舟，被系在岸边的大青石上，如果得到主人允许，也许你可以上舟(shang)一晤。\n",
        "岩缝" : "巨岩有一处裂缝，似乎可以伸手进去摸索一下。\n", 
        "tree" : (:look_tree:),
        "ju" : "悟、根、身、臂，从零开始，周而复始。\n",
	]));*/

    set("no_task",1);
  set("no_fight", 1);
  set("no_perform", 1);
  set("no_steal", 1);
  set("no_sleep_room", 1);

	set("exits", ([
		"west"     : __DIR__"hubian",
		
	]));
    set("couldfish",1);
    /*set("objects", ([
        "/d/jiangzhou/npc/diaoyuren" : 1,
        "/d/jiangzhou/obj/rock" : 1,
        ]));
	*/
    setup();
	
}

