
// soldier.c

inherit NPC;

void create()
{
	set_name("守城卫士", ({ "soldier" }) );
	set("gender", "男性" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
   这个士兵整副武装,忠于职守,用警觉的目光注视着每一个人. 
LONG
);
	set("combat_exp", 5000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"卫兵说道：你当这里是什么地方，敢来这里骚扰？\n",
		"卫兵说道：你要是再无理取闹，当心将军出来杀了你！\n",
		"卫兵手中的剑越舞越快，让你应接不暇。\n",
		"卫兵说道：你当宁远镇的人是好欺负么？！\n"
	}) );

	set_skill("sword", 40);
	set_skill("parry", 20);
        set_skill("dodge", 40);
	


	setup();
	
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

