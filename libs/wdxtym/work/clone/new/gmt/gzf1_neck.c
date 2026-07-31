// wusheng_neck.c

#include <ansi.h>
#include <armor.h>

inherit NECK;

string do_wear();

void create()
{
	set_name(HIR "地狱之符" NOR, ({"gzf1 neck"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "地狱级的[地狱]之符\n");
		set("material", "neck");    //类型
	set("armor_prop/armor", random(50)+200);  //防御
	set("armor_prop/warm", 1);   //保暖
	       set("value", 10);   //价值
		 set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05085");
		  set("suit_point",500);
       //---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"地狱"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","地狱巫袍");
		set("suit_mod/finger","地狱真戒");
		set("suit_mod/boots","地狱步履");
//		set("suit_mod/hands","地狱之握");
		set("suit_mod/head","地狱假面");
		set("suit_mod/neck","地狱晶视");
		set("suit_mod/pants","地狱之护");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",random(1)+1);      //两件
		set("suit_eff/constitution",random(1)+1);       // 五件 
		set("suit_eff/intelligence",random(1)+25);      //三件  
		set("suit_eff/strength",random(1)+1);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/force",7);   //一套
		set("suit_eff_skill/dodge",7);
		set("suit_eff_skill/parry",8);

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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "轻轻将一件$n" HIG "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "轻轻将一件$n" YEL "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
		else	
			msg = YEL "$N" YEL "轻轻将一件$n" YEL "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "轻轻将一件$n" HIG "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！！\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "轻轻将一件$n" YEL "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
		else    
			msg = YEL "$N" YEL "轻轻将一件$n" YEL "拿出来，高举！笑道，我为《地狱玩家服》服务，我自豪！\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}