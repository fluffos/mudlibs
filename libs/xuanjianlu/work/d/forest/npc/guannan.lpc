//Cracked by Roath
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("袁冠男", ({ "yuan guannan", "yuan", "guannan" }) );
        set("gender", "男性" );
	set("title", "书生");
        set("age", 24);
        set("long", 
	     "他长脸俊目，剑眉横飞，容颜间英气逼人。\n");
        set("str", 30);
        set("dex", 30);
        set("con", 27);
        set("int", 35);
        set("shen_type", 1);

	set_skill("blade",70);
        set_skill("unarmed", 70);
        set_skill("force", 60);
        set_skill("dodge", 75);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
	set("max_neili",800);
	set("jiali",20);

        set("combat_exp", 50000);

        set("attitude", "friendly");

	setup();

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	  "袁冠男叫道『女貌郎才珠万斛』\n",
	  "袁冠男使一招『天教丽质为眷属』\n",
	  "『清风引佩下瑶台』！袁冠男的刀飒飒生风\n",
	  "袁冠男道：『明月照妆成金屋』！\n",
	  "袁冠男使一招「喜结丝罗在乔木」\n",
	  "袁冠男道：「英雄无双风流婿」\n",
          "袁冠男道：「却扇洞房燃花烛」\n",
          "袁冠男道：「碧箫声里双鸣凤」\n",
          "袁冠男道：「今朝有女颜如玉」\n",
          "袁冠男叫道：「千金一刻庆良宵」\n",
          "袁冠男叫道：「占断人间天上福」\n",
          "袁冠男叫道：刀光掩映孔雀屏」\n",
	}));

        set("chat_chance", 5);
        set("chat_msg", ({
             "袁冠男长声吟道：「黄金逐手快意尽，昨日破产今朝贫，丈夫何事空啸傲？不如烧却头上巾……」\n",
	}));
        carry_object("/d/city/obj/cloth")->wear();
	if (clonep()) 
	carry_object("/clone/unique/yuandao", "/clone/weapon/gangdao")->wield();
	add_money("gold",1);
}

int accept_kill()
{
	object wife;

	if (wife=present("xiao zhonghui", environment(this_object()))) {
		remove_call_out("killhim");
		call_out("killhim",1,wife, this_player());
	}
	return 1;
}

void killhim(object wife, object badguy)
{
	message_vision("$N大吼一声：「休要伤我相公！」\n",wife);
	wife->kill_ob(badguy);
}
