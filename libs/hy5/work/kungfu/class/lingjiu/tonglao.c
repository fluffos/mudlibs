// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_job2();
void create()
{
	set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "她就是「灵鹫宫」的开山祖师.\n"+
	    "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
	    "双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
	set("title", "灵鹫宫主人");
	set("gender", "女性");
	set("age", 96);
	set("nickname", HIR "唯我独尊" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 65);
	set("int", 65);
	set("con", 60);
	set("dex", 60);

	set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 39000);
	set("max_neili", 39000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 200000);
	        set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu", 380);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);

	set_skill("wuzhan-mei",380);
	set_skill("zhemei-shou",380);
	set_skill("liuyang-zhang",380);
        set_skill("tianyu-qijian",380);
	set_skill("yueying-wubu",380);
	set_skill("bahuang-gong", 380);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");
	set("inquiry", ([
                "李秋水" : (: ask_job2() :),
                "护送" : (: ask_job() :),
                "逍遥子" : (: ask_job() :),
	]) );
        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("灵鹫宫",1, "开山祖师");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 800);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="女性")
           {
 		command("say 你找死啊!");
		return;
	   }
   if ((int)ob->query_skill("bahuang-gong", 1) < 160) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }
   if (ob->query_con() < 30) 
      	   {
		command("say 本门功法极为难练,你的根骨似乎不够.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "dancer")
     ob->set("class", "dancer");
   return;
}



int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/quest/where")->query_quest();

        skl = me->query_skills();

        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 180) skill = 180;

        if(((int)me->query("jinyong/book4")>6))
           {
                      message_vision("$N对着$n说道。我最近没什么事要你帮忙的。\n", this_object(), me);
	                      return 1;
            }

        if(((int)me->query("jinyong/book4")!=6))
           {
                      message_vision("$N对着$n说道。你找我做什么啊？ 你见过我师兄了吗？\n", this_object(), me);
	                      return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高经验再来吧");
                return 1;
}
        

        if (me->query_temp("lingjiujob") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是已经让你护送过我了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "我因练功 功力大失，需要出外逃避几天。");
                command("say " + me->query("id") + " 她到『" + quest["short"]             + "』附近等你！\n" NOR);
                command("say " + me->query("id") + "到时你把我护送回灵鹫百丈涧就行了，此事要保密行事！\n" NOR);
                command("say " + me->query("id") + "事不宜迟 我这就出去逃避几天！\n" NOR);
                me->set_temp("lingjiujob", 1);
                me->set("quest/quest_type", "护送");
                me->set("quest/quest", "小女孩");
                me->set("task_time", time() + 480);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"dashi",1);
                ob->move(quest["place"]);
                ob->set("combat_exp", me->query("combat_exp"));
 call_out("leavet",1);
                return 1;
               }                              
}



int ask_job2()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;

                        
        if (skill < 180) skill = 180;

        if(((int)me->query("jinyong/book4")>7))
           {
                      message_vision("$N对着$n说道。我最近没什么事要你帮忙的。\n", this_object(), me);
	                      return 1;
            }

        if(((int)me->query("jinyong/book4")!=7))
           {
                      message_vision("$N对着$n说道。你在说谁啊？\n", this_object(), me);
	                      return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高经验再来吧");
                return 1;
}
        

        if (me->query_temp("lingjiujobkill") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是让你去杀李秋水那个贱人了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "听说李秋水那个贱人  藏在西夏皇宫中。");
                command("say " + me->query("id") + "能否帮我对付这个贱人?\n" NOR);
                me->set_temp("lingjiujobkill", 1);

                return 1;
               }                              
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}