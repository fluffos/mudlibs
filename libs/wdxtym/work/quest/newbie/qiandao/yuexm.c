// yue.c 岳小玫
// lag 2000.5.9
#include <ansi.h>
inherit NPC;

int ask_job();
int ask_fail();


void create()
{
        set_name("岳小玫", ({ "yue xiaomei", "yue" }));
        set("nickname", HIC "星月传奇小娇倩" NOR);
        set("gender", "女性");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 55);
        
        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 250);
	set("combat_exp", 6000000);
	set("score", 500000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_skill("force", 400);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 400);
	set_skill("unarmed", 400);
	set_skill("taiji-quan", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("taiji-jian", 400);
	set_skill("liangyi-jian", 400);
	set_skill("wudang-array", 400);
	set_skill("array",400);
	set_skill("taoism", 400);
	set_skill("literate", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

        set("inquiry", ([
                "任务" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "job" : (: ask_job() :),
                "fail" : (: ask_fail() :),

          ])),

        set("env/important", 1);    
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);

        setup();
	carry_object("/clone/weapon/changjian")->wield();
          carry_object("/d/city/obj/cloth")->wear();
}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;

        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;


   if(this_object()->is_busy())
{
message_vision("岳小玫对$N说道：“我正忙着呢！”\n",me);
return 1;
}
   if(this_object()->is_fighting())
{
message_vision("岳小玫对$N说道：“我正忙着呢！”\n",me);
return 1;
}

   if((int)me->query("potential") - (int)me->query("learned_points")  > 200000)
{
message_vision("岳小玫对$N说道：“你的潜能太多了，我不能给你任务！”\n",me);
return 1;
}

      if ((int)me->query_condition("menpai_busy"))  
            {
                       command("say " + RANK_D->query_respect(me) + "现在没有强盗，你还是休息一会再来吧");
                      return 1;
            }
           if (me->query("combat_exp") < 80000) {
                command("say " + RANK_D->query_respect(me) + "杀强盗可不是一件容易的事情，你还是练高修为再来吧");
                return 1;
}
//        if (me->query("combat_exp") > 6000000) {
//                command("admire "+(string)me->query("id"));
//                command("say " + RANK_D->query_respect(me) + "是人间奇才,我哪里敢劳动您的大架呢！");
//                return 1;
//        }
if (me->query_condition("yue_busy"))
{
                command("say 你刚放跑了强盗，怎么又来了？");
                return 1;
        }
   if ((int)me->query_condition("guojob2_busy"))
{
                command("say 你先休息一会吧!");
                return 1;
}

        if (me->query("potential") < 200 || me->query("combat_exp") < 30000) {
                command("say 你连本钱都没有，我怎么放心要你去杀强盗呢？");
                return 1;
        }
        if (me->query("kill_qiangdao") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
//		me->map_skill("unarmed");
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能为侠侣情缘出力，真是太好了。");
                command("say " + me->query("id") + " 强盗在『" + quest["short"]             + "』，快去吧！\n" NOR);
                me->apply_condition("menpai_busy",4);
                me->set("kill_qiangdao", 1);
                me->set("quest/quest_type", "杀");
                me->set("quest/quest", "强盗");
                me->set("task_time", time() + 310);
                this_object()->start_busy(1);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                me->start_busy(4);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp")+random(100000));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_qi", me->query("max_qi") );
                ob->set("max_jing", me->query("max_jing") );
                ob->set("qi", me->query("max_qi"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                ob->set("neili",me->query("max_neili")*2 );
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
string mapa;
        object me = this_player();
        
        if (me->query("kill_qiangdao") == 1) {
                command("haha");
                command("say 你这身手也敢来惩奸除恶，都怪小玫我当初看错了人,扣你80点POT.");
//              command("chat " + me->query("name") + "没有真功夫，致使强盗危害一方。");
me->apply_condition("yue_busy",8);
/*if (random(7)==0)
{
mapa="/d/xingxiu/tianroad";
                me->move(mapa+(random(6)+1));
}
else if (random(7)==1)
{
mapa="/d/xingxiu/xxh";
               me->move(mapa+(random(6)+1));
}
else if (random(7)==2)
{
mapa="/d/xingxiu/silk";
               me->move(mapa+(random(4)+1));
}
else if (random(7)==3)
{
mapa="/d/xingxiu/shamo";
               me->move(mapa+(random(4)+1));
}
else if (random(7)==4)
{
mapa="/d/xingxiu/nanjiang";
               me->move(mapa+(random(3)+1));
}
else if (random(7)==5)
{
mapa="/d/hj/caoyuan";
               me->move(mapa+(random(10)+1));
}
else if (random(7)==6)
{
mapa="/d/hj/gebi";
               me->move(mapa+(random(5)+1));
}

else
{
mapa="/d/xingxiu/xxroad";
           me->move(mapa+(random(6)+1));
}*/
if (me->query("potential") >100)
{
                me->add("potential",-80);
}
me->delete("kill_qiangdao");
me->start_busy(8);
                return 1;
                }
}

