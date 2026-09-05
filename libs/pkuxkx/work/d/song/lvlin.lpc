//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "深山");
        set("long", @LONG
这里是一座不知名的深山，常有山贼出没。
LONG
        );

        set("exits", ([
               
               "north" : "/d/hangzhou/shanlu4",
        ]));

        set("outdoors", "hangzhou");
		set("at_hangzhou",1);
        setup();
        
}

void init()
{
    object shanzei;
    object me=this_player();
    if (me->query_temp("songtasks/longwei/task")==1&&!me->query_temp("songtasks/longwei/lcaolian_degree"))
    {
        shanzei=new(__DIR__"npc/shanzei");
        shanzei->set("owner",me->query("id"));
        shanzei->move(this_object());
        message_vision("一队山贼走了出来。\n",me);
    }
    return;
}