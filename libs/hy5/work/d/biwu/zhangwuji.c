//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    set("title",HIG "明教"HIM"教主"NOR);
    set("gender", "男性");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 128);
    set("str", 136);
    set("int", 136);
    set("con", 130);
    set("dex", 130);

    set("qi", 354050);
    set("max_qi", 354050);
    set("jing", 354050);
    set("max_jing", 354050);
    set("neili", 358000);
    set("max_neili", 358000);
    set("jiali", 120);

    set("combat_exp", 155000000);
    set("score", 455000);
    
    set_skill("force", 1250);
    set_skill("unarmed", 1200);
    set_skill("dodge", 1200);
    set_skill("parry", 1220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 1300);
    set_skill("cuff", 1250);
    set_skill("jiuyang-shengong", 980);
    set_skill("qiankun-danuoyi", 980);
    set_skill("qishang-quan", 980);
    set_skill("shenghuo-shengong", 980);
    set_skill("taiji-quan",1150);
    set_skill("taiji-jian",1150);
    set_skill("taiji-dao",1150);
    set_skill("shenghuo-ling",1390);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);

    create_family("明教",34, "教主");

    set("chat_chance",2);
    set("chat_msg",({
 "张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
        "张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
        "张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.lian" :),                
                (: perform_action, "sword.can" :),                
                (: perform_action, "sword.hua" :),                                	                	
                (: perform_action, "unarmed.hun" :),                                	                	
                (: perform_action, "unarmed.jiu" :),                                	                	
                (: perform_action, "unarmed.ri" :),                                	                	
                (: perform_action, "unarmed.pi" :),                                	                	                	                	                	
                (: perform_action, "unarmed.po" :),                                	                	                	                	                	
                (: command("unwield sword") :),
                (: command("exert shield") :),
                (: command("wield sword") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );

    setup();
    carry_object("/p/item/ritemtz3/wsword44")->wield();
    carry_object("/p/item/ritemtz3/ahands42")->wear();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

