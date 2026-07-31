// qigai.c

inherit NPC;

void create()
{
	set_name("老乞丐", ({ "qi gai","beggar","gai" }) );
	//set("title", "妙手神丐");
	set("title", "乞丐");
	set("gender", "男性" );
	set("age", 53);
	set("long", "一个满脸风霜之色的老乞丐。\n");

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("max_qi", 1500);
	set("max_jing", 1100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("shen_type", 0);

	set_temp("apply/attack",  120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage",  120);

	set("combat_exp", 200000);
	set("str", 27);
	set("kar", 100);
	set("thief", 0);
	set("force", 200);

	set("max_force", 200);
	set("force_factor", 2);

	set_skill("unarmed", 150);
	set_skill("sword", 150);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("stealing", 300);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"老乞丐说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
		"老乞丐懒洋洋地打了个哈欠。\n",
		"老乞丐伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
	}) );
	create_family("丐帮", 19, "弟子");

        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
	add_money("silver", 1);
}

