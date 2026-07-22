//edit by rock 2008.9.22
// 自动生成：/make/weapon/blade

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("寒青剑",({"hqj"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
		set("unit", "柄");           //量词
		set("flag",1);              //单手双手
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
		set("level", 25);            //装备等级
		set("value",4500);             //价值
		set("dp",8);                //防御
		set("pp",7);                //追加防御
		set("ap",55);                //追加攻击
             }
	set("max_lasting",13000);   //耐久度
	init_sword(62);
        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/weapon.h"
