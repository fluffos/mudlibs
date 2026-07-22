// xilang.c 西厢走廊
// by shang 97/6

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
你走在一条走廊上，西边有一间药房，再往东是一间炼丹房, 北面是练功
房。这儿是武当禁地, 非常安静, 有一武当弟子看守着。
LONG
        );

        set("exits", ([
                "west" : __DIR__"zoulang3",
                "east" : __DIR__"zoulang2",
                "north" : __DIR__"lgfang",
                "south" : __DIR__"sanqing",

        ]));

        set("objects", ([
                CLASS_D("wudang")+ "/xi" : 1
        ]));
 
        setup();
} 

int valid_leave(object me, string dir)
{
	object obj;
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "武当派")
         && dir != "south"
         && objectp( obj = present("zhang songxi", environment(me)))
         && living(obj))    
          return notify_fail(CYN"张松溪喝道：武当重地，外人不得入内。\n"NOR);
               
        return ::valid_leave(me, dir);
}
