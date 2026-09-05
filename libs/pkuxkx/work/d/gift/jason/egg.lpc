#include <ansi.h>

inherit ITEM;

int isegg() {return 1;}

void create()
{
        set_name(HIC"鸡蛋"NOR, ({ "ji dan", "dan","egg" }));
        set_weight(600);
        set("unit", "个");

        set("long","这是一颗普通的鸡蛋，你可以试着孵化它。(fu)\n");
				set("time",0);
				set("value",1);
                
}
void init()
{
	add_action("do_fu","fu");
	add_action("do_eat","eat");
}

int do_eat()
{
	object pl = this_player();
	message_vision("$N敲碎鸡蛋，一口把整个生鸡蛋吞进了肚子里。\n",pl);
	switch(random(5))
	{
		case 0:
			tell_object(pl,"你感到一阵恶心。\n");
			break;
		case 1:
			tell_object(pl,"你砸吧砸吧嘴，觉得自己什么都没吃。\n");
			break;
		case 2:
			tell_object(pl,"你觉得这么吃掉一个潜在的生命真是一种罪恶。\n");
			break;
		case 3:
			tell_object(pl,"你感到肚子里好像有小鸡的叫声\n");
			break;
		case 4:
			tell_object(pl,"这个鸡蛋吃下去，你觉得神清气爽。\n");
			pl->fullme();
			if(pl->query("max_neili")<3000 && random(10) == 0)
			{
				write("似乎你的内力有了一点点提升。吃鸡蛋能涨内力？\n");
				pl->add("max_neili",1);
			}
			break;
	}
	destruct(this_object());
	return 1;
}
int do_fu(string arg)
{
	object chick;
	if(arg == "egg" || arg == "dan" || arg == "ji dan")
	{
		if(this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
		if(random(10) == 0)
		{
			message_vision("$N蹲下来，小心的用屁股捂住鸡蛋，嘴里发出咯咯咯咯咯的声音。看起来鸡蛋热乎起来了。\n",this_player());
			add("time",1);
			set("long","这是一颗普通的鸡蛋，你可以试着孵化它。(fu)\n看起来这颗鸡蛋已经孵化了"+chinese_number(query("time")/10+1)+"成了。\n");
			if(query("time") >= 100)
			{
				message_vision(HIY"一只小鸡破壳而出啦！\n"NOR,this_player());
				chick = new(__DIR__"xiaoji");
				if(environment(this_object())->isroom() != 1)
				{
					chick->move(environment(environment(this_object())));
				}
				else
				{
					chick->move(environment(this_object()));
				}
				destruct(this_object());
				return 1;
			}
		}
		else
		{
			message_vision("$N蹲下来，小心的用屁股捂住鸡蛋。但是鸡蛋毫无反应。\n",this_player());
		}
		this_player()->add_busy(5);
		return 1;
	}
	return 0;
}