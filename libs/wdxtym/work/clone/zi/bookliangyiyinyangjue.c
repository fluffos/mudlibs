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
	set_name(HIR"【两 仪 阴 阳 诀】", ({"liangyi book"}));	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 288888);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," 孤阴不生，独阳不长，阴阳共济，始生两仪。一本蕴含万物相生的绝世内功\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
if(me->query_skill("liangyi-yinyangjue") > 359)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("liangyi-yinyangjue", me->query_skill("liangyi-yinyangjue",1) + 180);
	write(YEL"你学会了两仪阴阳绝。。。"NOR"\n");
	write(YEL"道生一，无极变太极；一生二，太极变两仪；二生三，两仪变四象；三生万物，四象旋转，终得此决，阴阳之奥秘尽在此书中"NOR"\n");
	
	add_amount(-1);
        return 1;}
}