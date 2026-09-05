//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "juedi.h"
void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江南岸，远远向北望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjn15",
             "southeast" : __DIR__"dkn3",
        ]));
       

        set("couldfish",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
		set("juedi_dir","west");
		set("juedi_connect",__DIR__"cjn15");
        setup();
}

