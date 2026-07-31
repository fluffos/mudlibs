// new_sowrd.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIG "蓝纹刀" NOR, ({ "zb1b"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("icon","05035");
		set("long", "这是一柄精工制成的"+this_object()->query("name")+"，蓝纹套装系列!\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	  //---------------------------------------------------------------
	      //套装参数
		set("suit",HIG"蓝纹套装"NOR);  //套装名称
		set("suit_lvl",1);	     //套装等级
		set("suit_count",4);	   //套装部件数量
	      //套装各部件
		set("suit_mod/cloth","蓝纹长衫");
		set("suit_mod/boots","蓝纹快靴");
		set("suit_mod/pants","蓝纹长裤");
		set("suit_mod/sword","蓝纹剑");
		set("suit_mod/blade","蓝纹刀");
//		set("suit_mod/hands","蓝纹手套");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",1);      //    一套
		set("suit_eff/constitution",1);      //三件  
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",50);   
	       set("suit_eff_skill/sword",50);
	       set("suit_eff_skill/blade",50);
	       set("suit_eff_skill/cuff",50);
	       set("suit_eff_skill/strike",50);
	       set("suit_eff_skill/finger",50);
	       set("suit_eff_skill/claw",50);
       //------------------------------------------------------
	}
	init_blade(175);
	setup();
}
int query_autoload()
{
	return 1;
}