// 铁铲

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
string *tattoo=({
"clone/tattoo/buttock1",
	"clone/tattoo/buttock2",
	"clone/tattoo/buttock3",
	"clone/tattoo/buttock4",
	"clone/tattoo/buttock5",
	"clone/tattoo/buttock6",
	"clone/tattoo/buttock7",
	"clone/tattoo/buttock8",
	"clone/tattoo/face1",
	"clone/tattoo/face6",
	"clone/tattoo/face15",
	"clone/tattoo/face19",
});
string *box_object=({
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/27",
"item/28",
"item/29",
"item/30",
"item/31",
"item/32",
"item/33",
"item/34",
"item/35",
"item/36",
"item/37",
"item/38",
"item/39",
"item/40",
"item/41",
"item/42",
"item/43",
"item/44",
"item/45",
"item/46",
"item/47",
"item/48",
"item/49",
"item/50",
"item/51",
"item/52",
"item/53",
"item/54",
"item/55",
"item/56",
"item/57",
"item/58",
"item/59",
"item/60",
"item/61",
"item/62",
"item/63",
"item/64",
"item/65",
"item/66",
"item/67",
"item/68",
"item/69",
"item/70",
"item/71",
"item/72",
"item/73",
"item/74",
"item/75",
"item/76",
"item/77",
"item/78",
"item/79",
"item/80",
"item/81",
"item/82",
"item/83",
"item/84",
"item/85",
"item/86",
"item/87",
"item/88",
"item/89",
"item/90",
"item/91",
"item/92",
"item/93",
"item/94",
"item/95",
"item/96",
"item/97",
"item/98",
"item/99",
"item/100",
"item/101",
"item/102",
"item/103",
"item/104",
"item/105",
"item/106",
"item/107",
"item/108",
"item/109",
"item/110",
"item/111",
"item/112",
"item/113",
"item/114",
"item/115",
"item/116",
"item/117",
"item/118",
"item/119",
"item/120",
"item/121",
"item/122",
"item/123",
"item/124",
"item/125",
"item/126",
"item/127",
"item/128",
"item/129",
"item/130",
"item/131",
"item/132",
"item/133",
"item/134",
"item/135",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
});


void create()
{
	set_name(HIC"铁铲"NOR, ({"tie chan", "chan", "tiechan"}));
	set_weight(100000);
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用精钢制作而成的"+HIC"铁铲，"NOR+"似乎可以挖掘(dig)。\n"
		"如果在荒山野地，用这个"+HIC"铁铲，"NOR+"挖到(dig)宝物就好了!\n"
		"在人多的城市附近铁定是没有的。\n");
		set("unit", "把");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                set("no_put",1);
	}
}


void init()
{
   add_action("do_open","dig");
}



