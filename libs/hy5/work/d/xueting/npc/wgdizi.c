// dizi.c

inherit NPC;

void create()
{
	set_name("武馆弟子", ({ "wuguan dizi" }) );

	if(random(10)<7)
		set("gender", "男性" );
	else
		set("gender", "女性" );

	set("age", 20+random(15));
	//set("class","huashan");

	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10+random(40));

	set("long", "这是一个淳风武馆第五代的弟子。\n");
	create_family("淳风武馆", 5, "弟子");

        set("combat_exp", 400000);

        set_skill("unarmed", 120);
        set_skill("literate", 80);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	if(random(10)<7)
		carry_object("/clone/weapon/gangjian")->wield();            
	carry_object("/clone/misc/cloth")->wear();  
}
