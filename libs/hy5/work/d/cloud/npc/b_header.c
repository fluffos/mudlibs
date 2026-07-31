
// b_header.c
//modified by ttf

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陈剑秋", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "霹雳刀");
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "陈镖头");

		set("long",@LONG
    陈剑秋在十几年前创立了振远镖局，凭着一手春风快意刀法在远近
颇有些名头，因此镖局的生意还算可以。
LONG);

//        create_family("振远镖局", 1, "镖头");

        set("combat_exp", 600000);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 100);
        set_skill("dodge", 60);
        set_skill("blade", 100);
        set_skill("force", 20);
        set_skill("literate", 40);



        set("inquiry", ([
                "振远镖局" :
"是在下所创，虽忝掌封山门户，但是也不敢妄自菲薄。\n",
				"name": "在下姓陈，人称霹雳刀\n",
				"霹雳刀": "江湖上的弟兄看得起在下就这么叫开了，实在是惭愧。\n",
				"陈天星":
"哦? 他是我师叔, 他老人家在京城... 你找他? 先帮我"
"找忘忧草吧? \n",
			"忘忧草": "好象在乔阴一带吧， 唉， 记不大清了....\n",

		]) );

		setup();
        carry_object("/clone/misc/cloth")->wear();
		carry_object("/clone/weapon/gangdao")->wield();
}

