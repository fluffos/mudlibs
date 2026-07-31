// eseng 恶僧
 
inherit NPC;
 
void create()
{
	set_name("恶僧", ({ "e seng", "seng" }));
//	set("nickname", "");
	set("long", 
        "少林的叛僧，干了不少坏事，据说时常出没在烟花柳巷。\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 3500);
	set("max_jing", 3400);
	set("neili", 3700);
	set("max_neili", 3700);
	set("jiali", 10);
	set("combat_exp", 75000 + random(40000)); 
	 
         set_skill("force", 60);
         set_skill("hunyuan-yiqi", 320);
         set_skill("dodge", 60);
  

        set_skill("shaolin-shenfa", 30 + random(50));
        set_skill("cuff", 30 + random(50));
        set_skill("sword", 30 + random(50));
        set_skill("luohan-quan", 50 + random(50));
        set_skill("parry", 30 + random(50));
        set_skill("damo-jian", 30 + random(50));
        set_skill("literate", 20);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("cuff", "luohan-quan");
  	map_skill("parry", "damo-jian");
        
        prepare_skill("cuff", "luohan-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
