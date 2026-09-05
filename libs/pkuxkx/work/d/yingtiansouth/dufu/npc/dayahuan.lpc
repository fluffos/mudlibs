inherit NPC;


void create()
{
	set_name("大丫鬟", ({ "da yahuan", "yahuan","ya","huan" }));
	set("gender", "女性");
	set("age", random(15) + 20);
	set("str", 10);
	set("dex", 10);
	set("long", "她是一名都府里的大丫鬟，几乎相当于内府的总管。\n");
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 10);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	setup();
	carry_object(__DIR__"obj/cloth_yahuan2")->wear();
}
