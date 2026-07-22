// dizi.c

inherit NPC;

void create()
{
	int i = 1+random(10);
	set_name("弟子", ({ "dizi", "trainee" }) );
	set_level(i);
	set("gender", "男性" );
	set("age", 18+random(10));
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练着。\n");

	set_skill("dodge", i*10);
	set_skill("unarmed", i*10);
	set_skill("parry", i*10);

	setup();
	carry_object(0,"cloth",0)->wear();
}
