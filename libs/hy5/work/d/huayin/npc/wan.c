// wan.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("万明仁", ({ "wan ming ren" }) );

	set("gender", "男性" );
	

	set("age", 35);
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 100);

	set("long", "这是一个专管培育药材的商人万明仁。\n");
	

        set("combat_exp", 800000);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("inquiry",([
	"工具" : (: ask_me :),
	"药苗" : (: ask_me :),
	"栽种" : (: ask_me :),
]));

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	carry_object("/clone/misc/cloth")->wear();  
}

string ask_me(object who)
{
	object ob;

	if(  (who->query("quest/huashan_quest/name") != "药苗") )
		return 0;

	if(who->query("quest/huashan_quest/wan_give"))
		return "东西不是都给了你了，赶紧去种吧。";

	if(!ob = present("shui piao",who))
	{
		ob = new(__DIR__"obj/piao");
		if(!ob->move(who))
		{
			ob->move(environment());
			message_vision("$N将一个水瓢放在地上。\n",this_object());
		}
		else
			message_vision("$N给$n一个水瓢。\n",this_object(),who);
	}

	ob = new(__DIR__"obj/huafei");
	if(!ob->move(who))
	{
		ob->move(environment());
		message_vision("$N将一块花肥放在地上。\n",this_object());
	}
	else
		message_vision("$N给$n一块花肥。\n",this_object(),who);

	who->set("quest/huashan_quest/wan_give",1);

	return "赶紧去种吧，迟了就来不及了。";
}

int accept_object(object who, object ob)
{
	if(!ob->is_yao_miao() || !ob->is_success())
		return 0;

	if(  (who->query("quest/huashan_quest/name") != "药苗") )
		return 0;

	who->set("quest/huashan_quest/finish",1);

	if(find_call_out("do_dest") == -1)
		call_out("do_dest",1);
	return 1;
}

protected void do_dest()
{
	object *inv = all_inventory(this_object());

	inv = filter_array(all_inventory(this_object()),(: !$1->query("equipped") :));

	if(sizeof(inv))
		foreach(object ob in inv)
			destruct(ob);
}
