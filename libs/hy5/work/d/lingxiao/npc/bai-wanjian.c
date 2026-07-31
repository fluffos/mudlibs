//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
        set_name("白万剑",({"bai wanjian","bai"}));
        set("nickname", HIC"气寒西北"NOR);
        set("gender", "男性");
        set("age", 30);
        set("long", 
               "白万剑是雪山派掌门人威德先生白自在的长子，他\n"
                "们师兄弟均以“万”字排行，他名字居然叫到白万剑,\n"
                "足见剑法之高.他外号气寒西北,与‘风火神龙’封万\n"
                "里合称‘雪山双杰’。\n");
        set("attitude", "peaceful");

        set("str", 50);
        set("con", 50);
        set("int", 50);
        set("dex", 50);
        set("per", 50);
        set("neili", 53000);
        set("max_neili", 53000);
        set("jing", 16000);
        set("max_jing", 16000);
        set("qi", 16000);
        set("max_qi", 16000);
        set("jiali", 80);

        set("combat_exp", 6500000);
        set("score", 50000);
        set("inquiry", ([
            "白自在"   : "老爷子的台炜是你叫的吗!。",
            "老爷子"   : "你想拜见老爷子吗？但他闭关面壁,你得找成师叔要到玉牌,才能见到他。",
            "掌门"   : 
     "你想拜见老爷子吗？但他闭关面壁,你得找成师叔要到玉牌,才能见到他。",
              "玉牌"   : "寒玉牌乃我门中重宝,只有凭它,才能进入监狱。",
        ]));
        set("shen_type", 1);


        set_skill("unarmed", 200);
        set_skill("sword", 280);
        set_skill("force", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 120);

        set_skill("xueshan-sword", 300);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 280);
        set_skill("snowstep", 280);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        create_family("凌霄城", 6, "弟子");
        setup();
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        carry_object("/clone/money/gold.c");
        carry_object("/d/lingxiao/obj/baihongjian.c")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 28) {
        command("say 你这种资质,怎能跟我学剑！");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 60 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    } 
    if ((int)ob->query_skill("xueshan-sword",1) < 80 ) { 
        command("say 你的本门剑法太低了,还是先找你原来的师父提高吧!"); 
                return;
        }
    if ((int)ob->query_skill("sword",1) < 80 ) {  
        command("say 你的基本剑法太低了,还是先提高基本功吧!"); 
                return; 
    }
    if ((int)ob->query("shen") < 20000 ) {
         command("say 学剑须先正身，你做到了吗?"); 
                return;
    } 

    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", "凌霄城第七代弟子"); 
}

