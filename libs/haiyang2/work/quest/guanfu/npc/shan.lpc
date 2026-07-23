// shan 单正
 
inherit NPC;
 
void create()
{
	set_name("单狰", ({ "shan zheng", "shan" }));
	set("nickname", "泰山单家叛徒");
	set("long", 
        "泰山单家的叛徒，性如烈火，一身功夫少有敌手。\n");
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -85000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 6800);
	set("max_jing", 6800);
	set("neili", 6800);
	set("max_neili", 6800);
	set("jiali", 100);
	set("combat_exp", 850000); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
               (: perform_action, "force.powerup" :),
        }));
        set_skill("force", 160);
        set_skill("huntian-qigong", 320);
        set_skill("dodge", 150);
        set_skill("xiaoyaoyou", 160);
        set_skill("strike", 160);
        set_skill("tiezhang-zhangfa", 160);
        set_skill("parry", 160);
       
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
    
        map_skill("strike", "tiezhang-zhangfa");
  	map_skill("parry", "tiezhang-zhangfa");
  	prepare_skill("strike", "tiezhang-zhangfa");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
      
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
