// saodiseng.c
inherit NPC;

string ask_me1();
string ask_me2();

void create()
{
	set_name("É¨µØÉ®", ({ "saodi seng","seng"}) );
	set("gender", "ÄĞĞÔ" );
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 22);
	set("int", 18);
	set("con", 21);
	set("dex", 19);

	set("qi", 500);
	set("max_qi", 500);
	set("jing", 250);
	set("max_jing", 250);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 5000);

	set_skill("force", 35);
	set_skill("dodge", 35);
	set_skill("parry", 35);

	setup();
	carry_object("/clone/cloth/c-jiasha")->wear();
}
