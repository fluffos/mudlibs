string ask_for_guojing();
int ask_book();
inherit NPC;
void create()  
{	set_name("吕文德", ({ "lv wende","lv","lu" }));
	set("gender", "男性");
	set("age", 44);
	set("str", 15);
	set("dex", 16);
	set("long", "他正陶醉在温柔乡里,怀中是温香暖玉,口中是山珍海味.把国家,黎民置于脑后.\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);

	set("neili", 200); 
	set("max_neili", 200);
	set("jiali", 50);
        
        set("inquiry",([
                "郭靖"  : (: ask_for_guojing :),
				"守城录"  : (: ask_book :),
        ]));


        set("chat_chance", 10);
        set("chat_msg", ({
       "小妞,再给大爷我唱一个吧?\n"
       "郭靖那个土包子,蒙古兵都退了,还忙活什么呀?\n"
        }) );
        setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
int ask_book()
{
	object me=this_player(),book;
	if (me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}
	if (!load_object("/d/hangzhou/obj/books/book_strategy_8"))
	{
		tell_object(me,"从来没听过什么守城录。\n");
		return 1;
	}
	if ("/adm/daemons/xytaskd"->query("times")==3&&"/adm/daemons/xytaskd"->query("begin"))
	{
		if (query("given"))
		{
			tell_object(me,"守城录真不在我这啊！\n");
			return 1;
		}
		set("given",1);
		book=new("/d/hangzhou/obj/books/book_strategy_8");
		book->move(me);
		command("say 还是保命要紧啊。指挥大军就交给郭靖了。");
		message_vision("$N战战兢兢地把$n交给了"+me->query("name")+"。\n",this_object(),book);
		return 1;
	}
	else
	{
		command("say 守城录固然在我这，本帅镇守襄阳，自然需要用到这本书，你拿去有什么用？");
		return 1;
	}
}
string ask_for_guojing()
{
          return "蒙古兵都走了,郭靖还在忙什么呢?真搞不懂他.";
}



