inherit NPC;

void create()
{
        set_name("营门守将", ({ "shou jiang","jiang" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", 
            "他顶盔冠甲，好不威风！\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 80);
        set_skill("dodge", 65);
        set_skill("blade", 85);    
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 50000);

        set("attitude", "peaceful");
        set("inquiry", ([
            "皇帝" : "大汗就在里面的金帐里，不过如果你没什么事的话,我可不能防你进去.",
            "蒙古皇帝" : "大汗就在里面的金帐里，不过如果你没什么事的话,我可不能防你进去.",
            "大汗" : "大汗就在里面的金帐里，不过如果你没什么事的话,我可不能放你进去.",
         ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "大汗每天忙于军务，经常外出，不知现在在不在。\n",
        }) );
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
}

void init()
{
        object me,ob;
        ::init();
        me=this_object();
        add_action("do_answer","answer");      
        if (this_player()->query_temp("杀")){ 
          command("haha");
          command("kill " + this_player()->query("id"));
        }
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
                command("haha");
                this_player()->set_temp("杀",1);
	}
}





int do_answer(string arg)
{
        object me;

        me = this_player();
        if (!this_player()->query_temp("进门")) {
           write("我又不是你师傅，你用不着回答我。\n");
           return 1;
        }


	  if(arg=="送信"){
        this_player()->set_temp("请进",1);
        command("say 既是大汗的使者，请进请进。\n");
          return 1;
        }
           else {
        command("say 什么乱七八糟的？这里是军营重地，速速离去，否则格杀勿论！！");
          return 1;
        }
        
}

   
