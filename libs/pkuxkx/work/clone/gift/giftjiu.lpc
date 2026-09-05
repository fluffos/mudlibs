// File         : giftjiu.c
// Created By   : iszt@pkuxkx, 2006-08-14

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"玄冰"HIG"碧火酒"NOR, ({"xuanbing bihuojiu", "bihuojiu", "jiu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR"这是武林中传闻已久的玄冰碧火酒，兼具阴阳调合之功，当真珍奇之极。\n"NOR);
                set("unit", "壶");
                set("value", 400000);
                set("no_store", 1);

        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();
        object ob = this_object();
        string msg;
        int reward;
        if(arg != "xuanbing bihuojiu" && arg != "bihuojiu" && arg != "jiu")
                return 0;
        if(me->query("gift/2006guoqing"))
                return notify_fail("你已经喝过玄冰碧火酒了，再喝也没什么效果。\n");
        if(me->query("combat_exp") < 20000)
                return notify_fail("你的经验太低，无法运功化解玄冰碧火酒的毒性。\n");
        if(me->query_skill("force") < 30)
                return notify_fail("你的基本内功太弱，无法运功化解玄冰碧火酒的毒性。\n");
        msg = YEL"$N灌下一壶"+ob->query("name")+NOR+YEL"，一股辛辣之气充盈在四周久久不散。\n";
        message_vision(msg, me);

        msg = WHT"你的内力增加了十点！\n";
        me->add("max_neili", 10);
        reward = 10 * me->query("neili") + random(100);
        msg += WHT"你的经验增加了"+chinese_number(reward)+"点！\n";
        me->add("combat_exp", reward);
        me->add("exp/2006guoqing", reward);
        reward = random(2);
        if(reward && me->query("combat_exp") > 100000)
        {
                msg += WHT"你的灵性增加了！\n";
                me->add("spi", reward);
                me->add("xiantian/spi/2006guoqing", reward);
        }
        msg += WHT"你的基本内功进步了！\n"NOR;
        me->set_skill("force", me->query_skill("force", 1) + 10);
        tell_object(me, msg);

        me->add("gift/2006guoqing", 1);
        me->save();
        destruct(ob);
        return 1;
}
