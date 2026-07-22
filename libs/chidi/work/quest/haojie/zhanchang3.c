//by mudgod@xssx
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIR"血池阵"NOR);
        set("long", @LONG
这是皇皇教进攻的路线，周围布满了埋伏和皇皇教众，四
周萧杀的气氛让你感到不寒而颤。面对着一群群的敌众，你不
觉的产生了不是敌死，就是我亡的想法。誓要平息这次武林浩
劫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"zhanchang1",
]));
                set("objects", ([
                "/quest/haojie/npc/man" : 9,
           ]));

        set("outdoors","zhanchang");
        setup();
}

void init()
{
    
    add_action("do_giveup", ({"taopao"}) );
  
}

int do_giveup()
{
        object room;
        object me;
        me = this_player();
        if (! room=find_object("/d/bianliang/guangchang"))
             room=load_object("/d/bianliang/guangchang");
        message_vision(HIR"$N面对皇皇教的大批进攻，胆颤心寒，施展平生最快的身法逃之夭夭。\n"NOR,this_player());
        me->move(room);
        me->set_temp("marks/逃",1);
        return 1;
}


