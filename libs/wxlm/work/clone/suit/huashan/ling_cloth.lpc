// ling_cloth.c   //angelus


#include <armor.h>

inherit CLOTH;

string do_wear();

void create()
{
	set_name(HIB "灵猿雪甲" NOR, ({"ling cloth"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件"+this_object()->query("name")+"，是华山二阶套装。\n");
		set("material", "cloth");     //类型
		set("armor_prop/armor", 40);  //防御
		set("armor_prop/warm", 20);   //保暖
		set("value", 8000);   //价值
		set("wear_msg", (: do_wear :));  //装备信息
		set("suit_point",50);
		set("icon","06011");
	 //---------------------------------------------------------------
	      //套装参数
		set("suit",HIB"灵猿套装"NOR);  //套装名称
		set("suit_lvl",2);	     //套装等级
		set("suit_count",4);	   //套装部件数量
	      //套装各部件
		set("suit_mod/cloth","灵猿雪甲");
		set("suit_mod/boots","灵猿飞靴");
		set("suit_mod/pants","灵猿雪裤");
		set("suit_mod/sword","灵猿雪剑");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
	      
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",3);      //    一套
	      
		set("suit_eff/constitution",2);      //三件  
	    
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",10);   
	       set("suit_eff_skill/sword",10);
       //------------------------------------------------------
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
