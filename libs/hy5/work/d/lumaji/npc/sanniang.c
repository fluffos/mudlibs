// sanniang.c

#include <ansi.h>


inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("徐三娘", ({ "san niang" }) );
	set("title","杂货店主人");
        set("gender", "女性" );
        set("age", 35);
        set("long","徐三娘正微笑着看着你。\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"徐三娘说道：“排云寨的大王人道是不错，从来不欺负咱们小老百姓。”\n"NOR,
		CYN"徐三娘说道：“每年春天这最热闹，各地的马贩子都要来。”\n"NOR,
		CYN"徐三娘说道：“好在这里京城不远，打一点野味去卖也能挣不少。”\n"NOR,
}));

	set("vendor_goods", ({
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
		"/clone/misc/chema",
	}));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(1==2)
	{
		
		say( (time > 480) ? CYN"这么晚的天，您一定是刚赶到，先来几个包子垫垫饥吧。\n"NOR
			: ( (time <= 60) ? CYN"大清早的您这是要赶路吧，买几个包子带在路上。\n"NOR
			: CYN"徐三娘了个哈嗤说道：客官需要什么？咱这都是现成的。\n"NOR ) );
		return;
	}
	else
		say( CYN"徐三娘笑咪咪地说道：客官请进，尝尝小店自酿的酒。\n"NOR);
}