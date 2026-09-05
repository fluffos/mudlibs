// gift.c    

#include "ansi.h"

inherit NPC;


void create()
{
	set_name(HIW"礼券"HIY"贩子"NOR, ({ "xiao fan", "seller" }));
	set("gender", "男性");
	set("age", 18);
	set("long", "他是是个普通的小贩，不过卖的不是普通的物品。\n");

	set("combat_exp", 8000);
	set("shen_type", -1);

	set("attitude", "peaceful");

	set("inquiry",([
		"礼券"		: "礼券花不出去了？找我啊(list)",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list","list"); 
	add_action("do_change","change");
}

int do_list()
{
	write("目前你拥有"HIY + chinese_number(this_player()->query_temp("gift/point")) + NOR"点临时礼券。\n\n"
		"你可以用临时礼券换取下面的临时属性或物品（需要消耗200点临时礼券）：\n"
		"	1 临时膂力+1	\n"
		"	2 临时悟性+1	\n"
		"	3 临时跟骨+1	\n"
		"	4 临时身法+1	\n"
		"	5 临时攻击+50	\n"
		"	6 临时防御+50	\n"
		"	7 临时躲闪+50	\n"
		"	8 临时掉宝率+50	\n"
		"	9 存款+10 gold	\n"
		"	10 门忠+10		\n"
		"	11 以上随机（只消耗50点临时礼券）\n"
		HIW"	12 邀请侠客岛赏善使者立即造访中原（消耗3000点正式礼券）"NOR

		"\n请输入change <编号>来换取。\n"
		);

	return 1;
}

int do_change(string arg)
{
	object me = this_player();
	int index, cost = 200;
	string msg;
	if (!arg || sscanf(arg, "%d", index) != 1 || index < 1 || index > 12)
		return notify_fail("你要换什么？\n");
	if (index == 12)
		return notify_fail("测试期间，你哪来的正式礼券？\n");
	if (index == 11)
	{	
		cost = 50;
		index = random(10) + 1;
	}
	if (me->query_temp("gift/point") < cost)
		return notify_fail("你没有足够的临时礼券！\n");
	me->add_temp("gift/point", -cost);
	msg = "$N获得了"HIC;
	switch (index)
	{
	case 1:
		me->add_temp("apply/strength", 1);
		msg += "1点膂力";
		break;
	case 2:
		me->add_temp("apply/intelligence", 1);
		msg += "1点悟性";
		break;
	case 3:
		me->add_temp("apply/intelligence", 1);
		msg += "1点跟骨";
		break;
	case 4:
		me->add_temp("apply/dexerity", 1);
		msg += "1点身法";
		break;
	case 5:
		me->add_temp("apply/attack", 50);
		msg += "50点攻击";
		break;
	case 6:
		me->add_temp("apply/defence", 50);
		msg += "50点防御";
		break;
	case 7:
		me->add_temp("apply/dodge", 50);
		msg += "50点躲闪";
		break;
	case 8:
		me->add_temp("apply/magic", 50);
		msg += "50点掉宝率";
		break;
	case 9:
		me->add("balance", 100000);
		msg += HIY"10两黄金（存款）";
		break;
	case 10:
		me->add("score", 20);
		msg += "10点门忠";
		break;
	}
	msg += NOR"。\n";
	message_vision(msg, me);
	write("你还剩下" + chinese_number(me->query_temp("gift/point")) + "点临时礼券。\n" );
	return 1;	
}
