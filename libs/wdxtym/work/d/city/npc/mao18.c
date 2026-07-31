// mao18.c 茅十八 
	
	
#include <ansi.h> 
	
inherit NPC; 
	
void create() 
{ 
	set_name("茅十八", ({ "mao shiba", "mao", "shiba" })); 
	set("gender", "男性"); 
	set("age", 30); 
	set("str", 25); 
	set("dex", 16); 
	set("long", "他虬髯如乱草，满脸血污，好象曾受过很重的伤，可以看得见\n" 
	    "他左腿上血迹未干。但他双目炯炯，却又有着说不出的威风。\n"); 
	set("combat_exp", 35000); 
	set("shen_type", 1); 
	set("score", 4000); 
	set("attitude", "peaceful"); 
       
	set_skill("unarmed", 50); 
	set_skill("force", 60); 
	set_skill("blade", 80); 
	set_skill("dodge", 50); 
	set_skill("parry", 50); 
       
	set_skill("wuhu-duanmendao", 70); 
       
	set_temp("apply/attack", 30); 
	set_temp("apply/defense", 30); 
	set_temp("apply/armor", 5); 
	set_temp("apply/damage", 10); 
       
	map_skill("blade", "wuhu-duanmendao"); 
       
	set("neili", 200);  
	set("max_neili", 200); 
	set("jiali", 20); 
	set("inquiry", ([ 
		"史松" : "杀了史松这奸贼，可以提高江湖威望。\n", 
		"威望" : "有了威望，名头响亮啊！", 
	])); 
       
	set("chat_chance", 2); 
	set("chat_msg", ({ 
		"\n茅十八说道: 他奶奶的，我就不信鳌拜有这等厉害,\n" 
		"我正要上北京去斗他一斗。" , 
		"\n茅十八叹道: 用我这五虎断门刀法对付盐枭可是绰绰有余,只不知对付鳌拜行不行。\n", 
		"\n茅十八说道: 江湖威望很重要！威望高大有好处啊...\n", 
		"\n茅十八说道: 他奶奶的，谁帮我杀了史松，兄弟我谢谢你了！\n", 
		"\n茅十八说道: 老听人说，那鳌拜是满洲第一武士，他妈的,\n" 
		"还有人说他是天下第一勇士，我可不服气，要上北京去跟他比划比划。\n" , 
		"\n茅十八朗声说道：江湖有言：“为人不识陈近南，就称英雄也枉然。”\n", 
		(: random_move :) 
	}) ); 
	setup(); 
	carry_object("/d/city/obj/gangdao")->wield(); 
	carry_object("/clone/misc/cloth")->wear(); 
} 
       
void init() 
{	
	object ob;  
       
	::init(); 
	if (interactive(ob = this_player())) 
	{ 
		remove_call_out("greeting"); 
		call_out("greeting", 1, ob); 
	} 
} 
       
void greeting(object ob) 
{ 
	if (! ob || environment(ob) != environment()) return; 
	message_vision("$N拱手道：兄弟腿上不方便，不能起立行礼了。\n", this_object()); 
} 
       
void die() 
{ 
	say("茅十八哈哈大笑道：托韦兄弟的福，我见过了陈近南总舵主，虽死无憾啊！\n"); 
	::die(); 
} 
       
int accept_object(object me, object ob) 
{ 
	if (ob->query("id") == "heilong bian") 
	{ 
		if (! me->query_temp("can_learn/mao18/wuhu-duanmendao")) 
		{ 
			message_vision("$N喜道：“多谢这位" + 
				       RANK_D->query_respect(me) + 
				       "，我这里有套五虎断门刀法，你可有兴趣？”\n", 
				       this_object()); 
			me->set_temp("can_learn/mao18/wuhu-duanmendao", 1); 
		} 
		me->set_temp("can_learn/mao18/wuhu-duanmendao", 1); 
       
		if (me->query("weiwang") < 200)
		{
			me->add("weiwang", 10); 
			message_vision(HIC "$N的江湖威望提高了！"NOR"\n", this_player()); 
		}
		destruct(ob); 
		return -1; 
	} 
      
	command("say 这种东西鬼才要！滚开！"); 
	return 0; 
} 
      
int recognize_apprentice(object me, string skill) 
{ 
	if (! me->query_temp("can_learn/mao18/wuhu-duanmendao"))
	{
		command("say 你这人啊.... 嘿嘿，我得考虑考虑。");
		return -1;
	}
      
	if (skill != "wuhu-duanmendao") 
		return 0; 
      
	return 1; 
} 
      
