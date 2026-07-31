// 萧府大门 damen.c
// zly 99.6.21

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        object con, item;
       set("short",MAG"萧府大门"NOR);
       set("long", @LONG
这里是晋阳大侠萧半和所住的萧府的大门，红漆包门的正上方有一
块金字黑底的长匾，上书“萧府”两个大字，门口两侧分立两个大石狮
，甚是威武。北面是萧府的大厅，南面是。
LONG);    
        set("exits", ([
            "north" : __DIR__"dating",
                "southeast" : "/d/huanghe/huanghe7",
        ]));    
        set("no_fight", 1);

        set("objects",([
            __DIR__"obj/flower" : 1,
            __DIR__"npc/zhang" : 1,
            __DIR__"obj/pin" : 1,
        ]));         
        setup();        
        con = present("flower", this_object());
        item= present("jin chai", this_object());
        item->move(con);
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("yyd_jinchai") && dir == "north" )
        return notify_fail("你怎么一点规矩也不懂！\n");
        return ::valid_leave(me, dir);
}
