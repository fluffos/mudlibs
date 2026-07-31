//  caokou 草寇
 
inherit NPC;
 
void create()
{
	set_name("草寇", ({ "cao kou", "cao" }));
//	set("nickname", "");
	set("long", 
        "一个四处流窜的草寇，坏事干了不少。\n");
	set("gender", "男性");
	set("age", random(20) + 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 380000 + random(300000)); 
	 
         set_skill("force", 100);
         set_skill("hunyuan-yiqi", 100);
         set_skill("dodge", 100 + random(30));
  

        set_skill("shaolin-shenfa", 110 + random(50));
        set_skill("strike", 110 + random(50));
        set_skill("sword", 110 + random(50));
        set_skill("kunlun-zhang", 110 + random(30));
        set_skill("parry", 110 + random(50));
        set_skill("damo-jian", 110 + random(50));
        set_skill("literate", 20);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "damo-jian");
  	 
        prepare_skill("strike", "kunlun-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
