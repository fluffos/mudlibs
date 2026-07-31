// huo.c

inherit NPC;

void create()
{
	set_name("霍先生", ({"huo xiansheng", "huo", "xiansheng"}));
	set("long",
"他一身邋遢，形容委琐，整天迷迷糊糊的睡不醒模样。可是他的账务十几年来无可挑剔。
原来他就是伏牛派的崔百泉，为避仇祸隐居于此。\n"
	);

	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 51);
	set("shen_type", 0);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
