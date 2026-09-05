// emei npc 守山弟子
//--by bibi--
// Rewrote by iszt@pkuxkx, 2007-02-12

#include "lev.h"

void create()
{
	set_name("小土匪",({"xiao tufei", "tufei"}));     
	set("gender","男性");
	set("long","这是一位小土匪！\n");
	set("attitude", "aggressive");
	set("max_qi" , 1500);
	set("qi" , 1500);
	set("max_jing" , 1500);
	set("jing",1500);
	set("max_neili" , 3000);
	set("neili" , 3600);  
	set("combat_exp",1500000);
	set_skill("force",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("sword",200);      
	set_skill("strike",200);  
	set_skill("fuliu-jian",200);
	set_skill("jinding-mianzhang",250);
	set_skill("zhutian",250);	   
	set_skill("linji-zhuang",250);
	set("jiali" , 170);
		 
	map_skill("dodge","zhutian");
	map_skill("parry","fuliu-jian");
	map_skill("sword","fuliu-jian");
	map_skill("strike","jinding-mianzhang");
	map_skill("force","linji-zhuang");

	prepare_skill("jinding-mianzhang"); 

	set("vendetta/authority",1);
	set("death_msg", "$N最后挣扎了两下，咽了气。\n");
					 
	set("shen_type",-1);
set("score",500);
setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();  
}