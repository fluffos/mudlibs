// laozhe.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("愁眉苦脸的老者", ({ "lao zhe" }) );
        set("gender", "男性");
        set("age", 67);
        set("long", "这是一位满脸皱纹的老者。\n");

	set("no_kill", 1);

	set("chat_chance", 2);
        set("chat_msg", ({
		"老者不断的叹气。。。\n",
		"老者低声叹道：这可怎么办，我怎么和孩子他爹交待呀，真愁死我了。。。\n",
}) );

	set("inquiry",([
	"叹气" : (: ask_me :),
	"忧愁" : (: ask_me :),
]));

	set("max_kee",800);
	set("max_gin",600);
	set("max_sen",600);

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob = previous_object(), master;

	if(!ob
	|| !ob->is_hs_quest_xiuxiu()
	|| !objectp(master = ob->query_my_master()))
		return;

	call_out("do_thanks",2,ob,master);
}

protected void do_thanks(object xiu, object who)
{
	object silver;

	if(!xiu
	|| (environment(xiu) != environment())
	|| !who
	|| (environment(who) != environment()) )
		return;

	who->set("quest/huashan_quest/finish", 1);
	message_vision("$N满含热泪的对$n说道：您真是我们家的救命大恩人！谢谢您啦！\n小老儿这有点积蓄，都送给大侠略表存心。\n",this_object(),who);

	silver = new(SILVER_OB);
	silver->set_amount(15);
	silver->move(this_object());
	command(sprintf("give silver to %s",who->query("id")));
	message_vision("$N感激地向$n望了一眼，朝屋里走去。\n",xiu,who);
	destruct(xiu);
}

string ask_me(object who)
{
	if( (who->query("class") != "huashan")
	|| (who->query("quest/huashan_quest/name") != "飞贼展飞熊的踪迹") )
		return "说了也没用。唉。。。。。。";

	if(who->query("quest/huashan_quest/asked_zhang"))
		return "不是和你说啦，帮不上忙就算了吧，都是我们命苦呀，唉。。。";

	who->set("quest/huashan_quest/asked_zhang",1);
	who->add("quest/huashan_quest/hint","\n      答应大同府的『老者』去『侯马集』找寻\n     『展飞熊』的贼窝，解救『秀秀』。\n");

	return "昨天晚上来了一个流氓带着一伙人，说听说我们家孙女长
得不错，非要抢走作他的压寨夫人，我拚了老命也没拦住，
我的孙女『秀秀』被他们抢走了。话中听说他们的头目叫
做『展飞熊』，平时盘踞在『侯马集』一带，这位大侠救
救我的小孙女吧。。。";
}
