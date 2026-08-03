// xian. 冼老板

inherit NPC;

string get_rumors();
string ask_mao18();
void create()
{
	set_name("冼掌柜", ({ "xian zhanggui", "xian", "zhanggui" }));
	set("title", "瘦西湖酒馆老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "洗掌柜经营祖传下来的瘦西湖酒馆已有多年。\n");
	set("combat_exp", 2000);
	set("inquiry", ([
		"name" : "客官您客气什么，叫小的冼掌柜就好。",
                "rumors" : (: get_rumors() :),
                "茅十八" : (: ask_mao18() :),
		"here" : "这里是扬州呀，客官您竟然不知道？",
		"扬州" : "这里就是扬州呀，客官您这不是骑着毛驴找毛驴吗？",
		"桃花岛": "听说是东海上的小岛，往杭州的东南走，到海边看能不能雇船吧？",
		"寒雨": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"jpei": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"生意" : "这里地处瘦西湖边，生意好得很。",
	]) );
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	setup();
}

void init()
{	
}

string get_rumors()
{
        object me = this_player();

        me->set_temp("mao18/jg_pass1",1);
        return "听说有个江洋大盗叫什么十八的越狱了，官府正在捉拿。";
}

string ask_mao18()
{
        object me = this_player();

        if (!me->query_temp("mao18/jg_pass1"))
                return ;
        if (!me->query_temp("total_pay"))
                return "您既然不是吃饭的客人，就不要在这里瞎打听了。";
        me->delete_temp("mao18/jg_pass1");
        me->set_temp("mao18/jg_pass",1);
        return "对，就是茅十八。听说那个江洋大盗躲到丽春院快活去了，也不知道是不是真的。";
}
int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "冼掌柜忙不迭地笑道：“客官您又不欠小店的钱，就别拿老头儿寻开心了。”\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "冼掌柜说道：“客官您先结帐(pay)再付款。”\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("冼掌柜满脸堆着笑，冲$N哈腰道：“谢客官您啦，走好。”\n", who);
			else message_vision("冼掌柜满脸堆着笑，冲$N哈腰道：“谢客官您的小费，老儿不客气就收下了，您走好。”\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("冼掌柜对着$N说道：“不够！还差" + chinese_number(pay) + "文。”\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现冼掌柜躲在高高的柜台后面，够不到。\n", ob);
}

void unconcious()
{
	say( "冼掌柜大喊一声：“我不行了，快来救我！”\n");
	say( "结果从柜台后面钻出一个小童来，往冼掌柜的嘴力塞了一个药丸就走了。\n");
	say( "片刻之间，冼掌柜又恢复了精神，“嘿嘿”奸笑了两声。\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

