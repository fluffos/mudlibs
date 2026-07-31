// ji.c 纪晓芙

inherit NPC;

void create()
{
	set_name("纪晓芙", ({ "ji xiaofu","ji","xiaofu"}));
	set("long",
		"她是峨嵋派的第四代俗家弟子。偏心偏听的灭绝抛弃她，\n"
		"她独自在这里苦度光阴。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("inquiry",([
		"倚天剑"  : "这是我们郭师祖传下来的镇派之宝。",
		"屠龙刀"  : "宝刀屠龙... 宝刀屠龙... 。",
		"杨不悔"  : "我的女儿啊。她在哪里？你知道么？",
		"杨逍"    : "我这辈子是不指望见到他了。",
		"灭绝"    : "师父就是太偏心。",
	]));

	set("max_qi", 2500);
	set("max_jing", 1200);
	set("neili", 2700);
	set("max_neili", 2700);

	set("combat_exp", 320000);
	set_skill("throwing", 40);
	set_skill("persuading", 40);
	set_skill("force", 140);
	set_skill("dodge", 80);
	set_skill("finger", 70);
	set_skill("parry", 70);
	set_skill("strike", 70);
	set_skill("sword", 130);
	set_skill("jinding-zhang", 70);
	set_skill("tiangang-zhi", 70);
	set_skill("huifeng-jian", 130);
	set_skill("zhutian-bu", 80);
	set_skill("emei-xinfa", 140);
	set_skill("linji-zhuang", 140);

	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	command("sigh");
	command("recruit " + ob->query("id"));
}
