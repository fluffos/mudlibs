// by binlang
//shamo6
#include <room.h>
inherit ROOM;
void create()
{
        set("short","大沙漠");
        set("long", @LONG
这是一片一望无际的大沙漠，连着明教和中原，
你一进来就迷失了方向，赶快离开吧。
LONG
        );
        set("exits", ([
                "south" :__DIR__"shamo4",
                "north" :__DIR__"shamo5",
                "east"  :__FILE__,
                "west"  :__FILE__,
        ]));
        set("outdoors", "mingjiao");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west")
                me->add_temp("mark/steps",1);
        if ( dir == "east")
                me->add_temp("mark/steps",-1);
        if (me->query_temp("mark/steps") >= 3)
        {
                set("exits/" + dir, __DIR__"shamo7");
                me->delete_temp("mark/steps");
                tell_object(me, "你累得半死，终於走出了沙漠。\n");
                remove_call_out("restore_exits");
                call_out("restore_exits", 1, dir);
                return 1;
        }
        if (me->query_temp("mark/steps") <= -3)
        {
                set("exits/" + dir, __DIR__"shamo1");
                me->delete_temp("mark/steps");
                tell_object(me, "你累得半死，还是走不出沙漠。\n");
                remove_call_out("restore_exits");
                call_out("restore_exits", 1, dir);
                return 1;
        }
        return ::valid_leave(me,dir);
}

void restore_exits(string arg)
{
        this_object()->set("exits", ([
                "south" :__DIR__"shamo4",
                "north" :__DIR__"shamo5",
                "east"  :__FILE__,
                "west"  :__FILE__,
        ]));
}
