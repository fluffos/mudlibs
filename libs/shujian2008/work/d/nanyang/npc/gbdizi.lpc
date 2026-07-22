inherit FIGHTER;
#include <ansi.h>
#include "/d/city/npc/skills_pfm.h";
void create()
{
    	set_name("丐帮弟子", ({"gaibang dizi", "dizi"}));
    	set("gender", "男性");
    	set("age", 65);
    	set("per",24);
    	set("long", "丐帮长老。\n");
    	set("attitude", "friendly");
      set("no_bark",1);
      set("dgb/wugou",6);
      set("str", 30);
      set("con", 30);
      set("dex", 30);
    	set("int", 22);
    	set("max_qi", 25000);
    	set("max_jing", 3600);
    	set("neili", 24000);
    	set("max_neili", 13000);
    	set("jiali", 200);
    	set("eff_jingli",4000);
    	set("combat_exp", 5400000);

    	set_skill("force", 300);
    	set_skill("huntian-qigong", 300);    
    	set_skill("strike", 300);           
    	set_skill("xianglong-zhang", 300);   
      set_skill("literate",200);          
    	set_skill("dodge", 300);           
    	set_skill("xiaoyaoyou", 300);       
    	set_skill("parry", 300);            
    	set_skill("stick", 300);            
    	set_skill("dagou-bang", 300);        
    	set_skill("begging", 200);          
    	set_skill("checking", 200);        
    	set_skill("bangjue",200);          
    	set_skill("dagou-zhen",200);	    
      set_skill("lianhua-zhang",300);     
      set_skill("stealing",200);         
    	map_skill("force", "huntian-qigong");
    	map_skill("strike", "xianglong-zhang");
    	map_skill("dodge", "xiaoyaoyou");
    	map_skill("parry", "xianglong-zhang");
    	map_skill("stick", "dagou-bang");
    	prepare_skill("strike", "xianglong-zhang");

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: perform_action, "strike.xiao" :),
        	(: exert_function, "powerup" :),
        	(: perform_action, "strike.paiyun" :),
      		(: perform_action, "strike.xiao" :),
        }));

    	create_family("丐帮", 19, "九袋长老");
        set_temp("apply/damage", 70);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 70);
    	setup();
        carry_object("/clone/armor/bainayi")->wear();
        carry_object("/clone/armor/gb_budai9")->wear();
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
   	ob->set("party","gb");  	  
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
