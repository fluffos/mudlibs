// Room: /hangzhou/damo3.c
// hubo 2008/4/19

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"大漠"NOR);
        set("long", YEL@LONG
一片大漠黄沙，一走进来感觉迷失了方向。
LONG
NOR);
        set("outdoors", "hangzhou");
        set("exits", ([
                "north" : __DIR__"damo2",
                "south" : __DIR__"damo4",
                "east" : __DIR__"damo3",
                "west" : __DIR__"damo2",   
]));
          
   setup();
}

void init()
{

        object ob, room;
        object *ob1;
        int i;
        ob = this_player();
        room = this_object();

        if ( !living(ob) ) return;
        //whuan 加入判断，防止无限刷wolf
        ob1 = all_inventory( environment( ob ));        
        for(i=0; i<sizeof(ob1); i++)
        {
        if( ob1[i]->query("id") == "wolf" ) return;
        }                
        if (random(3) == 1)
                 {
            message_vision(HIR "一条恶狼猛的向$N扑了过来，你被吓得呆住了！\n" NOR, ob);
            ob->start_busy(5);
            remove_call_out("wolf");
            call_out("wolf", 1, ob);
            return;
           }
        else
                 return;
}

void wolf(object me)
{
        object wolf;
        wolf = new("/d/hangzhou/npc/wolf");
        wolf->move(environment(me));
        return;
}

