#include <ansi.h>
inherit ROOM;

protected nosave mapping items = 
([
		"ak47"	:		__DIR__"obj/ak47",
		"awp"	:		__DIR__"obj/awp",
		"de"	:		__DIR__"obj/deserteagle"
]);

void create()
{
	set("short", BLU"匪徒之家"NOR);
	set("long", ""
"这里就是匪徒之家，你可以在这里购买装备，墙上贴着一张游戏规则(rule)。\n"
	);
	set("item_desc", ([
			"rule" : "作为反恐精英中的一员，你的职责就是和同伙一起消灭敌人。\n"
							"你可以在这里购买如下装备：\n"
							"ak47(1700$)\n"
							"awp(3000$)\n"
							"de(300$)\n"
							"bullets(30发)(200$)\n"
							"你的目标就是在雷区布雷，或者消灭所有敌人\n",
        ]));
	set("exits", ([
		"out" : "/d/wudang/guangchang",
	]));
	setup();	
}

void init()
{
	add_action("do_buy", "buy");
}

int do_buy(string args)
{
	object ob, me = this_player();
	object* allitem;
	int i;
	if(args == "bullets")
	{
		if(me->query_temp("cs/money") < 200)	
			return notify_fail("你的钱不够了！\n");	
		message_vision("$N买下三十发子弹。\n", me);
		me->add_temp("cs/money", -200);
		me->add_temp("cs/bullets", 30);
		tell_object(me, "你还剩下" + chinese_number(me->query_temp("cs/money")) + "CS币。\n");
		return 1;
	}	
	if(!items[args])
		return notify_fail("没有这个武器！\n");	
	ob = new(items[args]);
	if(ob->query("cs/value") > me->query_temp("cs/money"))
	{
		destruct(ob);
		return notify_fail("你的钱不够了！\n");	
	}
	//扔掉手中的枪先
	allitem = all_inventory(me);
	for(i = 0; i < sizeof(allitem); i++)
	{
		if(allitem[i]->query("cs/type") == ob->query("cs/type"))
		{
			message_vision(NOR"$N扔下一" + allitem[i]->query("unit") + allitem[i]->query("name")+"。\n", me);
			allitem[i]->move(environment(me));
			break;
		}
	}
	ob->move(this_player());
	message_vision("$N买下一" + ob->query("unit") + ob->query("name")+"。\n", me);
	me->add_temp("cs/money", -ob->query("cs/value"));
	tell_object(me, "你还剩下" + chinese_number(me->query_temp("cs/money")) + "CS币。\n");
	return 1;	
}
