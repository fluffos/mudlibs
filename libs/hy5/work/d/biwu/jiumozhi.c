// /kungfu/class/xueshan/jiumozhi.c 鸠摩智
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("鸠摩智", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "大轮明王" NOR);
        set("long",@LONG
他就是雪山寺的掌门，人称大轮明王的鸠摩智。他对佛法有精深的研究。
身穿一件大红袈裟，头带僧帽。
LONG
        );
        set("title","雪山寺掌门");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 130);
        set("int", 140);
        set("con", 130);
        set("dex", 130);
        set("max_qi", 355000);
        set("max_jing", 352000);
        set("neili", 355000);
        set("max_neili", 355000);
        //set("jiali", 100);
        set("combat_exp", 10500000);
        set("score", 500000);

        set_skill("necromancy", 950);
        set_skill("force", 900);
        set_skill("xiaowuxiang", 980);
        set_skill("dodge", 900);
        set_skill("shenkong-xing", 980);
        set_skill("unarmed", 900);
        set_skill("yujiamu-quan", 980);
        set_skill("parry", 1000);
        set_skill("sword", 1000);
        set_skill("mingwang-jian", 950);
        set_skill("lamaism", 950);
        set_skill("literate", 1000);
        set_skill("staff", 1000);
        set_skill("xiangmo-chu", 980 );
        set_skill("strike", 1000);
        set_skill("huoyan-dao", 980);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("雪山寺", 1, "掌门");
        set("class", "bonze");

        setup();

//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
carry_object("/p/item/ritemtz3/ahands1")->wear();
        add_money("silver",50);
}

