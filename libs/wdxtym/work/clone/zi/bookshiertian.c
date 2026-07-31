#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIR"【九 转 十 二 天】"NOR, ({"shiertian book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 900000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","修炼境界乃是将自身的武学境界融入太始帝经当中，太始帝经在来世当中从某中意义上来说已经不算是一种单纯的武学招式，而是一种武学境界\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name()+"。\n");
if(me->query_skill("yinyangjiuzhuanshierchongtian") > 359)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 180);
	write(YEL"你学会了太始帝经。。。"NOR"\n");
	write(YEL"只有拥有者将几种境界修炼成功后，方能将太始帝经发挥自如。"NOR"\n");
	
	add_amount(-1);
		return 1;}
}