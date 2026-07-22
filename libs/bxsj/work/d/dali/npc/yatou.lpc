//  yatou.c丫头

inherit NPC;

void create()
{
	set_name("丫头", ({ "ya tou","ya" }) );
	set("gender", "女性");
	set("age", 14);
	set("long",
		"大理城内大富人家的一个小丫头,上街买东西。\n");
	set("combat_exp", 700);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	"name" :"哼，你是不是对我不怀好意啊？",
	]) );
	setup();

	set("apply/attack", 10);
	set("apply/defense", 10);

	set_skill("unarmed", 20);
	set_skill("claw", 20);
	set_skill("parry", 20);
	set_skill("dodge", 26);
	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 3);
}       

