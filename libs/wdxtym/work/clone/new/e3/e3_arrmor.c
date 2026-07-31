// huanglong_arrmor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

string do_wear();

void create()
{
	set_name(HIR "黄龙道袍" NOR, ({"huanglong arrmor"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "玄者级的[黄龙]道袍\n");
		set("material", "armor");
	set("armor_prop/armor", random(40)+20);  //防御
	set("armor_prop/warm", 20);   //保暖
		set("value", 1000);   //价值
		 set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05082");
		set("suit_point",500);
	 //---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"黄龙"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","黄龙道袍");
		set("suit_mod/finger","黄龙戒指");
		set("suit_mod/boots","黄龙靴子");
//		set("suit_mod/hands","黄龙手套");
		set("suit_mod/head","黄龙斗笠");
		set("suit_mod/neck","黄龙护符");
		set("suit_mod/pants","黄龙护腿");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/constitution",random(2)+2);       //两件
		set("suit_eff/spirituality",random(2)+2);      // 五件 
		set("suit_eff/intelligence",random(2)+2);      //三件  
		set("suit_eff/strength",random(2)+2);      //    一套    
	       //套装全部附加技能效果   
		set("suit_eff_skill/club",5);   //一套
		set("suit_eff_skill/stick",5);
		set("suit_eff_skill/staff",5);
		set("suit_eff_skill/parry",5);
	   
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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "穿在身上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，穿在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在身上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在身上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "穿在身上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，穿在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在身上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在身上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
