//  cao 曹化淳
 
inherit NPC;
 
void create()
{
	set_name("曹化淳", ({ "cao huachun", "cao" }));
//	set("nickname", "");
	set("long", 
        "原是朝廷的宦官，后来由于贪赃枉法，被朝廷查办的时候逃跑了。\n");
	set("gender", "无性");
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
         set_skill("hunyuan-yiqi", 70);
         set_skill("dodge", 60);
  

        set_skill("shaolin-shenfa", 30 + random(50));
        set_skill("strike", 40 + random(40));
        set_skill("sword", 40 + random(40));
        set_skill("parry", 40 + random(40));
        set_skill("damo-jian", 40 + random(50));
        set_skill("kunlun-zhang", 40 + random(50));
        set_skill("literate", 20);
 	  map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "damo-jian");
        prepare_skill("strike", "kunlun-zhang"); 
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
