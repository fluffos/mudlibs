// 村长
// created by Zine 5 Sep 2010

inherit NPC;


int ask_knowledge();
void create()
{
	switch( random(1) ) 
	{case 0:
	set_name("地主老财", ({ "dizhu","laocai"}) );
	set("title", "吃人不吐骨头");
	set("gender", "男性" );
	set("long", "他是晋阳城最大的地主。\n");
	set("chat_chance", 20);
	
	case 1:
	set_name("地主老财", ({ "dizhu","laocai"}) );
	set("title", "吃人不吐骨头");
	set("gender", "男性" );
	set("long", "他是晋阳城最大的地主。\n");
	set("chat_chance", 20);
	}
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
    set("age", 25+random(45));
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", -100);
    set("combat_exp", 1000000);
    set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
    carry_object("/d/jinyang/obj/gpcloth")->wear();
}

