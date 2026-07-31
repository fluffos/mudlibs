// zhenwu_pants.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string do_wear();

void create()
{
	set_name(HIR "爆裂甲" NOR, ({"baolie pants"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是神器级[爆裂]的护腿\n");
		set("material", "pants");    //类型
		set("armor_prop/armor", 9999999);  //防御
		set("armor_prop/warm", 1);   //保暖   地狱中的，这个没有用
		set("value", 10000000);   //价值
		set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05083");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"白前辈"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",6);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","白衣");
		set("suit_mod/finger","真爱魔力");
		set("suit_mod/sword","流星剑");
		set("suit_mod/hands","真爱手套");
		set("suit_mod/head","头束");
		set("suit_mod/neck","加速护符");
		set("suit_mod/pants","爆裂甲");			     
	  //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",22222);      //两件
		set("suit_eff/constitution",22222);      // 五件 
		set("suit_eff/intelligence",22222);      //三件  
		set("suit_eff/strength",22222);      //    一套  
		//set("suit_eff/qi",22222);   
	       //套装全部附加技能效果   
		 //套装全部附加技能效果   
		/*set("suit_eff_skill/liangyi-yinyangjue",9999999);   //一套
		set("suit_eff_skill/buxiujianshu",9999999); 
		set("suit_eff_skill/dodge",9999999); 
		set("suit_eff_skill/force",9999999); 
		set("suit_eff_skill/parry",9999999); 
		set("suit_eff_skill/sword",9999999); 
		set("suit_eff_skill/lunhui-sword",9999999); 
		set("suit_eff_skill/lingbo-weibu",9999999); 
		set("suit_eff_skill/qiankun-danuoyi",9999999); 
		set("suit_eff_skill/sword-cognize",9999999); 
		set("suit_eff_skill/martial-cognize",9999999); 
		set("suit_eff_skill/unarmed",9999999); 
		set("suit_eff_skill/buddhism",9999999);
		set("suit_eff_skill/lamaism",9999999);  
		set("suit_eff_skill/taoism",9999999);	*/     
       //---------------------------------------------------------------
	}
	setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "女性")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "绑在腰上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "绑在腰上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
