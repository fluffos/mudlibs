//  shusheng.c
inherit NPC;

void create()
{
	set_name("落魄书生", ({ "luopo shusheng","shusheng" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
		"这是一个书生，穿的很是简朴，一副愁眉苦脸的样子。\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	"name" :"唉，告诉你我的名字有什么用？那还有脸见家中父老。。",
	]) );
	setup();

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 40);
	set_skill("strike", 40);
	set_skill("parry", 40);
	set_skill("dodge", 46);
	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 15);
}
