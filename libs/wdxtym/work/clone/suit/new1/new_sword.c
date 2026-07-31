// new_sowrd.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIG "侠义剑" NOR, ({ "new sword"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("icon","05035");
		set("long", "这是一柄精工制成的"+this_object()->query("name")+"，是地狱家族特别为新手定做的!\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	  //---------------------------------------------------------------
	      //套装参数
		set("suit",HIG"侠义套装"NOR);  //套装名称
		set("suit_lvl",1);	     //套装等级
		set("suit_count",4);	   //套装部件数量
	      //套装各部件
		set("suit_mod/cloth","侠义长衫");
		set("suit_mod/boots","侠义快靴");
		set("suit_mod/pants","侠义长裤");
		set("suit_mod/sword","侠义剑");
		set("suit_mod/blade","侠义刀");
//		set("suit_mod/hands","侠义手套");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",1);      //    一套
		set("suit_eff/constitution",1);      //三件  
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",10);   
	       set("suit_eff_skill/sword",10);
	       set("suit_eff_skill/blade",10);
	       set("suit_eff_skill/cuff",10);
	       set("suit_eff_skill/strike",10);
	       set("suit_eff_skill/finger",10);
	       set("suit_eff_skill/claw",10);
       //------------------------------------------------------
	}
	init_sword(135);
	setup();
}
int query_autoload()
{
	return 1;
}