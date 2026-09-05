// yetu.c 野兔
//by hehe
//203.3.22

inherit NPC;

void create()
{
	set_name("野兔", ({ "ye tu", "yetu","tu",}) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只好可爱的小野兔。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
	set("chat_chance", 5);
    set("chat_msg", ({
		(: random_move :),
		}) );

	set_temp("murong/shoot",1);
	setup();
}
