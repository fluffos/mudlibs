inherit NPC;

void create()
{
	set_name("卖艺人", ({ "maiyi ren", "ren" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是一个卖艺人，以杂耍谋生。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 3000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        set("chat_chance", 2);
	set("chat_msg", ({
		"卖艺人吆喝道：有钱的捧个钱场，没钱的捧个人场啦。\n",
		
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

