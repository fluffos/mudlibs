
// lm_guard.c

inherit NPC;

void create()
{
	set_name("彩衣少女", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 16);
	set("str", 18);
	set("cor", 18);
    set("max_force", 180);
    set("force", 180);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
    小姑娘是晚月庄的女弟子，虽说身形单薄，可眼神里透出的傲气让
人感到并不好欺负。
LONG
);
	set("combat_exp", 50000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"少女说道：你当这里是什么地方，敢来这里骚扰？\n",
		"少女说道：你要是再无理取闹，当心庄主的鞭子！\n",
		"少女手中的鞭子越舞越快，让你应接不暇。\n",
		"少女说道：你当晚月庄的女子好欺负么？！\n"
	}) );
	set("inquiry", ([
		"蓝止萍": "庄主的名字也是你这等人随便叫的么？",
		"晚月庄": "庄主吩咐过，不许乱讲。",
	]) );

	set_skill("whip", 40);
	set_skill("parry", 20);
        set_skill("dodge", 40);
	

        set_skill("snowwhip", 330);

        map_skill("whip", "snowwhip");

	setup();
	
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

