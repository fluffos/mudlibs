// gems - by xbd
// modified by Vast@pkuxkx
// all comments added by Vast
// upgraded by becool

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;

void set_level(int min, int number, string gem);
void generate_newweapon(object ob, string material, int lev);
void generate_newarmor(object ob, string material, int lev);
void generate_newring(object ob, string material, int lev);

int is_gem() { return 1; }// /feature/gems.c里面是is_gems()

void create()
{
	int lev, i;
	string gem, s;
	object me = this_player();

	//掉落率：炎晶:木灵:玉髓:精金:玄冰:神龙骨:凤凰羽:麒麟角:玄武甲 = 18:18:18:18:18:2:2:2:4
	i = random(100);
	if (i < 18) gem = "yan";
	else if (i < 36) gem = "mu";
	else if (i < 54) gem = "sui";
	else if (i < 72) gem = "jin";
	else if (i < 90) gem = "bing";
	else if (i < 92) gem = "gu";
	else if (i < 94) gem = "yu";
	else if (i < 96) gem = "jiao";
	else gem = "jia";

	//等级比较重要，可以人为设定上，下限
	set_level(0, 10000, gem);

	setup();
}
void set_level(int min, int number, string gem)
{
	int lev, i;

	if (min > number) return;
	if (min < 0) return;
	if (number > 10000) return;

	i = min + random(number - min + 1);
	//显然如果min == number则可以精确确定宝石的等级

	if (i < 5000) lev = 1;		//二分之一
	else if (i < 8335) lev = 2;	//三分之一
	else if (i < 9445) lev = 3;	//万分之一千一百一十(11.1%)
	else if (i < 9815) lev = 4;	//万分之三百七十(3.7%)
	else if (i < 9940) lev = 5;	//万分之一百二十五(1.25%)
	else if (i < 9980) lev = 6;	//万分之四十(0.4%)
	else if (i < 9995) lev = 7;	//万分之十五(0.15%)
	else lev = 8;			//万分之五(0.05%)
	//请不要随意改动以上数据

	set_name(query_gem_name(gem, lev), ({ query_gem_id(gem, lev), "gem" }));
	set("base_weight", 100 * lev);
	set_weight(100 * lev); //修改重量设置，原先lev^2的设置重量递增太快了 by seagate
	set("yinyang", query_all_yinyang(gem, this_object()));
	set("long", query_all_effect(gem, this_object()));
	set("unit", "颗");
	//只能在专门的地方进行买卖
	set("no_store", 1);
	set("no_sell", 1);
	set("no_pawn", 1);
	set("value", 2000 * lev * lev * lev);
	set("material", gem);
	set("level", lev);
	set("newgem", 1);
	if (gem == "yan" || gem == "mu" || gem == "sui" || gem == "jin" || gem == "bing")
		set("type", "wuxing");
	else if (gem == "gu" || gem == "yu" || gem == "jiao" || gem == "jia")
		set("type", "siling");
	else
		set("type", "riyue");
}

//自动产生特定等级特定类型的宝石
void set_special(string gem, int level)
{
	string *gemk = ({ "yan", "mu", "sui", "jin", "bing", "gu", "yu", "jiao", "jia", "ri", "yue" });

	if (member_array(gem, gemk) < 0 ||
		level <= 0 ||
		level > 8)
		error("生产宝石的参数有误，请重新设定宝石参数。");

	set_name(query_gem_name(gem, level), ({ query_gem_id(gem, level), "gem" }));
	set_weight(1000 * level); //修改重量设置，原先lev^2的设置重量递增太快了 by seagate
	set("yinyang", query_all_yinyang(gem, this_object()));
	set("long", query_all_effect(gem, this_object()));
	set("unit", "颗");
	//只能在专门的地方进行买卖
	set("no_store", 1);
	set("no_sell", 1);
	set("no_pawn", 1);
	set("value", 2000 * level * level * level);
	set("material", gem);
	set("level", level);
	set("newgem", 1);
	if (gem == "yan" || gem == "mu" || gem == "sui" || gem == "jin" || gem == "bing")
		set("type", "wuxing");
	else if (gem == "gu" || gem == "yu" || gem == "jiao" || gem == "jia")
		set("type", "siling");
	else
		set("type", "riyue");
}