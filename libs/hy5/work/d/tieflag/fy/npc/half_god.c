 // half_god.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
string sysmsg;
void create() {
        set_name(HIY"天机老人"NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "男性");
        set("age", 99);
        set("long", "天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，
尤在上官，小李之上．此人亦正亦邪，凡事都由爱恶而定。天机老人收徒极挑剔．．．．\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({ "天机老人拿起旱烟抽了几口．．．．\n" }));
        set("neili", 80000);
        set("max_jing", 80000);
        set("max_sen", 80000);
        set("max_neili", 80000);
        set("eff_qi", 80000);
        set("max_qi", 80000);
        set("force_factor", 1000);
    set("combat_exp", 100000000);
        set("score", 200000);
        set_skill("unarmed", 320);
        set("pubmaster",1);
        set_skill("force", 300);
        set_skill("iron-cloth", 600);
        set_skill("yiqiforce", 630);
        set_skill("dagger",600);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
   map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce"); 

        create_family("潇遥派", 1, "祖师");
        set("title", "闲云野鹤");
        setup(); 
        carry_object(__DIR__"obj/jade-cloth")->wear();
        carry_object(__DIR__"obj/hanyan");
} 
int accept_fight(object me) {
                command("say 生命可贵！不要自寻死路！");
                return 0;
} 
void attempt_apprentice(object me) {
        switch(random(4)) {
                case 0:
                        message_vision("$N对$n笑问道：什么是心剑？\n", this_object(),me);
                        break;
                case 1:
                   message_vision("$N对$n笑问道：什么是＂敌不动，我不动；敌一动，我先动？＂\n", this_object(),me); 
                        break;
                case 2:
                        message_vision("$N对$n笑问道：＂有形，无形＂是什么？\n", this_object(),me);             
                        break;
                case 3:
                        message_vision("$N对$n笑问道：武学的最高境界是什么？\n", this_object(),me);
                        break;
        }
} 
void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        //sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        //set("eff_sen",sen);set("sen",sen);
        return ; 
}   

void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n天机老人长叹:忘恩负义之徒！！！\n"NOR);                  
                message("vision", YEL"天机老人对"+ ob->name() +"叹道：“"+ ob->name() + "！ 国师叫我代他清理门户，容你不下了！\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"天机老人一拳击在你的天灵盖上！\n"NOR);              
                message("vision", HIW"天机老人一拳击在"+ ob->name() +"的天灵盖上！\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
                ob->set("title",HIC"少林叛徒"NOR);
                ob->die();
          }
}  

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
