// bfighter.c

inherit NPC;

void create()
{
        set_name("趟子手", ({ "tangzi shou" }) );
        set("gender", "男性" );
        set("age", 38);
        set("str", 25);
        set("cor", 27);
        set("int", 23);
	set("max_kee",700);
        set("max_force", 300);
        set("force", 300);
        set("force_factor", 10);

        set("pursuer", 1);
        set("env/wimpy", 30);

        set("long",@LONG
这是一位日月镖局的趟子手，负责镖局的护镖任务。
LONG);

        set("combat_exp", 40000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "趟子手喊道：日月镖局..., 盛名远扬...\n",
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "趟子手喊道：教你尝尝我的厉害！\n",
                "趟子手叫道：我们镖局可不是好惹的！\n"
                "趟子手大叫：我一定要杀了你，替镖局扬名！\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("blade", 50);
        set_skill("force", 20);
        set_skill("literate", 10);


        setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}