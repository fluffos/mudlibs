// lian_yu.c

inherit NPC;

void create()
{
	set_name("怜玉", ({ "lian yu" }) );
	// rset short 回味轩 ji2
	set("gender", "女性" );
	set("age", 19);
	set("str", 25);
	set("per", 30);
	set("long", @LONG
她轻施粉妆，长长的睫毛低垂，一位惹人怜爱的病美人。
LONG
);
	set("class","jiyuan");
	set("combat_exp", 100);
	set("attitude", "friendly");
set("no_get",1);
	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);
set("no_get",1);
	setup();
	carry_object(__DIR__"obj/p_necklace");	
	carry_object(__DIR__"obj/hanmei_skirt")->wear();
}

void init()
{	
	object *inv;
	int i;

	::init();
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		{
		if(!inv[i]->query_temp("jiyuan/order")) continue;
		remove_call_out("greeting");
		call_out("greeting", 1, inv[i]);
		}
	add_action("do_sleep","sleep");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || !ob->query_temp("jiyuan/order")) return;
	message_vision("\n$N朝$n盈盈一福：奴家来伺候您了。奴叫怜玉(lian yu)。\n",this_object(),ob);
	message_vision("去奴的「回味轩」吧，让爷好好瞧瞧奴的光景。(accept lian yu)\n",this_object());
}

int accept_object(object who,object ob)
{
	object obj;
	if(!who->query_temp("jiyuan/shangqian") || who->query_temp("jiyuan/shangqian") != "怜玉") return 0;
	if(!ob->query("money_id")) return 0;
	if(ob->value() < 10000)
		{
		message_vision("$N说道：爷再多赏几个吧。\n",this_object());
		return 1;
		}
	if(obj = present("hong xiu",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	if(obj = present("wan xiang",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	if(obj = present("xiang yu",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	message_vision("$N高兴地说道：多谢$n大爷的赏。爷跟我来吧。\n",this_object(),who);
	who->set_leader(this_object());
	who->delete_temp("jiyuan");
	who->set_temp("jiyuan/sleep",this_object()->name());
		//command("say testtest");
	//command("go west");
	this_object()->move("/d/tianshui/ji2");
	who->move("/d/tianshui/ji2");
	call_out("can_sleeping",2,who);
	return 1;
}

void can_sleeping(object who)
{
	object mother;
	if( !who || environment(who) != environment() )
	{
	message_vision("$N叹了口气，走了。\n",this_object());
	if(mother = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
	}
	message_vision("$N满脸羞红的往床边一靠。\n",this_object());
	command("remove skirt");
	message_vision("$N低声对$n说：爷快来(sleep)吧，奴家都...等不及了。\n",this_object(),who);
	return;
}

int do_sleep(string arg)
{
	object *inv,me = this_player();
	int i;
	if(!me->query_temp("jiyuan/sleep") || me->query_temp("jiyuan/sleep") != "怜玉")
		return 0;
	message_vision("$N两眼通红，低吼一声扑向$n的胴体......\n",me,this_object());
	message_vision("$N突然觉得一阵晕眩......\n",me);
	me->delete_temp("jiyuan");
	me->unconcious();
	command("get all");
	call_out("do_dest",1,me);
	return 1;
}

void do_dest(object me)
{
	object *inv;
	int i;
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
		{
if (inv[i]->query("money_id"))
		destruct(inv[i]);
		}
	call_out("go_out",1);
}

void go_out()
{
	object mother;
	command("wear skirt");
	message_vision("$N一阵冷笑，走了出去。\n",this_object());
	if(mother = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		mother->delete_temp("have_full");
	destruct(this_object());
}

