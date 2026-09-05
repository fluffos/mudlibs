// 香烛老板
// created by Zine 5 Sep 2010

inherit NPC;


int ask_knowledge();
void create()
{
	switch( random(1) ) 
	{case 0:
	set_name("哈希", ({ "ha xi","ha","ha laoban"}) );
	set("title", "香烛店老板娘");
	set("gender", "女性" );
	set("long", "老板娘为人尖酸刻薄，紧紧盯着来往的顾客，生怕被人顺走什么东西。\n");
	set("chat_chance", 20);
	set("chat_msg", ({
		this_object()->query("name")+"吟道：贤愚千载知谁是，满眼蓬蒿共一丘。\n",
	}) );
	case 1:
	set_name("哈希", ({ "ha xi","ha","ha laoban"}) );
	set("title", "香烛店老板娘");
	set("gender", "女性" );
	set("long", "老板娘为人尖酸刻薄，紧紧盯着来往的顾客，生怕被人顺走什么东西。\n");
	set("chat_chance", 4);
	set("chat_msg", ({
		this_object()->query("name")+"吟道：贤愚千载知谁是，满眼蓬蒿共一丘。\n",
	}) );
	}
    set("age", 35);
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
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
    carry_object("/d/jinyang/obj/yycloth")->wear();
}

