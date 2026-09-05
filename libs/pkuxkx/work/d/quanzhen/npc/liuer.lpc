inherit NPC;

#define MAX_NUMBER 10

void create()
{
        set_name("道长", ({ "dao zhang", "dao", }) );
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "这是一位粗旷的大汉，满脸刻着沧桑。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"horse",

        }));
	set("number",0);
        setup();
}


void init()
{
	add_action("do_buy","buy");
	add_action("do_wei","wei");
}

int do_buy(string arg)
{
	object ob,me,horse,*inv;
	int i;

	me=this_player();
	ob=this_object();

	if (ob->query("number") > MAX_NUMBER)
		return notify_fail("马已经售完了。\n");

	inv = all_inventory(environment(me));
	i = sizeof(inv);
	while(i--)
	{
		if( inv[i]->query("hoster")==me->query("id") ) 
			return notify_fail("你已经有一匹了,别贪得无厌。\n");
	}
	
	switch (MONEY_D->player_pay(me, 10000) )
	{
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		message_vision("$N从刘二那里买了一匹马。\n",me);
		ob->add("number",1);
		horse=new(__DIR__"horse");
		horse->move(environment(ob),1);
		horse->set("hoster",me->query("id"));
		horse->set_leader(me);
		return 1;
	}

	return 0;
}

int do_wei(string arg)
{
	object *inv,me;
	int i,j=-5;

	me=this_player();
	inv = all_inventory(environment(me));
	i = sizeof(inv);
	while(i--)
	{
		if( inv[i]->query("hoster")==me->query("id") ) 
		{
			j=i;
			break;
		}
	}
	if (j==-5) return notify_fail("你没马怎么喂!\n");

	switch (MONEY_D->player_pay(me, 1000) )
	{
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		message_vision("刘二对$N说道：客官稍候，我这就去把马喂好。\n",me);
		inv[j]->move(VOID_OB, 1);
		remove_call_out("weima");
		call_out("weima",10,inv[j],environment(me),me);
		return 1;	
	}
	
	return 0;
}

int weima(object ma,object env,object me)
{
	if(ma->move(env))
	{
		ma->set("times",0);
		message_vision("\n\n刘二把马牵到$N的身边，说道：马喂好了。\n",me);
		return 1;
	}

	return 0;
}
