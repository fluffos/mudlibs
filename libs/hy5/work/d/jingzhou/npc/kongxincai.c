// Room: /d/jingzhou/npc/kongxincai.c
// Date: 99/06/01 by Byt

inherit NPC;
void create()
{
	set_name("空心菜", ({ "kong xincai","kong","xincai"}) );
	set("gender", "女性" );
	set("age", 4);
	set("long", "戚芳的女儿，一个活泼可爱的小女孩。\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
        set("per", random(12)+20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);

         set("chat_chance", 10);
         set("chat_msg", ({
		"空心菜得意地道：“空心菜在花园！空心菜看蚂蚁！”\n",
	}));        
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

