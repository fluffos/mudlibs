// yamen_police.c

inherit NPC;

void create()
{
     string *surname=({"慕容","西门","公孙","上官","南宫","欧阳","司徒","紫云","流星",});
     set_name(surname[random(sizeof(surname))]+"巡捕", ({ "xun bu","police"}) );
     set("gender", "男性" );
     set("age", 25);
     set("str", 85);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long",@LONG
巡捕个个身手矫健，强盗、山贼无不闻风丧胆。
LONG
);
     set("status","patrol");
     set("CatchWho",0);
     set("combat_exp", 20000000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);
     set("chat_msg_combat", ({
                            "巡捕说道：你想干什么? 还不跟我去县衙受审!?\n",
                            "巡捕说道：大胆! 居然敢当街拒捕! 想造反？\n",
                            "巡捕手中的刀越砍越快，让你应接不暇。\n",
                            "巡捕说道：别胡闹了，还是乖乖的跟我走吧。\n"
                            }) );
     set ("inquiry",([
                "bribery":
"说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？\n"+
"收起你的钱吧！\n",
                "salary":
"哎，老爷俸银微薄，我们的年饷自然更少了......\n",
                "money":
"说实在的，我也想要钱。但要是让老爷知道了我收受贿赂(bribery)，\n不死也得扒层皮\n
",
                        ]));
     set ("chat_chance",99);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      (: random_move :)

                      }) );
     set("pursuer",1);
     set_skill("blade", 400);
     set_skill("parry", 400);
     set_skill("dodge", 400);
     set_skill("unarmed", 400);
     set_skill("force", 400);
	 set("neili", 18000); 	 
	 set("max_neili", 18000);
	 set("jiali", 250);
     setup();
     carry_object("/clone/weapon/gangdao")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("follow_ob", 1, ob);
		call_out("kill_ob", 1, ob);
	}
}
