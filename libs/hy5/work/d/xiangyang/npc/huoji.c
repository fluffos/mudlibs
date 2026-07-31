// huoji. 铁匠铺伙计

inherit NPC;
int ask_yaochu();

void create()
{
	set_name("铁匠铺伙计", ({ "tiejianpu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是被官府征用来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
        set("inquiry", ([
                "铁铲" : (: ask_yaochu :),
                "job"  : (: ask_yaochu :),
                "tiechan":(: ask_yaochu :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int ask_yaochu()
{
	object ob;
	ob = this_player ( ) ;
        message_vision("伙计笑道，铁铲也是要钱的呢！给我二十两银子我就卖给你！\n",ob);
	ob->set_temp ("铁铲" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("铁铲"))
	{
        message_vision("伙计对$N说：给我钱做什么？\n", who);
		return 0 ;
	}
	else
        if (present("tie chan", this_player()))
        {
         message_vision("伙计对$N说：你身上已有铁铲了，不要这么贪心。\n",who);
                return 0;
        }
        else        	
	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("伙计给了$N铁铲！\n" , who);
		this_player()->delete_temp("铁铲" );
		obj=new("/clone/box/tiechan");
		obj->move(this_player());

	}
	return 1;
}