// dizi.c

inherit NPC;
 
void create()
{
	set_name("武馆弟子", ({"wuguan dizi", "dizi"}));
	set("long", "这是一位精壮的大汉，一看就
是练过几天武功的人。\n");
	set("gender","男性");

	set("age",28);
	set("con",30);
	set("str",20);
	set("max_kee",700);
	set("max_gin",250);
	set("max_sen",250);

	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("unarmed",50);

	set("combat_exp",50000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
