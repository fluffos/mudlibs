// Room: /city/chaguan.c

inherit ROOM;
inherit F_SAVE;

#include <ansi.h>
string look_paizi();
string query_save_file()
{
	return "/log/quest/lottery";
}

mapping lottery;

void create()
{
	restore();
	if (!mapp(lottery))
		lottery = ([ ]);
	set("short", "茶馆");
	set("long", @LONG
这是扬州城南的一家茶馆。一走进来，就闻到一股茶香沁入心脾，你的精
神为之一爽。几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。
壁上挂了一幅字贴(zitie) 。茶馆中有一说书之人，讲述三国志、水浒传、大
明英烈传等等英雄故事。茶博士正在吆喝着招呼客人, 递茶送水, 忙的不亦乐
乎。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("item_desc", ([
		"zitie" : HIC"\t\n十年一觉扬州梦，赢得青楼薄幸名。\n"NOR,
		"paizi": (: look_paizi :),
	]));
	set("objects", ([
		__DIR__"npc/boshi" : 1,
		__DIR__"npc/shuren" : 1,
	]));

	setup();
}
/*
暂时关闭，后面重新改进
void init()
{
	if ( wiz_level(this_player()) >= 5 )
		add_action("do_set", "game");
	add_action("do_ling", "draw");
	add_action("do_dui", "exchange");
}
*/
string help()
{
	return 	"game start					开始领取奖券\n"+
		"game close					中止领取奖券\n"+
		"game number <数字> <数字> <数字> <数字>         设置中奖号码(4位)\n"+
		"game name <名称>				设置中奖标记\n";
}

int do_set(string arg)
{
	object me = this_player();
	int a, b, c, d;
	string str, msg, *type;

	if ( ! arg ) return notify_fail(help());

	if ( arg == "start") {
		if ( ! lottery["number"] )
			return notify_fail("你还没有设置本次中奖的号码！\n");
		if ( ! lottery["name"] )
			return notify_fail("你还没有设置本次中奖的标记。\n");
		lottery["set"] = 1;
		msg = "抽奖活动现在开始！\n";
	}
	else if ( arg == "close") {
		if ( lottery["set"] != 1) 
			return notify_fail("抽奖活动又没开始，你结束什么？\n");
		lottery["set"] = 0;
		msg = "抽奖活动现在结束！\n";
	}
	else if ( sscanf(arg, "number %d %d %d %d", a, b, c, d) == 4) {
		if ( a > 9 || b > 9 || c > 9 || d > 9)
			return notify_fail("每位数只能是个位数。\n");
		if ( a == b || a == c || a == d || b == c || b == d || c == d)
			return notify_fail("每位数不能相同。\n");
		type = ({ chinese_number(a) }) + ({ chinese_number(b) }) + ({ chinese_number(c) }) + ({ chinese_number(d) });
		lottery["type"] = type;
		lottery["number"] = chinese_number(a) + chinese_number(b)+ chinese_number(c)+ chinese_number(d);
		msg = "本次抽奖，数值设定为「"+ lottery["number"] +"」\n";
	}
	else if ( sscanf(arg, "name %s", str) == 1){
		lottery["name"] = str;
		msg = "本次抽奖标记为「"+ str+"」。\n";
	}
	else msg = help();

	save();
	tell_object(me, msg);
	return 1;
}


mixed get_number(object me)
{
	string *numbers=({"零","一","二","三","四","五","六","七","八","九"});
	int x, i, j = sizeof(numbers);
	string num, str, *num_type;


	for ( x = 0; x < 4 ; x ++ ) {
		num = numbers[random(j)];
		num_type = me->query("lottery/type");

		if ( ! sizeof( num_type)) {
			me->set("lottery/type", ({ num }) );
			str =  num;
		}
		else {
			for ( i = 0; i < j ;i ++) {
				if (member_array( num, num_type) != -1)
					num = numbers[i];
			}
			me->set("lottery/type", num_type + ({ num }) ); 
			str += num;
		}
	}
	return str;
}

int do_ling()
{
	object ob, me = this_player();
	string str;

	if ( me->query("registered") < 3 ) {
		tell_object(me, "只有正式用户才能领取奖券。\n");
		return 1;
	}

	if ( lottery["set"] != 1) {
		tell_object(me, "抽奖活动已经结束了。\n");
		return 1;
	}

	if ( me->query("lottery/name") == lottery["name"]) {
		tell_object(me, "你不是已经领取过奖券了么？\n");
		return 1;
	}

	me->delete("lottery");
	str = get_number(me);
	me->set("lottery/name", lottery["name"]);
	me->set("lottery/time", time());
	me->set("lottery/number", str);
	ob = new(__DIR__"obj/lottery_paper");
	ob->set("lottery_number", str);
	ob->move(me);
	message_vision(HIY"$N随意抽取了一张兑奖券，不用仔细看，就能看到下面写着一些号码。\n"NOR, me);
	return 1;
}

int do_dui()
{
	object ob, me = this_player();
	int i, j;
	string num, *num_type;

	ob = present("duijiang quan", me);
	num = me->query("lottery/number");
	num_type = me->query("lottery/type");

	if ( ! num ) 
		return notify_fail("你都没有领取奖券，来兑什么奖啊？\n");

	if ( me->query("lottery/finish"))
		return notify_fail("你不是已经兑过奖了么，怎么还来？\n");

	if ( ob && !me->query_temp("lottery_look"))
		return notify_fail("你连奖券看都不看，就来兑奖啊？\n");

	if ( num == lottery["number"])
		i = 5;
	else {
		for ( j = 0; j < sizeof( num_type); j ++)
			if (member_array(num_type[j], lottery["type"]) != -1)
				i ++;
	}
	switch (i) {
		case 5:	
			me->add("combat_exp", 50000);
			me->add("potential", 2000);
			me->add("balance", 10000000);
			me->add("max_neili", 100);
			me->add("max_jingli", 100);
			tell_object(me, HIR"恭喜您中了特等奖。\n");
			tell_object(me, "您获得了五万点实战经验、二千点潜能、一千锭黄金、一百点最大内力、一百点最大精力。\n"NOR);
			break;
		case 4:	
			me->add("combat_exp", 25000);
			me->add("potential", 1000);
			me->add("balance", 5000000);
			me->add("max_neili", 50);
			me->add("max_jingli", 50);
			tell_object(me,	HIR"恭喜您中了一等奖。\n");
			tell_object(me, "您获得了二万五千点实战经验、一千点潜能、五百锭黄金、五十点最大内力、五十点最大精力。\n"NOR);
			break;
		case 3:	
			me->add("combat_exp", 10000);
			me->add("potential", 500);
			me->add("balance", 3000000);
			me->add("max_neili", 20);
			me->add("max_jingli", 20);
			tell_object(me, HIR"恭喜您中了二等奖。\n");
			tell_object(me, "您获得了一万点实战经验、五百点潜能、三百锭黄金、二十点最大内力、二十点最大精力。\n"NOR);
			break;
		case 2:	
			me->add("combat_exp", 5000);
			me->add("potential", 200);
			me->add("balance", 2000000);
			me->add("max_neili", 10);
			me->add("max_jingli", 10);
			tell_object(me, HIR"恭喜您中了三等奖。\n");
			tell_object(me, "您获得了五千点实战经验、二百点潜能、二百锭黄金、十点最大内力、十点最大精力。\n"NOR);
			break;
		case 1:	
			me->add("combat_exp", 3000);
			me->add("potential", 100);
			me->add("balance", 1000000);
			tell_object(me, HIR"恭喜您中了四等奖。\n");
			tell_object(me, "您获得了三千点实战经验、一百点潜能、一百锭黄金。\n"NOR);
			break;
		default:
			tell_object(me, "很遗憾，您没有中奖，还是看下次吧。\n");
			break;
	}
	me->set("lottery/finish", 1);
	me->delete_temp("lottery_look");
	if ( ob) destruct(ob);
	log_file("quest/bonus", 
		sprintf("%18s 号码：%s，中奖号码：%s，中了 %d。",
			me->name(1)+"("+ me->query("id") +")",
			num,
			lottery["number"],
			i,
		), me
	);
	return 1;
}

string look_paizi()
{
	string str;

	if ( lottery["set"] != 1)
		return "现在没有抽奖活动。\n";

	str = "\n一、地点：扬州城茶馆。\n";
	str += "二、指令：首先领取奖券(draw)，然后兑奖(exchange)。\n";
	str += "三、活动范围：正式玩家即可。\n";
	str += "四、奖励范围：\n";
	str += "1、特等奖：要求玩家抽奖号码与公布的中奖号码数值及排列顺序完全相同；\n";
	str += "奖品：五万点实战经验、二千点潜能、一千锭黄金、一百点最大内力、一百点最大精力；\n";
	str += "2、一等奖：要求四位数与公布的中奖号码相同，顺序无所谓；\n";
	str += "奖品：二万五千点实战经验、一千点潜能、五百锭黄金、五十点最大内力、五十点最大精力；\n";
	str += "3、二等奖：要求三位数与公布的中奖号码相同，顺序无所谓；\n";
	str += "奖品：一万点实战经验、五百点潜能、三百锭黄金、二十点最大内力、二十点最大精力；\n";
	str += "4、三等奖：要求二位数与公布的中奖号码相同，顺序无所谓；	\n";
	str += "奖品：五千点实战经验、二百点潜能、二百锭黄金、十点最大内力、十点最大精力；\n";
	str += "5、四等奖：要求一位数与公布的中奖号码相同，顺序无所谓；\n";
	str += "奖品：三千点实战经验、一百点潜能、一百锭黄金；\n";
	str += "6、没有一位数与公布的中奖号码相同，没有奖励。\n";

	str +="\n\n本次中奖号码是：\n";
	str += CHINESE_D->font(lottery["number"]);
	str += "\n\n";

	return str;
}
                                                                                          