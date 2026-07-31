
// crazy_dog.c

inherit NPC;

void create()
{
	set_name("狼狗", ({ "wolf dog", "dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只齿尖爪利的狼狗，一双眼睛正恶狠狠地瞪著你。\n");
	set("attitude", "aggressive");
	
	set("str",50 );
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp",61100);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"狼狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"狼狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );
		
	set_temp("apply/attack", 65);
	set_temp("apply/damage",26);
	set_temp("apply/armor",22);

	setup();
}

