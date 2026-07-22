// 编写仙丹必备属性介绍
// set("gift_rate", 75);														仙丹的成功率
// set("gift_effect", 8);														仙丹的效果(8倍仙丹)
// set("gift_attr", "xiandan/int");												仙丹增加的属性(xiandan/int, xiandan/str, xiandan/con, xiandan/dex)
// set("gift_type", "int");														仙丹的类型(int, str, con, dex)
// set("gift_time", 360);														仙丹的持续时间(单位为 10s, 360 == 3600s 即一个小时)
// set("gift_cond", "tempint");													仙丹效果名称 用来对状态计时(tempint, tempstr, tempcon, tempdex)
// set("gift_msg", HIG "突然间你只觉灵台处一片空明，舒泰无比。\n" NOR);			吃仙丹的描述
// set("gift_msg2", HIC "你的先天悟性临时(一小时)增加了八倍。\n" NOR);			仙丹的功效描述



#include <ansi.h>
inherit ITEM;

void init()	{ add_action("do_eat", "eat"); }

void owner_is_killed() { destruct(this_object()); }

int do_eat(string arg)
{
	int iRate, iEffect, iTime, iValue;
	string strAttr, strCond, strType;

	if(!id(arg))
		return notify_fail("你要吃什么？\n");

	iRate	= query("gift_rate");
	iEffect = query("gift_effect");
	iTime	= query("gift_time");
	if(!stringp(strAttr = query("gift_attr")))
		return notify_fail("这个丹是臭的！\n");
	if(!stringp(strCond = query("gift_cond")))
		return notify_fail("这个丹是臭的！\n");
	if(!stringp(strType = query("gift_type")))
		return notify_fail("这个丹是臭的！\n");

	if(this_player()->query(strAttr, 1) > 1)
		return notify_fail("你一次只能吃一个\n");

	// 真命天子提升成功几率
	if (this_player()->query("special_skills/emperor"))
		iRate += 35;
	// 天煞孤星提升成功几率
	if (this_player()->query("special_skills/lonely"))
		iRate += 10;
	// 福星高照提升成功几率
	if (this_player()->query("special_skill/lucky"))
		iRate += 5;

	message_vision(WHT "$N" WHT "一仰脖，吞下了一" +
		query("unit") + name() + WHT
		"。\n" NOR, this_player());

	/*
	if (this_player()->query("gift/" + strType + "/all") >= 10)
	{
	tell_object(this_player(), "你觉得这药好象没什么效果。\n");
	} else
	*/

	if(random(100) >= iRate)
	{
		tell_object(this_player(), HIR "不过你觉得这药好像没起到什么"
			"作用。\n" NOR);

		// 记录失败的记号
		this_player()->add("gift/" + strType + "/fail", 1);
	}
	else
	{
		tell_object(this_player(), query("gift_msg"));
		tell_object(this_player(), query("gift_msg2"));

		// 记录成功的记号
		this_player()->add("gift/" + strType + "/succeed", 1);
		iValue = (int)this_player()->query(strType) * (iEffect - 1);
		this_player()->set(strAttr, iValue);

		// 增加相应的天赋属性
		this_player()->add(strType, iValue);
		this_player()->apply_condition(strCond, iTime);
	}

	// 记录入吃丹的总量
	this_player()->add("gift/" + strType + "/all", 1);
	destruct(this_object());
	return 1;
}
