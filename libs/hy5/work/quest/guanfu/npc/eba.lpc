//  eba 恶霸
 
inherit NPC;
 
void create()
{
	set_name("恶霸", ({ "e ba", "e" }));
//	set("nickname", "");
	set("long", 
        "一个危害一方的恶霸，强男霸女，无恶不做。\n");
	set("gender", "男性");
	set("age", random(20) + 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5200);
	set("max_jing", 5200);
	set("neili", 5200);
	set("max_neili", 5200);
	set("jiali", 100);
	set("combat_exp", 380000 + random(300000)); 
	 
        set_skill("force", 140);
        set_skill("canhe-zhi", 120);
        set_skill("finger", 120);
        set_skill("shenyuan-gong", 320);
           set_skill("shaolin-shenfa", 120);
        set_skill("dodge", 140 + random(20));
        set_skill("strike", 120 + random(50));
        set_skill("sword", 120 + random(50));
        set_skill("parry", 120 + random(50));
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "canhe-zhi");
  	map_skill("parry", "canhe-zhi");
 
        prepare_skill("finger", "canhe-zhi");
  	setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
