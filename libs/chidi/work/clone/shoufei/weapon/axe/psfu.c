//edit by rock 2008.9.22
// 自动生成：/make/weapon/blade

#include <weapon.h>
#include <ansi.h>
inherit AXE;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("破山斧",({"psfu"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
		set("unit", "把");           //量词
		set("flag",1);              //单手双手
		set("material", "steel");
                set("wield_msg", "$N双手提起$n。\n");
                set("unwield_msg", "$N放下$n。\n");
		set("level", 35);            //装备等级
		set("value",8500);             //价值
		set("dp",0);                //防御
		set("pp",-48);                //追加防御
		set("ap",0);                //追加攻击
             }
	set("max_lasting",14000);   //耐久度
	init_axe(235);
        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/weapon.h"
