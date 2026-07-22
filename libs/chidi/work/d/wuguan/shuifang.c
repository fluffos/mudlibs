//shuifang.c
// Modify By River@SJ

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"水房"NOR);
        set("long", @LONG
一进屋，你看见屋内放着几口大缸（gang），好象是装水用的，不过缸似
乎都是空的。一群武馆的弟子正在忙碌的挑着水，水房管事在一边吆喝着，督
促众人不要偷懒。
LONG
        );
        
	set("item_desc",([
               "gang" :"一口水缸，但里面空荡荡的一滴水也没有。\n",
	]));

        set("exits", ([
               "west" : __DIR__"shilu2",               
        ]));

        set("no_fight",1);
        
        set("objects", ([
            __DIR__"npc/guanjia4" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_tiao", "tiao");
        add_action("do_tiao", "挑");       
}

int do_tiao(string arg)
{
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("job_name") != "挑水") 
            return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");
        if (me->is_busy())
            return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting())
            return notify_fail("你正在战斗中,无法专心干活!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "shui tong")         
            return notify_fail("你想用什么来挑水，用手吗？\n");
        if ( !arg || arg != "水" )
            return notify_fail("你要挑什么？\n");
        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);
        if((int)me->query("jingli") < costj 
         ||(int)me->query("qi") < costq){
          message_vision(HIR"$N手一抖，不小心水桶砸在自己身上。\n"NOR,me);
          me->unconcious();
          return 1;
        }        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);
        if(((int)me->query_temp("mark/挑") > 15 + random(5))
         &&(present("shuifang guanshi", environment(me)))){
           me->set_temp("mark/完了", 1);
           write(RED"水房管事说：干的不错，好了，你可以到大师兄鲁坤那里去覆命(task ok)了！\n"NOR);
           return 1;
        }
        write("你慢慢将水桶中的水蓄满，然后倒入水缸中。\n");
        me->start_busy(1);
        me->add_temp("mark/挑", 1);
        if((int)me->query_skill("parry", 1) < 20 
         && random(10)>6 ){
          write(HIM"你在挑水中对于招架的用法有些体会!\n"NOR);
          me->improve_skill("parry", (int)(me->query("int") / 10));
        }
        return 1;
}
