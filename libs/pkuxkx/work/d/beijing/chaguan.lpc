// Room: /beijing/chaguan
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"京城茶馆"NOR);
	set("long",
CYN"	你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。茶馆正中有一座台子，一个说
书先生正起劲的说着一部《大明英烈传》。你要想打听江湖掌故和谣言，这里
是个好所在。这里有一块牌子(paizi)。\n"NOR
	);

	set("exits", ([
                "northwest" : __DIR__"tianqiao",
                "up" : __DIR__"clubpoem",
	]));

	set("objects", ([
		__DIR__"npc/huoji" : 1,
		CLASS_D("tiandihui/guanfuzi") : 1,
	]));
	set("item_desc", ([
		"paizi" : "供应清茶，每壶二十文。\n",
	]));
	set("cost", 0);
	set("day_shop", 1);
	setup();
}
void init()
{
	add_action("do_fill", "fill");
}
int do_fill(string arg)
{
	object ob, obj, me = this_player();

	if (!objectp(obj = present("huoji", environment(me))))
	{	write("掌柜的不在！\n");
		return 1;
	}

	if (!living(obj)){
		write("你还是等掌柜的醒过来再说吧。\n");
		return 1;
	}

	if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把清茶装在哪儿？\n");
		return 1;
	}

	switch (MONEY_D->player_pay(this_player(), 20)) {
        case 0: {
		write("穷光蛋，一边呆着去！\n");
		return 1;
		}
        case 2: {
                write("您的零钱不够了，银票又没人找得开。\n");
		return 1;
		}
	}

        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") +
		"倒掉。\n", this_player());
        message_vision("$N给伙计二十文铜板。\n伙计给$N的"+ob->name()+"装满清茶。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "water");
        ob->set("liquid/name", "清茶");
        ob->set("liquid/remaining", query("max_liquid"));
        ob->set("liquid/drink_func", 0);
	ob->set("liquid/drunk_apply", 4);
	return 1;
}





