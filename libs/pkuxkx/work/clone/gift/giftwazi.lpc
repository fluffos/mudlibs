// File         : giftwazi.c
// Created By   : iszt@pkuxkx, 2006-12-23

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

string *name = ({"袜子", "破袜子", "臭袜子", "烂袜子", "脏袜子"});
string *id = ({"wa zi", "po wazi", "chou wazi", "lan wazi", "zang wazi"});

void create()
{
        int index = random(sizeof(name));
        set_name(HIY + name[index] + NOR, ({id[index]}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", CYN"这是一双"+query("name")+CYN"，似乎能装点什么东西，你可以摸(mo)一下看看。\n"NOR);
                set("unit", "双");
                set("value", 1000);
                set("no_store", 1);
                set("no_pawn", 1);
                set("no_sell", 1);
                set("zigong_count", 1);
                set("armor_prop/force", 41);
                set("armor_prop/dodge", 41);
                set("armor_prop/parry", 41);
        }
        setup();
}

void init()
{
        add_action("do_mo", "mo");
}

int do_mo(string arg)
{
        object me = this_player();
        object ob = this_object();
        string msg;

	if(arg != query("id"))
                return 0;
        if(!query("zigong_count"))
                return notify_fail("你摸了一把，并没有摸到什么。\n");
        if(me->query("gift/2006christmas"))
                return notify_fail("你已经拿到属于自己的礼物了。\n");
        msg = HIG"$N满脸憧憬的伸手进"+query("name")+HIG"摸了一把，摸到一颗"HIM"紫宫丸"HIG"！\n";
        message_vision(msg, me);
        ob = new(__DIR__"giftzigong");
        ob->move(me);
        add("zigong_count", -1);

        if(!random(4) && me->query("combat_exp") > 100000)
        {
                msg = WHT"你猛然间领悟到了一点「雪山剑法」！\n"NOR;
                me->improve_skill("xueshan-jianfa", 4);
		tell_object(me, msg);
        }

        me->add("gift/2006christmas", 1);
        me->save();

        return 1;
}
