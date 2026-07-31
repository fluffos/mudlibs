// wusheng_hands.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIY "史诗之握" NOR, ({"y3 hands"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "史诗级的[史诗]之握\n");
		set("material", "neck");    //类型
	set("armor_prop/armor", random(50)+1180);  //防御
	set("armor_prop/unarmed_damage", random(120)+20);
	set("armor_prop/warm", 1);   //保暖
	       set("value", 30);   //价值
		set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05084");
		  set("suit_point",500);
		//---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"史诗"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","史诗圣袍");
		set("suit_mod/finger","史诗之戒");
		set("suit_mod/boots","史诗之履");
//		set("suit_mod/hands","史诗之握");
		set("suit_mod/head","史诗桂冠");
		set("suit_mod/neck","史诗护符");
		set("suit_mod/pants","史诗护腿");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",random(4)+15);      //两件
		set("suit_eff/constitution",random(4)+15);       // 五件 
		set("suit_eff/intelligence",random(4)+15);      //三件  
		set("suit_eff/strength",random(4)+15);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/force",20);   //一套
		set("suit_eff_skill/dodge",27);
		set("suit_eff_skill/parry",27);

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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "套在手上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，套在手上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "套在手上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "套在手上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "套在手上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，套在手上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "套在手上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "套在手上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
