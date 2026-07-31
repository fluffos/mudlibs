// guanzhong.c

inherit NPC;

void create()
{
	set_name("观众", ({ "guan zhong" }) );
	if(random(10)<5)
		set("gender", "男性" );
	else
		set("gender", "女性" );
	set("age", 30);
	set("max_kee",400);
	set_skill("unarmed",60);

	set("long",
		"这是一位天水镇的镇民，正摇头晃脑，听得如醉如痴。\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
