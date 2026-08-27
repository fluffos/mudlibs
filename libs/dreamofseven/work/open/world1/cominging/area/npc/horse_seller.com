#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("周詳連", ({ "horse seller" , "seller" }) );
	set("long",
        "這是步靈城中新開的連詳馬廄\的主人，他正用心的照顧馬中。\n"
	    "你可以問問他有賣那種馬(list)，或是向他購買各種品種的馬(buy)\n"
	);
	set("level", 10);
	set("no_fight",1);
	set("age",   50);
	set("chat_chance", 1);
	set("chat_msg", ({
  (: command("say 最近真是閒呀..") :),
  (: command("sigh") :),
  (: command("say 不知道還會有客人上門否 ?") :),
}) );
	set("sell_list",([	
		__DIR__"horse": 4,
	]));
	setup();
	add_money("coin",50);
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}


int do_buy_amount()
{

}

string item_list(object ob)
{
	int b;
	b=ob->query("value");
	return sprintf(" %7d ────────  %-26s",
		b,ob->short()
		);
}

int do_list(string arg)
{
	object goods,me;
	mapping item;
	string list, *file;
	int i,*supply_cost,debug;
        
	me=this_player();

	if(wizardp(me) && me->query("env/debug")) debug=1;
		else debug=0;

        if( ! mapp( item = query("sell_list") ) )
        {
                write("這位小販沒有物品列表！\n");
                return 0;
        }

	file =  keys(item);
	supply_cost = values(item);
	list = "\n\n\n┌─────────────────────────────┐\n"
		    +"│ 馬 價                          目前可以購買的馬種清單    │\n"
		    +"└─────────────────────────────┘\n";
	for( i=0 ; i<sizeof(file) ; i++)
	{
		goods = load_object(file[i]);
		if(goods) list+= item_list(goods);
		if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
			else list+="\n";
		list +="\n";
	}
	list +="\n";
	if( i==0 ) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..貨都賣完了。\n");
	else {
		tell_object(me,"\n");
		me->start_more(list);
	}
	return 1;       
}

int do_buy(string arg)
{
	int valus,j,world;
	object goods,ob,me;
	string item,*file;
	mapping items;
	
	items = query("sell_list");
	me = this_player();

	if( arg!="horse" ) return notify_fail("你要買什麼東西？\n");

	file = keys(items);
//	int *supply_cost;
//	supply_cost = values(items);
	goods = load_object(__DIR__"horse.c");
	valus=goods->query("value");

	if( !me->can_afford( valus ) )
		return notify_fail("你身上的錢不夠。\n");

	me->receive_money(-valus);
	me->add("supply_point",-50);

	world = me->money_type();
	message_vision("$N花了 "+price_string(valus,me->money_type())+" 向$n買了一"+goods->query("unit")+goods->name()+"。\n", me , this_object() );

	ob = new(__DIR__"horse.c");
	call_out("buy1",0,me,ob);
	call_out("buy2",7,me,ob);
//	ob->move(environment(me));
	me->save();
	return 1;
}

void buy1(object me,object ob)
{
	message_vision("周詳連對$N說﹕$n是吧？請等會兒！\n",me,ob);
	message_vision("周詳連對著馬舍拉開喉嚨吆喝道：來馬！\n",me);
	return;
}

void buy2(object me,object ob)
{
	message_vision("舍中的小二一路上哼著歌把$n給牽了出來。\n"
		+"周詳連對$N說：客倌，您的$n來了！\n"
		+"周詳連把剛從的馬舍牽出來的$n到$N面前。\n"
		, me , ob );
	ob->move(environment(me));
	me->save();
	return;
}
