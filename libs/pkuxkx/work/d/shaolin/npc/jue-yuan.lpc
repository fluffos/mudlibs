// File         : jue-yuan.c
// Created By   : iszt@pkuxkx, 2007-04-27

#include <ansi.h>

inherit FAMILY_NPC;

string ask_work();

void create()
{
        set_name("觉远大师", ({ "jueyuan dashi", "jueyuan", "dashi", }) );
        set("title", YEL"少林寺挑水僧"NOR);
        set("gender", "男性" );
        set("age", 60);
        set("long", "这是一个身穿破旧僧袍的僧人，正担着两个巨大的木桶。\n");
        set("attitude", "friendly");
        add("inquiry", ([
/*
                "work" : (: ask_work :),
                "劳动" : (: ask_work :),
*/
        ]));
        set("jiali", 50);
        set("combat_exp", 6400000);
        set_shaolin(this_object(), 300, 0);
        set("shen_type",1);set("score",10000);setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_work()
{
        object me = this_player();
        string respect = RANK_D->query_respect(me);
        int reward;
        object ob;

        if(query("startroom") != file_name(environment(this_object())))
                return "善哉，贫僧现在身有要事，还望"+respect+"见谅。";
        if(me->is_busy())
                return "阿弥陀佛，"+respect+"还是先忙完了吧。";
        if(me->query_temp("apply/dexerity") < 30)
                return "善哉，"+respect+"就在此地劳动(work)吧。";
        if(me->query("gift/20070501"))
                return respect+"辛苦了，不用劳动了。";
        if(me->query("20070501/dex"))
                return respect+"不妨去别处看看有没有需要帮忙劳动的。";
        command("buddhi " + query("id"));
        command("say 多谢"+respect+"，请下去休息休息吧。");
        write(HIW"你被奖励了：\n");
        reward = me->query_skill("force") + me->query_skill("parry");
        reward *= 5;
        write("\t"+chinese_number(reward)+"点经验；\n");
        me->add("combat_exp", reward);
        write("\t"+chinese_number(reward/5)+"点潜能。\n"NOR);
        me->add("potential", reward/5);

        me->set("20070501/dex", 1);
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
