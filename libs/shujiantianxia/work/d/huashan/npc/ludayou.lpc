// NPC: /d/huashan/npc/dayou.c
// Date: Look 99/03/25
// Modify By Looklove@SJ 2000/01/07 for add a job
// Lklv Modify at 2001.10.18

#include <ansi.h>
inherit NPC;
string ask_job();

void create()
{
        set_name("陆大有", ({ "lu dayou", "lu", "dayou" }));
        set("nickname", "六猴儿");
        set("long",
"陆大有身材很瘦，又长的尖嘴猴腮的，但别看他其貌不扬，他在\n"
"同门中排行第六，是华山派年轻一代中的好手。\n");
        set("gender", "男性");
        set("age", 26);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 13);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("cuff", 100);
        set_skill("zixia-gong", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("poyu-quan", 100);
        set_skill("zhengqi-jue", 100);

        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("cuff", "poyu-quan");

        prepare_skill("cuff", "poyu-quan");

        create_family("华山派", 14, "弟子");

        set("inquiry", ([
              "砍柴" : (: ask_job :),
        ]));

        setup();
        carry_object(BINGQI_D("sword/sword"))->wield();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_job()
{
        object ob, me, dao;
        me = this_player();

        if(me->query("family/family_name") != "华山派")
               return "你非我华山弟子，这些活还是不麻烦你了。";
        //if ((int)me->query("combat_exp") >= 30000)
        if ((int)me->query("combat_exp") >= 100000)
                return "你武功已成，还是去给师傅帮忙吧。\n";
        if (me->query("shen") < 1000)
                return "你眼露凶光, 最近是不是做了什么坏事？ ";
        if (me->query_temp("hs/kc_job"))
                return "不是让你去砍柴了吗？怎么还不去？\n";
        if(me->query_condition("job_busy"))
               return "我现在很忙，你一会再来吧。";

        dao = present("chai dao", me);

        if (!dao){
	        ob=new(__DIR__"obj/chaidao");
        	ob->move(me);
        	tell_object(me, "陆大有给你一把柴刀。\n");
        }
        me->set_temp("hs/kc_job",1);
        me->apply_condition("job_busy", 6+random(6));
        command("ok "+me->query("id"));
        return "伙房的仆人来说，他那里现在缺柴禾做饭，你去朝阳峰砍些吧。\n";
}
