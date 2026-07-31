//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("白自在",({"bai zizai","bai"}));
        set("nickname", HIC"威德先生"NOR);
        set("gender", "男性");
        set("age", 55);
        set("long", 
             "他就是雪山剑派的掌门人，习武成性，自认为天下武功第一,\n"
             "他大约五十多岁，精明能干，嫉恶如仇，性如烈火。\n");
        set("attitude", "peaceful");

        set("str", 55);
        set("con", 55);
        set("int", 50);
        set("dex", 50);
        set("per", 55);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);
        set("inquiry", ([
            "石中玉"   : "如果让我逮到这个小王八蛋,我非剥了他的皮不可。",
        ]) );

        set("combat_exp", 8000000);
        set("shen_type", 1);
        set("score", 100000);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 250);
        set_skill("sword", 380);
        set_skill("force", 320);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("literate", 200);

        set_skill("xueshan-sword", 380);
        set_skill("bingxue-xinfa", 380);
        set_skill("snow-zhang", 380);
        set_skill("snowstep", 380);


         set_skill("doom-hand", 380);
        set_skill("hanshan-strike", 380);
        set_skill("snowwhip", 380);
        set_skill("hand", 280);
        set_skill("strike", 280);
        set_skill("whip", 280);
set_skill("mingyu-gong", 380);


        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
if (random(3)==0)
{
        map_skill("sword", "mingyu-gong");
        map_skill("parry", "mingyu-gong");
        map_skill("force", "mingyu-gong");
        map_skill("unarmed", "mingyu-gong");
        map_skill("dodge", "snowstep");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.gua" :),
                (: perform_action, "unarmed.moqi" :),
                (: perform_action, "unarmed.qiong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "zu" :)                	
        }) );	
	
}
else
{
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");
	
}

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("凌霄城", 5, "掌门");
        setup();

        
        carry_object("/d/lingxiao/obj/icesword")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 你这种资质,也好意思来找我！");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    } 
    if ((int)ob->query("shen") < 50000 ) {
         command("say 我威德先生乃堂堂正人君子，怎能收你。"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say 你内力不足，怎能领悟我神功的精妙。"); 
                return;
    }
    if ((int)ob->query_skill("xueshan-sword",1) < 100 ) { 
        command("say 你的本门剑法太低了,还是先找你原来的师父提高吧!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say 你的基本剑法太低了,还是先提高基本功吧!"); 
                return; 
    }
    command("say 很好，很好,老子今天心情好,就收下你吧。");
    command("say 这个城老子没心情管了，你就先帮我管着吧。");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", HIW"凌霄城城主"NOR); 
}



void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book11")>=4))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book11")==3))
{
		message_vision("$N说道：我不会败的，不 不 不！难道你是侠客岛的人?? \n" NOR,this_object());
		i = 900+random(1000);
		who->set("jinyong/book11",4);
		who->add("combat_exp",i+13000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+13000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}
        }
	::die();
}                         