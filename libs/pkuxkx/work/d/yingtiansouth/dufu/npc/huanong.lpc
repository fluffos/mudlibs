inherit NPC;

void create()
{
	set_name("花农", ({ "hua nong", "hua","nong" }));
	set("gender", "男性");
	set("age", random(20) + 40);
	set("str", 10);
	set("dex", 10);
	set("long", "他是一名都府里的长期聘用的花农，正在收拾着花草。\n");
	set("combat_exp", 12000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 15);
	set_skill("force", 10);
	set_skill("dodge", 15);
	set_skill("parry", 20);
	set("chat_chance", 1);
	set("chat_msg", ({
				this_object()->name()+"叹了口气，继续干活。\n",
                //(:askforhelp:),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth_puren")->wear();
}

