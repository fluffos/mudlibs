// wangtiejiang.c
#include <ansi.h>

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

string ask_work();

void create()
{
        set_name("王铁匠", ({ "wang tiejiang", "wang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "王铁匠是外地人，刚刚在此开了个打铁铺，买卖倒也红火。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("inquiry", ([
                "work" : (: ask_work :),
                "劳动" : (: ask_work :),
        ]));
        set("vendor_goods", ({
                __DIR__"obj/gangdao",
         "/d/city/obj/tiejia",
                __DIR__"obj/changjian",
                __DIR__"obj/duanjian",
                "/clone/weapon/dart",
                "/clone/weapon/wuyingzhen",
                "/d/xingxiu/npc/obj/tiegun",
                "/d/village/npc/obj/hammer",    
           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_ding", "ding");
}

int do_ding(string arg)
{
        write(geteuid());
        seteuid("pretty");
        write(geteuid());
        return 1;
}
string ask_work()
{
        object me = this_player();
        string respect = RANK_D->query_respect(me);
        int reward;
        object ob;

        if(query("startroom") != file_name(environment(this_object())))
                return "我现在身有要事，还望"+respect+"见谅。";
        if(me->is_busy())
                return respect+"还是先忙完了吧。";
        if(me->query_temp("apply/strength") < 30)
                return "好吧，"+respect+"就在此地劳动(work)吧。";
        if(me->query("gift/20070501"))
                return respect+"辛苦了，不用劳动了。";
        if(me->query("20070501/str"))
                return respect+"不妨去别处看看有没有需要帮忙劳动的。";
        command("thank " + query("id"));
        command("say 多谢"+respect+"，请下去休息休息吧。");
        write(HIW"你被奖励了：\n");
        reward = me->query_skill("force") + me->query_skill("parry");
        reward *= 5;
        write("\t"+chinese_number(reward)+"点经验；\n");
        me->add("combat_exp", reward);
        write("\t"+chinese_number(reward/5)+"点潜能。\n"NOR);
        me->add("potential", reward/5);

        me->set("20070501/str", 1);
        if(sizeof(me->query("20070501")) >= 4)
                me->set("gift/20070501", 1);
        if(me->query("gift/20070501"))
        {
                ob = new("/d/wizard/obj/xiandou2");
                ob->set("no_store", 1);
                ob->set("no_sell", 1);
                ob->set("no_pawn", 1);
                message_vision(HIM"$N交给$n一颗仙豆。\n"NOR, this_object(), me);
                ob->move(me);
                me->delete("20070501");
                command("chat* buddhi "+me->query("id"));
                return "这是你用辛勤劳动换来的五一礼物，祝你五一快乐！劳动光荣！";
        }
        else
                return respect+"不妨去别处看看有没有需要帮忙劳动的。";
}
