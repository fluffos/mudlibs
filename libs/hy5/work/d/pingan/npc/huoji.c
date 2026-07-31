// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;
int ask_yaochu();

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是神针世家的一个小伙计。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/d/shenlong/obj/xionghuang",
	}));
        set("inquiry", ([
                "药锄" : (: ask_yaochu :),
                "job"  : (: ask_yaochu :),
                "yaochu":(: ask_yaochu :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_yaochu()
{
	object ob;
	ob = this_player ( ) ;
        message_vision("伙计笑道，药锄也是要钱的呢！给我一两银子我就卖给你！\n",ob);
	ob->set_temp ("药锄" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("药锄"))
	{
        message_vision("伙计对$N说：给我钱做什么？\n", who);
		return 0 ;
	}
	else
        if (present("yao chu", this_player()))
        {
         message_vision("伙计对$N说：你身上已有药锄了，不要这么贪心。\n",who);
                return 0;
        }
        else        	
	if (ob->query("money_id") && ob->value() >= 100)
	{
		message_vision("伙计给了$N药锄！\n" , who);
		this_player()->delete_temp("药锄" );
		obj=new("/quest/liandan/yaochu");
		obj->move(this_player());

	}
	return 1;
}