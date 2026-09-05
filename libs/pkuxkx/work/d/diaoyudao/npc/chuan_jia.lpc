//chuan_jia.c  老船家
//cgbii 96.10.3
// modify by hongdou 98.09.15

inherit NPC;

int accept_object(object who, object ob);
string ask_me1();
string ask_me2();
string ask_me3();

void create()
{
        set_name("老船家", ({ "chuan jia","jia" }) );
        set("gender", "男性");
        set("age", 55);
        set("long", 
        "这老船家看上去很和善，不过现在气呼呼的好象有点不高兴。\n");
        
        set("combat_exp", 1000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set("apply/attack",  30);
        set("apply/defense", 30);
        set("chat_chance", 5);
        set("chat_msg", ({
                "那几个臭东瀛人一定是乔本龙太郎那群倭寇派来的探子。\n",
                "这帮贼家伙抢了我买给闺女的嫁妆，就没有人敢出来管管。\n",
                "我这条老命不要啦，跟这帮狗强盗拚了！\n", }) );
        
        set("inquiry",([ "钓鱼岛" :(:ask_me1:),
	      "出海" : (:ask_me2:),
              "珍珠项链" : (:ask_me3:),
              "项链" : (:ask_me3:),
	      "嫁妆" : "那是我辛辛苦苦攒钱，买了一串珍珠项链，给我女儿当嫁妆的。",
              ]));
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("shen_type",1);set("score",200);setup();
        
        carry_object(__DIR__"obj/suoyi")->wear();
}

string ask_me1()
{
return "钓鱼岛我倒是去过，那里已经被倭寇占了。看你的样子象习武之人，\n
是去打倭寇么？要去钓鱼岛可要小心，大海茫茫，随时都可能迷失方向。\n";
}

string ask_me2()
{
	if (base_name(environment(this_object())) != "/d/diaoyudao/matou1")
		return "对不起客官，我的船在泉州海港哪！\n";
    if (!(this_player()->query_temp("助")))
	return "这位客官想出海呀？我这里有船可以租给你，五十两银子，
怎么样？价钱公道吧！\n";
    else 
	{
	    message_vision("\n老船家笑着说道：“大侠帮过我，要出海，我的船您随便用！”\n",this_player()); 
	    message_vision("\n$N悠然地走进了船舱！\n",this_player());
	    this_player()->move("/d/diaoyudao/x_chuan1");
	    this_player()->set_temp("航1",1);
	    return "老船家高兴地对你道：“大侠帮助过我，要出海，我的船免费租给您！”\n"; 
	}
}

string ask_me3()
{
    if (!(this_player()->query_temp("助")))
	return "唉！我女儿的嫁妆珍珠项链被那伙强盗抢去了，怎么办啊？\n";
    else return "多谢这位大侠将我女儿的嫁妆抢回来！\n";
}



int accept_object(object who, object ob)
{
	object luopan;
//	if (!who->query_temp("助")) return 0;
 	if (ob->query("money_id") && ob->value() < 5000) 
        {   message_vision("老船家冷笑着冲$N说道：这么点钱就想租船，你还是自己留着吧。\n\n",who);
	    return 0;
	}
        if ((ob->query("money_id") && ob->value() >= 5000) ||
	    (ob = present("xiang lian", this_player())))
	{
	    if ((ob->query("money_id")) && (ob->value() >= 5000))
	    message_vision("老船家笑着对$N道：“这条船就是你的了，祝你一路顺风！”\n",who);
       
            if ((ob = present("xiang lian", this_player())))
	    {
                say(
"老船家说道：哈哈哈！您真的把我闺女的嫁妆给找回来啦，\n"
"这条船免费租给您了。还有这个东西给您，对恩公出海有帮助。\n");
		luopan=new("/d/diaoyudao/npc/obj/luopan");
		luopan->move(who);
		message_vision("老船家给了$N一个罗盘。\n",who);
		who->set_temp("助",1);
		call_out("destroy", 1, ob);
            }
            message_vision("$N走进了船舱。\n",who);
	    who->move("/d/diaoyudao/x_chuan1");
	    who->set_temp("航1",1);
            return 1;
	}
	return 0;    
}


void destroy(object ob)
{
        destruct(ob);
        return;

}
