// gems - by xbd
// modified by Vast@pkuxkx
// all comments added by Vast

#include <ansi.h>

inherit ITEM;
inherit F_GEMS2;

void set_level(int min, int number, string gem);
void generate_newweapon(object ob, string material, int lev);
void generate_newarmor(object ob, string material, int lev);
void generate_newring(object ob, string material, int lev);

int is_gem() {return 1;}// /feature/gems.c里面是is_gems()

void create()
{
	int lev, i;
	string gem, s;
	object me = this_player();

	//掉落率：炎晶:木灵:玉髓:精金:玄冰:神龙骨:凤凰羽:麒麟角:玄武甲 = 1:1:1:1:1:3:3:3:2 
	i = random(20);
	if (i < 3) gem = "yan";
	else if (i < 6) gem = "mu";
	else if (i < 9) gem = "sui";
	else if (i < 12) gem = "jin";
	else if (i < 15) gem = "bing";
	else if (i < 16) gem = "gu";
	else if (i < 17) gem = "yu";
	else if (i < 18) gem = "jiao";
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

	set_name(query_gem_name(gem, lev), ({query_gem_id(gem, lev), "gem"}));
	set_weight( 100 * lev * lev);
	set("yinyang", query_all_yinyang(gem, this_object()));
	set("long", query_all_effect(gem, this_object()));
	set("unit", "颗");
	//只能在专门的地方进行买卖
	set("no_store",1);
  set("no_sell",1);
  set("no_pawn",1);
	set("value", 2000 * lev * lev * lev);
	set("material", gem);
	set("level", lev);
}