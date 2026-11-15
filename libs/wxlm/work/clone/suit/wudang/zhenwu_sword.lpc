
#include <weapon.h> 


inherit SWORD;


void create()
{
	set_name(HIR"⑤真武除邪剑"NOR, ({"zhenwu sword"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把不知道什么材料做的剑，发出幽幽的光芒\n");
		set("value", 20000000);   //价值
		 set("material", "crimson gold");  //原料
		set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中．\n");
		set("unwield_msg",
"$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");
	 set("weapon_prop/int", 2);
	 set("icon","05093");
	    set("suit_point",1000);
       //---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"真武除邪"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",6);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","真武法袍");
		set("suit_mod/finger","真武戒指");
		set("suit_mod/sword","真武除邪剑");
		set("suit_mod/hands","真武手套");
		set("suit_mod/head","真武头冠");
		set("suit_mod/neck","真武护符");
		set("suit_mod/pants","真武裙甲");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性，臂力
		set("suit_eff/dex",3);      //两件
		set("suit_eff/con",4);      // 五件 
		set("suit_eff/int",5);      //三件  
		set("suit_eff/str",6);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/taiji-jian",10);   //一套
		set("suit_eff_skill/taiji-quan",10); 
		set("suit_eff_skill/taoism",10);	   
       //---------------------------------------------------------------
	}
	init_sword(80);
	setup();
}

int query_autoload()
{
	return 1;
}

