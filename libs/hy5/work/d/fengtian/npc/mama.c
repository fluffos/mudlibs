// mama.c

inherit NPC;
 
void create()
{
	set_name("老鸨子", ({"ma ma"}));
	set("long", "这是一位徐娘半老的老鸨。\n");
	set("gender","女性");

	set("age",45);
	set("con",20);
	set("str",20);

	set("combat_exp",100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
