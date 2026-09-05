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

         set("count",20);

          set("count2",10);

         set("no_get",1);

        set("inquiry", ([

                "铁铲" : (: ask_yaochu :),

                "job"  : (: ask_yaochu :),

                "tiechan":(: ask_yaochu :),

        ]));



	set("shen_type",1);set("score",200);setup();

	carry_object("/clone/misc/cloth")->wear();

}





int ask_yaochu()

{
	object ob;
	ob = this_player ( ) ;

	if (query("count") > 0 )
	{
         message_vision("伙计笑道，铁铲也是要钱的呢！给我十两银子我就卖给你！\n",ob);
		ob->set_temp ("铁铲" , 1 );
		return 1;
	}   
	else
	if (query("count") < 1 && query("count2") > 0)
	{
        message_vision("伙计对$N说：我的铁铲已经卖完了。\n不过如果你给我一两黄金,我可以把我自己的给你。\n",ob);
        ob->set_temp("铁铲2",1);
        return 1;	

	}
	else
	if (query("count2") < 1 && query("count") < 1)
	{
         message_vision("伙计对$N说：我自己都没有铁铲了。\n",ob);
         return 1;	

	}


}



int accept_object(object who, object ob)

{
	object obj ;
    if (!(int)who->query_temp("铁铲") && !(int)who->query_temp("铁铲2"))
	{
        message_vision("伙计对$N说：给我钱做什么？\n", who);
		return 0 ;
	}
	else
        if (present("tie chan", this_player()) )
        {
         message_vision("伙计对$N说：你身上已有铁铲了，不要这么贪心。\n",who);
         return 0;
        }
    else 
		if (query("count2") < 1 && query("count") < 1)
	{
         message_vision("伙计对$N说：我自己都没有铁铲了。你给我钱也没有用。\n",who);
         return 0;	
	}
    else
		if (this_player()->query("combat_exp") < 200000)
	{
         message_vision("伙计对$N说：你经验不足，拿着铁铲也没用。\n",who);
         return 0;	
	}
	else        	
        if (ob->query("money_id") && ob->value() >= 1000 && who->query_temp("铁铲"))
	{
		message_vision("伙计给了$N铁铲！\n" , who);
		this_player()->delete_temp("铁铲" );
		obj=new(__DIR__"obj/tiechan");
		obj->move(this_player());
		add("count",-1);
        return 1;
	}
    else 
                if (ob->query("money_id") && ob->value() >= 10000 && who->query_temp("铁铲2"))
        {
		message_vision("伙计给了$N铁铲！\n" , who);
        this_player()->delete_temp("铁铲2" );
		obj=new(__DIR__"obj/tiechan");
		obj->move(this_player());
        add("count2",-1);
		return 1;
		}
	else
	{
        message_vision("伙计对$N说：我不要你的破烂东西。\n",who);
		return 0;
	}

}

