//path

#include <ansi.h>
#include "/doc/help.h"

inherit ROOM;

void create()
{
        
        
        set("short", "秘道");
        set("long",@LONG
    这里黑凄凄的，墙壁上挂着一盏油灯，发着昏黄的微光，周围有八个洞，
能感到隐隐杀气从中传出，你不由得打了个冷战。
LONG
                );
        set("exits", ([    
              "east" : __DIR__"path2",
         "southeast" : __DIR__"path2",
             "south" : __DIR__"path2",
         "southwest" : __DIR__"path3",
              "west" : __DIR__"path2",
         "northwest" : __DIR__"path2",
             "north" : __DIR__"path2",
         "northeast" : __DIR__"path2",
	]));

        set("no_task",1);
        setup();

	
}
