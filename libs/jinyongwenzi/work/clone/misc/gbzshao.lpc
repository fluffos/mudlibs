//笛子 /clone/misc/gbzshao.c
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;

void create()
{
        seteuid(getuid());
	set_name(HIM"笛子"NOR, ({ "di zi"}) );
	set("long", HIM"这是一个训练蛇的笛子。\n"NOR);
        set("unit","个");
        set("no_get", 1);
        set("no_drop", 1);
        set("material", "steel");
        set_weight(1);
        setup();
}

void init()
{
	object me=this_player();
	
	if (environment() != me) return;
	add_action("do_tame","tame");  //驯服自己的蛇
	add_action("do_play","play");  //增加蛇的友善
	add_action("do_aggress","aggress"); //增加蛇的凶残
	add_action("do_ambush","fuji"); //命令蛇伏击id
}

int query_autoload()
{
	return 1;
}

int do_tame(string arg)
{
	object me,snake;
	string msg;

	if (arg!="snake" && arg!="she")
		return notify_fail("你要驯服谁？\n");
		
	me = this_player();

	snake = present("snake",environment(me));

	if (!snake) return notify_fail("你四下望了望，发现四周并没有什么蛇！\n");
	
	if (snake->query_temp("owner")==me->query("id")) return notify_fail("你的蛇已经驯服了。\n");

	if (!me->query_temp("tame"))
	{
		switch (random(5))
		{
			case 0 : msg=HIY"$N走上前去，小心翼翼地摸了一下$n的身体。\n"NOR;break;
			case 1 : msg=HIR"$N转到$n的后面，轻轻拍了拍$n的尾巴。\n"NOR;break;
			case 2 : msg=HIG"$N伸出一只手，似乎想和$n握握手。\n"NOR;break;
			case 3 : msg=HIM"$N伸出双手，捏住自己的鼻子和下巴，对着$n做了一个鬼脸。\n"NOR;break;
			case 4 : msg=HIB"$N冲上前去，紧紧握住$n的尾巴。\n"NOR;break;
		}
		message_vision(msg,me,snake);
		if (random(20)==18)
		{
			me->set_temp("tame",1);
			message_vision("$N发现事情不妙了，$N的蛇突然摆了摆尾巴，然后对着$N就扑了下来！\n",me);
			snake->kill_ob(me);
			message_vision(HIR"看起来$N的蛇想杀死$N"NOR,me);
			return 0;
		}	
		else 
		{
			message_vision(BLU"$n瞪了$N一眼，转过头去不理$N。\n"NOR,me,snake);
			return 0;
		}
	}
	else
	{
		if (snake->is_fighting(me))
		{
			me->add_temp("tame",1);
			if (random(me->query_temp("tame",1))>=5 )
			{
				snake->remove_killer(me);
				me->remove_killer(snake);
				snake->set_leader(me);
				snake->set_temp("owner",me->query("id"));
				message_vision(HIY"突然$n向后一跳，不和$N打了！\n"NOR,me,snake);
				message_vision(HIM"$n爬到$N脚下，用尾巴轻轻蹭了蹭$P的脚！\n"NOR,me,snake);
				me->delete_temp("tame");
				me->set("snake/friendly",50);
				me->set("snake/aggress",50);
	                        return 1;
			}
			else 
			{
				message_vision(HIW"$N向后一跃，试图跳出战圈，但是$n似乎并没有这个意思，继续攻击$P。\n"NOR,me,snake);
				me->add("jingli",-10);
				me->add("qi",-10);
				me->start_busy(random(4));
				return 0;
			}
		}
		else return 0;
	}
}	

int do_play(string arg)
{
	object me,snake;
	
	if (!arg || arg!="snake" && arg!="diao")
		return notify_fail("你要和谁玩？\n");
	
	me = this_player();
	snake = present("snake",environment(me));
	
	if (!snake) return notify_fail("你的蛇在哪里呢？\n");
	
	if (me->query("snake/aggress")>2) me->add("snake/aggress",-2);
	if (me->query("snake/friendly")<100) me->add("snake/friendly",1);
	
	message_vision(HIB"$N掏出笛子，轻轻吹奏起来，$N的蛇听见笛声，身体竟然随着节拍扭动起来。\n"NOR,me);
	me->add("jingli",-50);
	me->start_busy(2);
	return 1;
}

int do_aggress(string arg)
{
	object me,snake,ji;
	
	if (!arg || arg!="snake" && arg!="diao")
		return notify_fail("你要做什么？\n");

	me = this_player();

	ji = present("gong ji",me);
	snake = present("snake",environment(me));
	
	if (!snake) return notify_fail("你的蛇呢？\n");
	if (!ji) return notify_fail("你的训练方法好像不得要领！\n");

	if (random(10)>6 )
	{
		if (me->query("snake/aggress")>100) me->add("snake/aggress",1);
		if (me->query("snake/friendly")<2) me->add("snake/friendly",-2);
	
		message_vision(HIR"蛇扑向$N身上的$n，三下两下就吃了个干干净净。\n"NOR,me,ji);
		destruct(snake);
		me->add("jingli",-50);
		me->start_busy(2);
	}
	else
		message_vision(HIR"看起来$N的蛇对$n不太感兴趣。\n"NOR,me,ji);
	return 1;
}

int do_ambush(string arg)
{
	object ob,me,snake;
	
	if (!arg)
		return notify_fail("你要蛇攻击谁？\n");

	me = this_player();
	
	snake = present("snake",environment(me));
	
	if ( !snake || !snake && snake->query_temp("owner")!=me->query("id") ) return notify_fail("你的蛇呢？\n");
	
	if (arg==me->query("id")) return notify_fail("你发疯了么？用自己的蛇攻击自己？\n");
	
        ob =find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要伏击的人好像不在!\n");
	
	tell_object(me,HIR"你要蛇埋伏在这里，准备伏击名为"+ob->query("name")+"的人。\n"NOR);
	snake->set_temp("ambush",ob->query("id"));
	snake->set_leader(0);	
	return 1;
}
