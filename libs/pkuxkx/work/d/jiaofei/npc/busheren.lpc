// jiaofei task npc
// 捕蛇人
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("捕蛇人",  ({ "bushe ren","ren"}));       
              
        set("shen_type", 1);

        set("str", 30);
        set("gender", "男性");
        set("age", 35);
        set("per",30);
        set("long","一个捕蛇人，在这大沼泽里打摸了十几年。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "藤甲" : "我在那边的山谷里发现一个秘密的仓库，找到了几件藤甲，差点把命都丢了。\n",
                "沼泽": "身手和工具，却一样都别想在这里混。\n",
        ]));
        
        
       

        setup();

}

void init()
{
        object ob;        
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int do_list()
{
	object pl = this_player();
	int sklv = 0;
	int price = 500000000;
	if(!pl->query_skill("business"))
	{
		tell_object(pl,"捕蛇人说：我这里有硬藤甲卖，要不要来一套，防弓弩特别有效。不贵，只要五万两金子。这可是我拿命换来的。\n");
	}
	else
	{
		sklv = pl->query_skill("business")-15;
		price = price / (2*sklv);
		if(price < 2000000)
		{
			price = 2000000;
		}
		tell_object(pl,"捕蛇人被你如簧巧舌打动，同意以"+chinese_number(price)+"两金子一套的价格卖给你硬藤甲。\n");
	}
	return 1;
}

int do_buy()
{
	object pl = this_player();
	int sklv = 0;
	int price = 500000000;
	object jia;
    if(environment()->query("tianmo_book_num") <= 0)
    {
        command("say 对不起，东西已经没了。下次赶早。\n");
        return 1;
    }
	if(!pl->query_skill("business"))
	{
		
	}
	else
	{
		sklv = pl->query_skill("business")-15;
		price = price / (2*sklv);		
	}
	if(pl->query("balance") < price)
	{
		command("say 你的钱不够嘛！");
	}
	else
	{
		pl->add("balance",-price);
		jia = new("/d/jiaofei/obj/yingtengjia");
		if(!jia->move(pl))
		{
			jia->move(environment(pl));
		}
		command("say 成交，拿去吧！\n");
        environment()->add("tianmo_book_num",-1);
	}
	return 1;
}

