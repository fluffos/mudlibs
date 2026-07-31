//  dadao 江洋大盗
 
inherit NPC;
 
void create()
{
    set_name("江洋大盗 王三", ({ "jiangyang dadao", "dadao" }));
	set("long", 
        "一个无恶不做的江洋大盗，四处打家劫舍，作恶多端。\n");
	set("gender", "男性");
	set("age", random(20) + 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 3200);
	set("max_jing", 31200);
	set("neili", 3200);
	set("max_neili", 3200);
	set("jiali", 100);
	set("combat_exp", 380000 + random(300000)); 
	 
         set_skill("force", 150);
         set_skill("hunyuan-yiqi", 320);
         set_skill("dodge", 120 + random(30));
  

        set_skill("shaolin-shenfa", 120 + random(30));
        set_skill("strike", 120 + random(30));
        set_skill("sword", 120 + random(30));
        set_skill("parry", 120 + random(30));
        set_skill("chousui-zhang", 120 + random(30));
        set_skill("murong-jianfa", 120 + random(30));
        set_skill("literate", 20);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "chousui-zhang");
  	map_skill("parry", "murong-jianfa");
  	map_skill("sword", "murong-jianfa");
        
        prepare_skill("strike", "chousui-zhang");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
