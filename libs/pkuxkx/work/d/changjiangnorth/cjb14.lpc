//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江北岸，远远向南望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjb15",
             "southeast" : __DIR__"dkb3",
        ]));
       

        set("couldfish",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");

        setup();
}


int rebuild()
{
    this_object()->set("exits/west", __DIR__"cjb15");
}

int valid_leave(object me,string dir)
{  
    
	if (dir=="west" && random(300)>289)
    {
        this_object()->delete("exits/west");
        call_out("rebuild",60);
        return notify_fail("你刚要前行，忽然发现江水决堤，不由暗自庆幸，还好没过去。\n");
    }
	return ::valid_leave(me, dir);
}

