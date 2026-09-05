//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "水匪营寨");
        set("long", @LONG
这里是太湖水贼的营寨。
LONG
        );

        set("no_task",1);

        set("outdoors", "suzhou");
        setup();
        
}

void init()
{
    object shanzei;
    object me=this_player();
    if (me->query_temp("songtasks/shuishi/task")==1 &&!me->query_temp("songtasks/shuishi/scaolian_degree"))
    {
        shanzei=new("/d/song/npc/shuizei");
        shanzei->set("owner",me->query("id"));
        shanzei->move(this_object());
        message_vision("一队水贼迎了出来。\n",me);
    }
    return;
}