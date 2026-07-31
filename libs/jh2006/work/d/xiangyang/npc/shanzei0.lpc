// /d/xiangyang/npc/shanzei0.c

//#define MAX(a, b) (a > b ? a : b)

inherit NPC;

void create()
{
	set_name("山贼", ({"shan zei", "shanzei", "shan", "zei"}));
	set("long", "他是一个没拿武器的山贼，一副耀武扬威的样子。\n");

	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 25);
	set("shen_type", -1);
	set("shen", 1000);
	set("str", 22);
	set("int", 20);
	set("con", 21);
	set("dex", 18);
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 250);
	set("max_neili", 250);
	set("jiaji", 2);
	set("combat_exp", 3000);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_skill("parry", 40);

	setup();
}

void do_copy(object ob, int rate)
{
	mapping hp_status;

	hp_status = ob->query_entire_dbase();

	set("str", hp_status["str"]);
	set("int", hp_status["int"]);
	set("con", hp_status["con"]);
	set("dex", hp_status["dex"]);

	set("max_qi",    hp_status["max_qi"] * rate / 100);
	set("eff_qi",    hp_status["eff_qi"] * rate / 100);
	set("qi",        hp_status["qi"] * rate / 100);
	set("max_jing",  hp_status["max_jing"] * rate / 100);
	set("eff_jing",  hp_status["eff_jing"] * rate / 100);
	set("jing",      hp_status["jing"] * rate / 100);
	set("max_neili", hp_status["max_neili"] * rate / 100);
	set("neili",     hp_status["neili"] * rate / 100);
	set("jiali",     hp_status["jiali"] * rate / 100);
	set("combat_exp",hp_status["combat_exp"] * rate / 100);

	set_skill("force", MAX(ob->query_skill("force", 1) * rate / 100, 40));
	set_skill("dodge", MAX(ob->query_skill("dodge", 1) * rate / 100, 30));
	set_skill("unarmed", MAX(ob->query_skill("unarmed", 1) * rate / 100, 40));
	set_skill("parry", MAX(ob->query_skill("parry", 1) * rate / 100, 40));
}
