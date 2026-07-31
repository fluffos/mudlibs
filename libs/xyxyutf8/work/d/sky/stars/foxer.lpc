
//note: this is created from player data.
//foxer.c
inherit NPC;

void create()
{
	set_name("阿绣", ({"foxer"}));
	set("long",
"西王母座下杰出弟子。有功夫，有才气，人又长得漂亮，天上地下都吃得开。\n");
	set("title", "心月星官");
	set("gender", "女性");
	set_level(80);
	set("age", 20);
	set("class", "xian");
	set("attitude", "friendly");
	set("per", 22);
	set("max_kee", 1123);
	set("max_gin", 200);
	set("max_sen", 1381);
	set("force", 4346);
	set("max_force", 2173);
	set("force_factor", 133);
	set("mana", 4286);
	set("max_mana", 2143);
	set("mana_factor", 108);
	set("combat_exp", 1162000);
	set("env/no_teach", 1);

	set("eff_dx", 800000);
	set("nkgain", 800);

	set_skill("baihua-zhang", 600);
	set_skill("dodge", 600);
	set_skill("force", 600);
	set_skill("literate", 600);
	set_skill("moondance", 600);
	set_skill("moonforce", 600);
	set_skill("moonshentong", 600);
	set_skill("parry", 600);
	set_skill("snowsword", 700);
	set_skill("spells", 600);
	set_skill("sword", 600);
	set_skill("unarmed", 600);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	create_family("月宫", 2, "弟子");
	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}