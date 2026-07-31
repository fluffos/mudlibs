// hau 花剑影
inherit NPC;
 
void create()
{
	set_name("花剑影", ({ "hua jianying", "hua" }));
//	set("nickname", "");
	set("long", 
        "有着一个好听的名字，可惜功夫平平，还时常打劫一些路客。\n");
	set("gender", "男性");
	set("age", random(10) + 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5500);
	set("max_jing", 5400);
	set("neili", 5700);
	set("max_neili", 5700);
	set("jiali", 10);
	set("combat_exp", 175000 + random(40000)); 
	 
        set_skill("force", 60);
        set_skill("dodge", 40 + random(50));
        set_skill("strike", 50 + random(50));
        set_skill("parry", 40 + random(50));
        set_skill("literate", 20);
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
