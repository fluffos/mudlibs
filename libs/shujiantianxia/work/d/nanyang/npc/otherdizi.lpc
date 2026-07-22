inherit FIGHTER;
#include <ansi.h>
string *str_menpai = ({ "wd","hs","ss","gm","tz","dls","sld","mj","thd","kl"});       
#include "/d/city/npc/skills_pfm.h";
void create()
{
	set_name("无名小子", ({ "wuming xiaozi", "xiaozi" }));
	set("long",
		"他长脸深目，瘦骨棱棱，约莫三十岁左右年纪。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 40);
	set("con", 40);
	set("dex", 28);
	set("max_qi", 25000);
	set("max_jing", 6000);
	set("neili", 15000);
	set("max_neili", 10000);
	set("jiali", 200);
	set("eff_jingli", 6000);
	set("jingli", 6000);
	set("combat_exp", 5800000);
	set("score", 400000);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		 (: perform_action, "strike.diezhang" :),
     (: exert_function, "taxue" :),
	}));

	set_skill("art", 200);
    set_skill("literate", 380);
	set_skill("force", 385);
	set_skill("xuantian-wuji", 385);
	set_skill("dodge", 300);
	set_skill("taxue-wuhen", 300);
	set_skill("strike", 380);
	set_skill("kunlun-zhang", 380);
	set_skill("cuff", 380);
	set_skill("zhentian-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 310);
	set_skill("liangyi-jian", 310);
	set_skill("throwing", 380);
	map_skill("cuff", "zhentian-quan");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "kunlun-zhang");
	map_skill("sword", "liangyi-jian");
	prepare_skill("strike", "kunlun-zhang");
	prepare_skill("cuff", "zhentian-quan");
	setup();
  add_temp("apply/attack",100);
  add_temp("apply/defense",200);
  add_temp("apply/armor_vs_force",200);
  add_temp("apply/armor",200);
  carry_object("/d/sld/npc/obj/slp")->wear();    
}
void init()
{
    object ob;  
    int i;     
    ::init();
    ob = this_object();
 	if(ob->query("setok")) return;
	ob->set("setok",1);
	i=400;	
   	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	  
	ob->copy_menpai(({ob->query("party")}),random(2),random(2),100);    //复制npc的门派武功，                                                   
	ob->copy_state();				//根据门派更新npc 的一些状态
	ob->set("max_qi", 25000);
	ob->set("eff_qi", 25000);
	ob->set("qi", 25000);
	ob->set("max_jing", 6000);
	ob->set("neili", 15000);
	ob->set("max_neili", 10000);
	ob->set("jiali", 200);
	ob->set("eff_jingli", 6000);
	ob->set("jingli", 6000);
	ob->set("combat_exp", 5800000);
	ob->set_skills_level(i);
	ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
	ob->set_skill("wuxing-zhen",ob->query("int")*10); 	 									
}
