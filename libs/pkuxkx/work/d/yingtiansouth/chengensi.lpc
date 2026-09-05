//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"承恩寺"NOR);
        set("long", "这个寺庙名叫承恩寺，远近闻名，听说这里很灵验的。捐款(juan)后可以求\n签(qiuqian)算命。\n"

        );
        set("exits", ([
                
                
                "west" : __DIR__"s_street1",
                
                
        ]));
        set("objects", ([
                "/d/yingtiannorth/npc/miaozhu" : 1,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{ 
	add_action("do_juan","juan"); 
	add_action("do_qiuqian","qiuqian"); 
}

int do_juan()
{
    object who=this_player();
    int amount=10000;
    if (MONEY_D->player_pay(who,amount))
    {
        message_vision("庙祝收下$N捐献的善金。\n",who);
        who->set_temp("承恩寺",1);
        return 1;
    }
    else
    {
        tell_object(who,"你身上似乎也没有什么值钱的东西了。\n");
        return 1;
    }
}

int do_qiuqian()
{
    object me=this_player();
    int rp = (int)me->query_temp("apply/magic");
    if (!me->query_temp("承恩寺"))
    {
        return notify_fail("你没有捐款，不能求签！\n");
    }
    else
    {
        me->delete_temp("承恩寺");
        if (rp<100)
        {
            message_vision("$N求到了一只下下签，烂无可烂。\n",me);
            return 1;
        }
        if (rp<200)
        {
            message_vision("$N求到了一只下签，九死一生。\n",me);
            return 1;
        }
        if (rp<400)
        {
            message_vision("$N求到了一只中下签，烂泥扶不上墙。\n",me);
            return 1;
        }
        if (rp<700)
        {
            message_vision("$N求到了一只中签，平平无奇。\n",me);
            return 1;
        }
        if (rp<1100)
        {
            message_vision("$N求到了一只中上签，乏善可陈。\n",me);
            return 1;
        }
        if (rp<1600)
        {
            message_vision("$N求到了一只上签，红光满面。\n",me);
            return 1;
        }
        if (rp<2200)
        {
            message_vision("$N求到了一只上上签，大富大贵。\n",me);
            return 1;
        }
        else
        {
            message_vision("$N求到了一只极品上上签，贵不可言。\n",me);
            return 1;
        }
        
    }
}