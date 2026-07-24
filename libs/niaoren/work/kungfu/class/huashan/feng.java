// feng.c 風清揚

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("風清揚", ({ "feng qingyang", "feng", "qingyang" }));
	set("long", 
"他就是華山劍宗的長老風清揚。他身材瘦長，眉宇間一直籠罩著一股淡淡的憂傷\n"
"神色，顯然對當年的劍宗氣宗之爭一直難以忘懷。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jiali", 200);

	set("combat_exp", 1750000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 170);
	set_skill("fanliangyi-dao", 180);
        set_skill("huashan-sword", 200);
	set_skill("hunyuan-zhang", 170);
        set_skill("lonely-sword", 200);
        set_skill("feiyan-huixiang",160);
 	set_skill("literate", 120);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "lonely-sword");
        map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("華山派", 12, "弟子");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.po2" :),
                (: perform_action, "sword.po3" :),
                (: perform_action, "sword.po4" :),
                (: perform_action, "sword.po5" :),
                (: perform_action, "sword.po6" :),
                (: perform_action, "sword.po7" :),
                (: perform_action, "sword.po8" :),
                (: perform_action, "sword.po9" :),
                (: perform_action, "strike.hu1" :),
                (: perform_action, "cuff.po1" :),
                (: exert_function, "re1" :),
                (: exert_function, "p" :),
        }) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	temp = read_file("/kungfu/class/huashan/FENG", 1, 1);
	student_num = atoi(temp);

	line = "風清揚說道：“我現在共有" + temp + "個徒弟。”\n";
	write(line);

    if ( ob->query("int") < 10)
    {
        command("say 也不知道你是真聰明還是假聰明，可是總訣三千字你背不下來。");
        command("sigh");
        return;
    }
	if ( student_num == 3)
	{
		command("say 你來晚了，我已經收了三個徒弟了。");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "華山派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名師指點，何必又來拜老朽呢？");
		return;
	}

    if (((int)ob->query_skill("sword",1) < 80) || ((int)ob->query_skill("huashan-sword",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的華山劍法還沒學到家吧。");
		return;
	}
    if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功\還沒學到家吧。");
		return;
	}
    if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
	{
        command("say 我看" + RANK_D->query_respect(ob) + "的飛燕回翔還沒學到家吧。");
		return;
	}
    if ( (int)ob->query_skill("literate",1) < 100)
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的讀書識字還沒學到家吧。");
		return;
	}

    if ((int)ob->query("shen") < 50000)
	{
		command("say 我華山派乃是堂堂名門正派，對弟子要求極嚴。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否還做得不夠？");
		return;
	}

    if ((int)ob->query_int() < 20) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的資質似乎不適合學我獨孤九劍？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	write_file("/kungfu/class/huashan/FENG", temp, 1);
}
