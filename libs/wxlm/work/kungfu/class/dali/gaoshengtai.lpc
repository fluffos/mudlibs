// gaoshengtai.c 高昇泰


inherit NPC;

void create()
{
	set_name("高昇泰", ({ "gao shengtai", "gao" }));
	set("title",  "大理善阐侯" );
	set("long", "大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。\n");
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_qi", 2200);
	set("max_jing", 1000);
	set("neili", 3300);
	set("max_neili", 3300);
	set("jiali", 60);
	set("combat_exp", 720000);
	set("score", 15000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("cuff", 110);
	set_skill("strike", 110);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("duanshi-xinfa", 110);
	set_skill("tiannan-step", 120);
	set_skill("jinyu-quan", 110);
	set_skill("wuluo-zhang", 110);
	set_skill("duanjia-sword", 110);
	set_skill("literate", 60);

	map_skill("force", "duanshi-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
	carry_object(__DIR__"obj/tiedi")->wield();
	add_money("silver", 20);

	create_family("大理段家", 0, "武将");
}
