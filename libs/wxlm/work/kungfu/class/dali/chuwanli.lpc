// chuwanli.c 褚千山



inherit NPC;
inherit F_GUARDER;

void create()
{
	set_name("褚千山", ({ "chu wanli", "chu" }));
	set("title",  "大理国护卫" );
	set("long", "他是大理国四大护卫之一。身穿黄衣，脸上英气逼人。手持一根铁杆。\n");
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1800);
	set("max_jing", 900);
	set("neili", 1900);
	set("max_neili", 1900);
	set("jiali", 45);
	set("combat_exp", 310000);
	set("score", 8000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("staff", 80);
	set_skill("cuff", 75);
	set_skill("jinyu-quan", 75);
	set_skill("shaolin-xinfa", 80);
	set_skill("tiannan-step", 70);
	set_skill("duanjia-sword", 80);
	set_skill("literate", 30);

	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	set("coagents", ({
		([ "startroom" : "/d/dali/neitang",
		   "id"	: "duan zhengchun", ]),
	}));

	set("guarder", ([
		"refuse_home" : "$N拦住$n道：对不起！王爷有令，出了段家就莫回来。\n",
		"refuse_other": "$N一把拦住$n，喝道：闲杂人等，不能入内。\n",
		"refuse_carry": "$N陪着笑脸对$n道：可否将... 你背的人放下再进王府？\n",
	]));

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object(__DIR__"obj/diaogan")->wield();
	add_money("silver", 10);

	create_family("段氏皇族", 0, "护卫");
}
