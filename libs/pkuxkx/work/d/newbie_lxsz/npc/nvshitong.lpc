//D:\xkx\d\liuxiu-shanzhuang\npc\nvshitong.c女侍童
//labaz 2012/10/23

inherit NPC;

void create()
{
	set_name("女侍童", ({ "nv shitong", "shitong"}));
	set("title", "柳秀山庄");
	set("gender", "女性");
	set("age", 12);
	set("long", "她是柳秀山庄的小侍童，看上去十分机灵的样子。\n");

	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}

