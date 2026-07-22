//Cracked by Roath
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("盖一鸣", ({ "gai yiming","gai" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"他短小精悍，下巴尖削，说起话来细声细气。\n");
	set("nickname","八步赶蟾、赛专诸、踏雪无痕、独脚水上飞、双刺盖七省");
	set("title","太岳四侠");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  20);
	set("apply/defense", 20);

	set("chat_chance", 15);
	set("chat_msg", ({
		"盖一鸣一摆峨眉刺，细声细气的道：「你有什麽宝贝，给我们留下吧！」\n",
		"盖一鸣双刺一击，叮叮作响。\n",
	}) );

	set_skill("sword", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	setup();
        carry_object(__DIR__"obj/emeici")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
