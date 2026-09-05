// File         : giftzigong.c
// Created By   : iszt@pkuxkx, 2006-12-23

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"紫宫丸"NOR, ({"zigong wan", "zigong", "wan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM"这是一颗紫宫丸，据说能提高服食者的功力。\n"NOR);
                set("unit", "颗");
                set("value", 50000);
                set("no_store", 1);
                set("no_pawn", 1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();
        string msg;

        if(arg != ob->query("id") && arg != "zigong" && arg != "wan")
                return 0;
	if(me->query("gift/2006christmas") >= 2)
                return notify_fail("紫宫丸多吃有害无益，吃过还是不要再吃的好。\n");
        if(me->query("combat_exp") < 2000)
                return notify_fail("你的经验太低，服食紫宫丸只怕不好。\n");
        msg = MAG"$N急急忙忙的吞下一枚紫宫丸，顿时感到自己的身体产生了些变化！\n"NOR;
        message_vision(msg, me);

        me->improve_skill("chatting", random(200));
        me->improve_skill("chatting", random(200));
        me->improve_skill("chatting", random(200));
        me->improve_skill("chatting", random(200));
        me->improve_skill("chatting", random(200));
        me->improve_skill("rumoring", random(200));
        me->improve_skill("rumoring", random(200));
        me->improve_skill("rumoring", random(200));
        me->improve_skill("rumoring", random(200));
        me->improve_skill("rumoring", random(200));
        me->improve_skill("huyou-wiz", random(5));

        if(random(2) && me->query("gender") == "男性")
        {
                msg = HIW"【江湖传闻】听说"+me->query("name")+HIW"误食"HIM"自宫丸"HIW"，变成了一个太监！\n"NOR;
		message("channel:baowei", msg, users());
		CHANNEL_D->do_channel(me, "chat*", "taijian "+me->query("id"), 1);
                me->set("gender", "无性");
                me->set("zigongwan", 1);
        }

        me->add("gift/2006christmas", 1);
        me->save();

        destruct(ob);
        return 1;
}
