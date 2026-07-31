// ling_sowrd.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIB "灵猿雪剑" NOR, ({ "ling sword"}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("icon","06010");
		set("long", "这是一柄"+this_object()->query("name")+"，是华山二阶套装。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
		set("suit_point",50);
	
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
	init_sword(58);
	setup();
}
int query_autoload()
{
	return 1;
}