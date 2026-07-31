//nezhamiao.c  by meteor 2003/8/16
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short","哪吒行宫");
        set("long", @LONG
哪吒行宫中香火鼎盛，当中一座八尺哪吒像(xiang) 三首八臂法
身，分别持火尖枪，乾坤圈，混天绫，九龙神火罩，阴阳剑，威风凛
凛。旁边分别塑着一个跪着的小鬼，双手托盘(pan) ，高举过头，里
面放着来参拜祈福的善男信女们捐出的银钱。正中一个锦缎缝制的蒲
团(putuan)虽然很旧，但依然干净。
LONG );
        set("exits",([
                "west" : __DIR__"ruzhou",
        ]));
        set("item_desc", ([
                "xiang"  : "威武的哪吒立像，背后还有一朵很大的莲花衬托，但是你觉得很奇怪
的是，哪吒的风火轮并没有在塑像的脚下。你在想是不是应该到处找
找(find)。\n",
                "pan"    : "盘中散落着一些银钱，你大概算了一下，也有几十两银子。\n",
                "putuan" : "一个锦缎缝制的蒲团，中间有少许凹陷，看来是经常有人在这里跪拜(kneel)。\n"
        ]));
         set("lun",1); 
        setup();
}

void init()
{
        add_action("do_put","put");
        add_action("do_find", "find");
        add_action("do_kneel", "kneel");
}

int do_put(string arg)
{
       object me, ob, dest;
       me = this_player();

       if( !arg || arg=="" ) return 0;
        if( arg != "1 gold" )
                return notify_fail("你的心意不诚，还是算了吧。\n");
        dest = present("gold", me);
        if( !dest )
                return notify_fail("你要放什么？\n");
        if(dest->query_amount() == 1)
                destruct(dest);
        else
                dest->set_amount((int)dest->query_amount() - 1);
        message_vision(HIW"$N从身上拿出一两"HIY"黄金"HIW"，恭恭敬敬地放在小鬼手上的托盘里。"NOR" \n", me);

        me->add_temp("fenghuolun", 1);
        return 1;
}

int do_find(string arg)
{
        object me;
       me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg != "xiang" )
                return notify_fail("你要找什么？\n");
        message_vision(HIW"$N在哪吒像的四周绕了一圈，却什么也没发现。"NOR" \n", me);
        me->add_temp("fenghuolun", 1);
        return 1;
}

int do_kneel()
{
        object me, lun;
       me = this_player();
        message_vision(HIW"$N在蒲团上跪了下来，恭恭敬敬地磕了几个头。"NOR" \n", me);
        if (me->query_temp("fenghuolun") >= 2 && query("lun") == 1 && random(3) == 1)
        {
                message_vision(HIG"$N在跪下去的时候，突然见到供桌下金光一闪，$N乘着没人注意，赶快拿出来放入怀中。"NOR" \n", me);
                lun = new(__DIR__"obj/fenghuo-lun");
                lun->move(me, 1);
              delete("lun");
              me->delete_temp("fenghuolun");
        }
        return 1;
}

