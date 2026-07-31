// gaiyiming 盖一鸣
inherit NPC;
 
void create()
{
	set_name("盖一鸣", ({ "gai yiming", "gai" }));
//	set("nickname", "");
	set("long", 
        "一张蜡黄的脸，时常找一些单身的行人下手的小强盗。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 10);
	set("combat_exp", 95000 + random(40000)); 
	 
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
