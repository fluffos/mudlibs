// sheep_girl.c

inherit NPC;

void create()
{
	set_name("牧羊女", ({ "sheep girl", "girl" }) );
	set("gender", "女性" );
	set("age", 17);
	set("long", "一个天真活泼小女孩。 \n");
	set("combat_exp", 30000);
	set("per", 30);
	set("str", 30);
	set("kar", 30);
	set("max_kee", 700);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("unarmed", 60);

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}
