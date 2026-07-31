// zhang. 张老板

inherit NPC;

void create()
{
	set_name("张掌柜", ({ "zhang zhanggui", "zhang", "zhanggui" }));
	set("title", "岳候酒馆老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "张掌柜来这里开酒馆还没有多长时间。\n");
	set("combat_exp", 2000);
	set("inquiry", ([
		"name" : "客官您客气什么，叫小的张掌柜就好。",
		"rumors" : "听说有个江洋大盗叫什么十八的越狱了，官府正在捉拿。",
		"here" : "这里是岳候镇呀，客官您竟然不知道？",
		"岳候镇" : "这里就是岳候镇呀，客官您这不是骑着毛驴找毛驴吗？",
		"桃花岛": "听说是东海上的小岛，往杭州的东南走，到海边看能不能雇船吧？",
		"生意" : "这里人一天比一天多，生意好得很。",
	]) );
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "张掌柜忙不迭地笑道：“客官您又不欠小店的钱，就别拿老头儿寻开心了。”\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "张掌柜说道：“客官您先结帐(pay)再付款。”\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("张掌柜满脸堆着笑，冲$N哈腰道：“谢客官您啦，走好。”\n", who);
			else message_vision("张掌柜满脸堆着笑，冲$N哈腰道：“谢客官您的小费，老儿不客气就收下了，您走好。”\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("张掌柜对着$N说道：“不够！还差" + chinese_number(pay) + "文。”\n", who);
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
	message_vision("$N沮丧地发现张掌柜躲在高高的柜台后面，够不到。\n", ob);
}

void unconcious()
{
	say( "张掌柜大喊一声：“我不行了，快来救我！”\n");
	say( "结果从柜台后面钻出一个小童来，往张掌柜的嘴力塞了一个药丸就走了。\n");
	say( "片刻之间，张掌柜又恢复了精神，“嘿嘿”奸笑了两声。\n");
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

