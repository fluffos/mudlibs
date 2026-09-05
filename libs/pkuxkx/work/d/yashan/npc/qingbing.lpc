// bing.c 官兵

inherit NPC;

void create()
{
	set_name("清兵", ({ "qing bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他们是北洋舰队的海军，被李鸿章调到牙山来准备和日本决一死战。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 500000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

	if (random(2) == 1) {
		set("chat_chance", 80);
		set("chat_msg", ({
			"马上要打仗了，不知道我老婆孩子怎么样了？\n",
			"该死的日本人，他们要是敢和我们大清做对，我们一定要他们好看!\n",
			"听上头说，好像咱们的炮弹不是很够哇?\n",
			"济远和光乙两艘战舰厉害着呢，只要熟练操作，一定能把日本人打趴下!\n",
		}));
	}

    setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/handbook");
}
