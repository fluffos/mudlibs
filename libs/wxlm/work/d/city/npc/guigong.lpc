// guigong.c
inherit NPC;

void create()
{
	set_name("保卫", ({ "gui gong", "gui", "gong" }));
	set("gender", "男性");
	set("age", 25);

	set("long", "一个满脸狠肉的汉子，在观乐楼日子久了，养的白白肥肥。\n");
	set("combat_exp", 30000);
	set("shen_type", 2);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set("chat_msg", ({
	     "想跑？跑到天涯海角都给你追回来！",
	     "哼！你们活该！",
	}) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
