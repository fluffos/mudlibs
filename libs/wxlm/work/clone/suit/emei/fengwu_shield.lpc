// fengwu_shield.c


#include <armor.h>

inherit SHIELD	;

string do_wear();

void create()
{
	set_name(HIM "③凤舞之盾" NOR, ({"fengwu shield"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "面");
		set("long", "这是圣器级[凤舞套装]的盾牌\n");
		set("material", "shield");    //类型
		set("armor_prop/armor", 100);  //防御
		set("armor_prop/warm", 1);   //保暖
		set("value", 10);	 //价值
		set("wear_msg", (: do_wear :));  //装备信息
       //---------------------------------------------------------------
	      //套装参数
		set("suit",HIM"凤舞套装"NOR);  //套装名称
		set("suit_lvl",3);	     //套装等级
		set("suit_count",1);	   //套装部件数量
	      //套装各部件
		set("suit_mod/sword","凤舞裙甲");
		set("suit_mod/boots","凤舞头冠");
		set("suit_mod/arrmor","凤舞法袍");
		set("suit_mod/neck","凤舞护符");
		set("suit_mod/shield","凤舞手套");
	    //套装全部附加效果  //身法第一，根骨第二，悟性，臂力
		set("suit_eff/dex",1);    
		set("suit_eff/con",2);  
		set("suit_eff/int",3);    
		set("suit_eff/str",4);    
	  //     
		set("suit_eff_skill/fly",10);   
		set("suit_eff_skill/taoism",10);	       
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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "披在身上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，披在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "披在身上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "披在身上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "披在身上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，披在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "披在身上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "披在身上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
