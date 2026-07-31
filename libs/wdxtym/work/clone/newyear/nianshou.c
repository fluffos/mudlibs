
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIY "年兽召唤卡" NOR, ({ "nianshou card" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一张精美的金色卡片，上面画着一个年兽的图案。\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "张");
		set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}



int do_effect(object me)
{
	
	object nianshou;
	nianshou = new("clone/shizhe/nianshou");
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	nianshou->move(environment(me));
	
	//message_vision("channel", HIR"【剑诀】:"HIY"听说"+HIG+me->query("name")+HIY"召唤出了年兽！"NOR"\n", users());
	//message_vision(CYN "$N" CYN "使用了"+query("unit")+"" + name() + CYN "，召唤出了年兽。"NOR"\n", me);
	CHANNEL_D->do_channel( this_object(), "chat","据说"+me->query("name")+"使用了"+this_object()->query("name")+""HIC"，召唤了"HIR"年兽！");
        
	add_amount(-1);
	return 1;
}