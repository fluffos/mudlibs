//Room:/d/lingshedao/migong1.c
inherit ROOM;
#include <ansi.h>
void create()
{ 
        set("short", "山腰");
        set("long",@LONG
山路到了这里,好象没有了出口,四处都是荆棘和大树,你不
由一阵慌乱.向北,向北.似乎只有这样,你才能重新找到出路.
LONG );
        set("outdoors", "lingshedao");
        set("exits", ([
                "east" :  __FILE__,
                "west" :  __FILE__,
                "southdown" : __FILE__,
                "northup" : __FILE__,
        ]));             
        set("no_clean_up", 0);
        setup();
}


void init()
{
    object ob=this_player();
    ob->receive_damage("qi", 25);
    ob->receive_wound("qi",  25);
    message_vision(HIR"$N脚下一痛,不禁大叫起来.原来地上竟然布满了七八寸长的钢针\n"NOR,ob);
}

int valid_leave(object me, string dir)
{
        int total_steps,total_steps2;
        total_steps = 30;
        total_steps2 = -30;
        if ( dir == "northup")
            me->add_temp("lsmigong/steps",1); 
        if ( dir == "southdown")
            me->add_temp("lsmigong/steps",-1);
        if (me->query_temp("lsmigong/steps") >= total_steps )
        {  
            me->move(__DIR__"xiaowuout");   
            me->delete_temp("lsmigong/steps");
            return notify_fail("你咬紧牙关，终于发现一条小径,走了出来。\n");
             }
        if (me->query_temp("lsmigong/steps") <= 0 )
        {  
            me->move(__DIR__"shanyao");   
            me->delete_temp("lsmigong/steps");
            return notify_fail("你咬紧牙关，终于发现一条小径,走了出来。\n");
             }

        return ::valid_leave(me,dir);
}
