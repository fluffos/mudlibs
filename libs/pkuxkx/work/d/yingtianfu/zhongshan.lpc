//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "钟山");
        set("long", @LONG
这里是一座高山，位于应天府、苏州和镇江交界之地。近年已被山贼占据。
LONG
        );

        set("exits", ([
               
               "southdown" : __DIR__"tulue2",
        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}

void init()
{
    object shanzei;
    object me=this_player();
    if (me->query_temp("mingtasks/dudufu/task")==1&&!me->query_temp("mingtasks/dudufu/lcaolian_degree"))
    {
        shanzei=new(__DIR__"neicheng/npc/shanzei");
        shanzei->set("owner",me->query("id"));
        shanzei->move(this_object());
        message_vision("一队山贼走了出来。\n",me);
    }
    return;
}