int do_open(string arg)
{
	int exp,pot;
    object me=this_player(),ob,env;
	env = environment(me);
	if (me->is_busy())
	{
		tell_object(me,"等你忙完了，再挖吧，！\n");
		return 1;
	}
	if( me->is_fighting() )
	{
		tell_object(me,"等打完了，再挖吧，！\n");
		return 1;
	}

	if ((me->query("jing") < 20))
	{
		tell_object(me,"你的精力不能集中，不可以挖宝！\n");
		return 1;
	}
	if ((me->query("combat_exp") < 100000 ))
	{
		tell_object(me,"你的修为太差，不能挖宝！\n");
		return 1;
	}

	if ((me->query("qi") < 30 ))
	{
		tell_object(me,"你的身体状态太差，不能挖宝！\n");
		return 1;
	}
    if(me->query("jing")<me->query("max_jing")/20 )
      return notify_fail("你的精不够了。\n");

    if(me->query("eff_jing")<me->query("max_jing")/20 )
      return notify_fail("你的精不够了。\n");

    if(me->query("qi")<me->query("max_qi")/20 )
      return notify_fail("你的气不够了。\n");

    if(me->query("eff_qi")<me->query("max_qi")/20 )
      return notify_fail("你的气不够了。\n");

	if (!env->query("outdoors"))
		return notify_fail("你打算拆屋呀？\n");

	if (env->query("no_fight"))
	{
		return notify_fail("这里不准随便挖掘。\n");
    }

	if (env->query("no_dig"))
	{
		return notify_fail("这里好像刚刚被人挖过没有宝物了!\n");
	}

	else {
        message_vision(HIC"$N蹲在地上，双手乱刨,挥动铁铲开始在地上挖了起来。\n"NOR,me);
        me->add("jing",-me->query("eff_jing")/50);
        me->add("qi",-me->query("eff_jing")/50);
        me->add("eff_qi",-me->query("max_jing")/50);
        me->start_busy(6);
	}

	if (random(7)<5)
	{
		me->start_busy(3);
        message_vision(CYN"$N挖了一阵，什么也没有找到。\n"NOR,me);
		return notify_fail("真是可惜!\n");
	}

	if (env->query("outdoors")=="city"
        ||env->query("outdoors")=="city2"
        ||env->query("outdoors")=="chengdu"
        ||env->query("outdoors")=="changan"
        ||env->query("outdoors")=="dali"
        ||env->query("outdoors")=="foshan"
        ||env->query("outdoors")=="hangzhou"
        ||env->query("outdoors")=="huanggon"
        ||env->query("outdoors")=="hg"
        ||env->query("outdoors")=="quanzhou"
        ||env->query("outdoors")=="xiangyang"
        ||env->query("outdoors")=="quanzhou"
        ||env->query("outdoors")=="pingan"
        ||env->query("outdoors")=="武馆"
        ||env->query("outdoors")=="lanzhou"
        ||env->query("outdoors")=="ruzhou"
        ||env->query("outdoors")=="fengyun"
        ||env->query("outdoors")=="yanjing"
        ||env->query("outdoors")=="japan"
        ||env->query("outdoors")=="kaifeng"
        ||env->query("outdoors")=="changan"
        ||env->query("outdoors")=="lingzhou")
	{
		me->start_busy(3);
        message_vision(CYN"$N挖了一阵，什么也没有找到, 这个地方估计找不到什么了。\n"NOR,me);
		return notify_fail("真是可惜!\n");
	}

	if(me->query("gender")=="男性")
		tell_object(me,"你迫不及待地将挖出的"+HIY+"宝物"NOR+"拿出，\n");
	else
		tell_object(me,"你小心翼翼地将挖出的"+HIY+"宝物"NOR+"拿出，\n");

    if( me->over_encumbranced() )
		return notify_fail("身上带的东西太多了，拿不动了。\n");

	env->set("no_dig",1);
	add_temp("workchan", 1);
	exp=25+random(30);
	pot=15+random(15);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	tell_object(me,"你被奖励了\n"+chinese_number(exp)+"点实战修为\n"+chinese_number(pot)+"点潜能\n");

	if(random(100)>95)
	{
        ob=new("/clone/money/gold");
        ob->set_amount(random(3)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"黄金"NOR+"。\n"NOR);
	}
	else if(random(200)>180)
	{
        me->add("eff_jing",-10);
        me->add("eff_qi",-100);
        tell_object(me,"挖出的石头划破了你的"+HIC"手"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>180)
	{
        me->add("eff_jing",-10);
        me->add("eff_qi",-100);
        tell_object(me,"挖出的石头划破了你的"+HIC"手"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("snake_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("zhizhu_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("xiezi_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(200)>198)
	{
        me->apply_condition("chanchu_poison",10);
        me->add("qi",-10);
        tell_object(me,"挖出的东西有"+HIR"毒"NOR+",你受了伤!"NOR+"。\n"NOR);
	}
	else if(random(100)>95)
	{
        ob=new("/clone/money/silver");
        ob->set_amount(random(10)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"白银"NOR+"。\n"NOR);
	}
	else if(random(100)>95)
	{
        ob=new("/clone/money/coin");
        ob->set_amount(random(20)+1);
        ob->move(me);
        tell_object(me,"发现了一些"+HIY"铜钱"NOR+"。\n"NOR);
	}
	else if(random(100) == 1)
	{
		ob = new(random(sizeof(tattoo)));
		ob->move(me);
		tell_object(me,"发现了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
	}
	else
	{
		int rand;
		rand=random(sizeof(box_object));
		ob=new(__DIR__+box_object[rand]);
		if(random(201)==199)
		{
			message_vision(HIY "$N挖到了一个亮晶晶的宝石!!\n" NOR,me);
			ob=new("/clone/gem/gem");
			if (ob->query("level") >4)
			{
				ob=new("/clone/gem/gem");
			}
			if (ob->query("level") >4)
			{
				ob=new("/clone/gem/gem");
			}
			ob->move(me);
		}

		if(ob)
		{
			ob->move(me);
			tell_object(me,"发现了"+HIY":"+ob->query("name")+"."NOR+"。\n"NOR);
		}
		else
			tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
	}

	if ( query_temp("workchan") > 12)
	{
		message_vision(HIG"铁铲已经挖坏了!\n"NOR,me);
        destruct(this_object());
	}
	return 1;
}