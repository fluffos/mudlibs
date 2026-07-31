// liandan_fang.c

#include <ansi.h>

inherit ROOM;

#define DAN_DIR         "/d/beijing/npc/dan/"

int do_liandan(string arg);

void create()
{
        set("short", "炼丹房");
        set("long", @LONG
这是姚春的炼丹房，四周堆放着炼丹的药材，一个漆黑的炼丹炉(lu)耸立
在中央，房中的药味经久不散，并且总有一股散不尽的淡青色烟雾，长时间的
丹药炼制已经让这个房间充满了神秘的色彩。
LONG );
        set("no_fight", 1);
        set("item_desc", ([
                "lu" : "一个深黑色的大铁丹炉，顶部不停地升起丝丝青烟。\n",
        ]));

        set("exits", ([
                "south" : __DIR__"liandan_yaoshi",
        ]));

        setup();
}

void init()
{
        add_action("do_liandan", "liandan"); 
}

int do_liandan(string arg)
{
        int time;

        object me = this_player();
        time = 10 + random(10);

        if (me->is_busy())
                return notify_fail("等你有空了再说吧。\n");

        if ((int)me->query_temp("liandan") < 1)
                return notify_fail("炼丹之地，切勿滋扰。\n");

        if ((int)me->query_temp("liandan") < 2)
                return notify_fail("原料都没有，炼什么啊？\n");

        if ((int)me->query_temp("liandan") == 3)
                return notify_fail("丹药炼制中，请勿分心。\n");

        if ((int)me->query_temp("liandan") == 4)
                return notify_fail("炼制成功，快去复命吧。\n");

        if ((int)me->query("jing") < 80 ||
            (int)me->query("qi") < 80)
                return notify_fail("你已经筋疲力尽了。\n");

        message_vision(HIY "$N" HIY "将原料药材一一放进炉中，盘"
                       "腿坐下，闭目静待。\n" NOR, me); 
        me->set_temp("liandan", 3);
        me->start_busy(time);
        me->start_call_out((: call_other, __FILE__, "liandan", me :), time);
        return 1;
}

// 特殊丹列表
string *SM_LIST = ({ "dans_1", "dans_2", "dans_3", "dans_4", "dans_5",
                     "danm_3", "danm_4", "danm_5", "danm_7", "danm_8",
                     "danm_9" });

// 普通丹列表
string *NORMAL_LIST = ({ "danm_1", "danm_2", "danm_6",
                         "dana_1", "dana_2", "dana_3", // "dana_4", "dana_5",
                         "danb_1", "danb_2", "danb_3", "danb_4", "danb_5", "danb_6",
                         "danc_1", "danc_2", "danc_3", "danc_4", "danc_5",
                         "dand_1", "dand_2", "dand_3", "dand_4", "dand_5", "dand_6", });

void liandan(object me)
{
        object ob;
        int a;

        if (environment(me) != this_object())
                return;

        me->receive_damage("jing", 50 + random(30));
        me->receive_damage("qi", 50 + random(30));
        if (random(3) == 1) 
        {
                me->set_temp("liandan", 1);
                message_vision(HIR "正当$N" HIR "昏昏然的时候，一阵刺鼻"
                               "的气味从炉中冲出，$N" HIR "急忙开炉取药，"
                               "结果被弄得个灰头土脸。\n"NOR,me);
        } else
        // if (random(40) == 1)
        if (random(me->query_skill("liandan-shu", 1)) > 100 || random(40) == 1)
        {
                message_vision(HIY "炉顶青烟渐渐转淡，蓦然一道金光闪过，$N"
                               HIY "不禁吃了一惊，此时丹药气味渐浓，$N"
                               HIY "赶紧把炼制而成的丹丸取出。\n" NOR, me);
                me->set_temp("liandan", 4);
                ob = new(DAN_DIR + SM_LIST[random(sizeof(SM_LIST))]);
                tell_object(me, CYN "你炼成了珍品" + CYN + ob->name() + "。\n" NOR);
                ob->move(me, 1);
        } else
        {
                message_vision(HIC "炉顶青烟渐渐转淡，丹药气味渐浓，$N"
                               HIC "高兴地把炼制而成的丹丸取出。\n" NOR, me);
                me->set_temp("liandan", 4);
                ob = new(DAN_DIR + NORMAL_LIST[random(sizeof(NORMAL_LIST))]);
                tell_object(me, CYN "你炼成了" + CYN + ob->name() + "。\n" NOR);
                ob->move(me, 1);
        }
        me->start_busy(0);
}

