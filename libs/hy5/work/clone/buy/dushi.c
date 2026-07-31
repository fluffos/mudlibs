// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIY"朱睛冰蟾油"NOR, ({"chan"}));


	set_weight(200);
	set("unit", "瓶");
	set("value", 1000000);
	set("long", "这是一瓶千年难得一瓶的朱睛冰蟾油, 通体透明,
惟眼呈赤色, 使用后(use) 能解百毒。\n");

	set("no_put",1);
	              set("no_beg",1);
	              set("no_steal",1);
                set("no_clone",1);
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	
	if (me->query_condition("f_condi") )
		return notify_fail("你才吃过朱睛冰蟾油 再吃没什么效果!!\n");

	if(arg=="chan") 
	{
message_vision(HIG"$N吃下一点朱睛冰蟾油，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
		if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
        if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        if (me->query_condition("qishang_poison"))
        {          me->clear_condition("qishang_poison");}
        if (me->query_condition("jy-poison"))
        {          me->clear_condition("jy-poison");}
        if (me->query_condition("xx_poison"))
        {          me->clear_condition("xx_poison");}
        if (me->query_condition("cold_poison"))
        {          me->clear_condition("cold_poison");}
        if (me->query_condition("flower_poison"))
        {          me->clear_condition("flower_poison");}
        if (me->query_condition("chilian_poison"))
        {          me->clear_condition("chilian_poison");}
        if (me->query_condition("yufeng_poison"))
        {          me->clear_condition("yufeng_poison");}
        if (me->query_condition("anqi_poison"))
        {          me->clear_condition("anqi_poison");}
       if (me->query_condition("yf_poison"))
        {          me->clear_condition("yf_poison");}
       if (me->query_condition("nx_poison"))
        {          me->clear_condition("nx_poison");}
       if (me->query_condition("x2_poison"))
        {          me->clear_condition("x2_poison");}
       if (me->query_condition("sanpoison"))
        {          me->clear_condition("sanpoison");}
       if (me->query_condition("insect_poison"))
        {          me->clear_condition("insect_poison");}



me->clear_condition("anqi_poison");
me->clear_condition("baituo_poison");
me->clear_condition("bat");
me->clear_condition("bing_poison");
me->clear_condition("binghuo");
me->clear_condition("black_poison");
me->clear_condition("broken_arm");
me->clear_condition("canxia");
me->clear_condition("chanchu_poison");
me->clear_condition("chilian_poison");
me->clear_condition("cold_poison");
me->clear_condition("corpse_poison");
me->clear_condition("cuixin_zhang");
me->clear_condition("dashouyin");
me->clear_condition("dragon_poison");
me->clear_condition("emerald_poison");
me->clear_condition("fire_poison");
me->clear_condition("flower_poison");
me->clear_condition("green_blood");
me->clear_condition("hehe");
me->clear_condition("hot_poison");
me->clear_condition("huanyin_poison");
me->clear_condition("ice_poison");
me->clear_condition("iceshock");
me->clear_condition("ill_dongshang");
me->clear_condition("ill_fashao");
me->clear_condition("ill_keshou");
me->clear_condition("ill_kesou");
me->clear_condition("ill_shanghan");
me->clear_condition("ill_zhongshu");
me->clear_condition("insect_poison");
me->clear_condition("juehu_hurt");
me->clear_condition("jy-poison");
me->clear_condition("jy_poison");
me->clear_condition("libie");
me->clear_condition("new_poison1");
me->clear_condition("new_poison2");
me->clear_condition("new_poison3");
me->clear_condition("new_poison4");
me->clear_condition("new_poison5");
me->clear_condition("new_poison6");
me->clear_condition("new_poison7");
me->clear_condition("new_poison8");
me->clear_condition("no_shadow");
me->clear_condition("nx_poison");
me->clear_condition("poison");
me->clear_condition("poison_sandu");
me->clear_condition("qiankun_wound");
me->clear_condition("qiankunyibang");
me->clear_condition("qinghua_poison");
me->clear_condition("qishang_poison");
me->clear_condition("qx_snake_poison");
me->clear_condition("rose_poison");
me->clear_condition("sanpoison");
me->clear_condition("sanxiao_poison");
me->clear_condition("scorpion_poison");
me->clear_condition("shenlong_poison");
me->clear_condition("shenzhao");
me->clear_condition("sl_poison");
me->clear_condition("snake_poison");
me->clear_condition("ss_poison");
me->clear_condition("tiezhang_yang");
me->clear_condition("tiezhang_yin");
me->clear_condition("tmpili_poison");
me->clear_condition("tmqidu_poison");
me->clear_condition("tmzhuihun_poison");
me->clear_condition("unknown");
me->clear_condition("wudoumi-fanshi");
me->clear_condition("wugong_poison");
me->clear_condition("wuhudu_poison");
me->clear_condition("wuxing_poison");
me->clear_condition("x2_poison");
me->clear_condition("x2_sandu");
me->clear_condition("xiezi_poison");
me->clear_condition("xscold_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuantian_han");
me->clear_condition("xx_condition");
me->clear_condition("xx_liandu");
me->clear_condition("xx_poison");
me->clear_condition("xx_sandu");
me->clear_condition("yf_poison");
me->clear_condition("yufeng_poison");
me->clear_condition("yyz_damage");
me->clear_condition("zhizhu_poison");
me->clear_condition("zhua_poison");
me->clear_condition("zimu-zhen");
me->clear_condition("zm_poison");
me->clear_condition("zmqidu_poison");
me->clear_condition("new_poison1");
me->clear_condition("new_poison2");
me->clear_condition("new_poison3");
me->clear_condition("new_poison4");
me->clear_condition("new_poison5");
me->clear_condition("new_poison6");

}
	//me->start_busy(3);
me->apply_condition("f_condi",3);
        //destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }