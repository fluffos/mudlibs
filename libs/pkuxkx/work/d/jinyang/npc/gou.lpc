// gou.c 

inherit NPC;

void create()
{
	
    set_name("来福", ({ "dog","lai fu" }) );
	set("race", "野兽");
	set("age", random(2));
	set("long", "一只吐着长舌头的小花狗，它的名字叫来福。\n");
	set("max_qi", 500);
	set("qi", 500);
	set("str", 30);
	set("con", 50);
	set("dex", 50);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 800000);
	set("chat_msg_combat", ({
		"来福大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"来福转了一个圈，似乎对它的尾巴产生了浓厚的兴趣。\n"
	}) );
		
    set_temp("apply/attack", 100);
    set_temp("apply/damage", 100);
	set_temp("apply/armor", 800);

	setup();
}
