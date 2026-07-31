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
	set_name(HIY"幸运灵石袋"NOR, ({"nhua dai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"幸运大礼包灵石袋子？有概率获得一亿灵石\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 1000);

		set("yuanbao", 1200);
        set("no_sell", 1);
		set("no_put",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_steal",1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int i,ob1;

    if (me->is_busy())
           return notify_fail("你正忙着呢。\n");
i=random(6);
if (i<1){
me->add("yuanbao",100);
message_vision(HIR"$N获得了100个灵石！"NOR"\n", me, this_object());
}
if (i<1){
me->add("yuanbao",200);
message_vision(HIR"$N获得了200个灵石！"NOR"\n", me, this_object());
}
if (i<1){
me->add("yuanbao",300);
message_vision(HIR"$N获得了500个灵石！"NOR"\n", me, this_object());
}
if (i<1){
me->add("yuanbao",400);
message_vision(HIR"$N获得了800个灵石！"NOR"\n", me, this_object());
}
if (i<1){
me->add("yuanbao",500);
message_vision(HIR"$N获得了1000个灵石！"NOR"\n", me, this_object());
}
if (i>=1 && i<2){
me->add("yuanbao",444);
message_vision(HIR"$N获得了444个灵石！"NOR"\n", me, this_object());
}
if (i>=2 && i<3){
me->add("yuanbao",555);
message_vision(HIR"$N获得了555个灵石！"NOR"\n", me, this_object());
}
if (i>=3 && i<4){
me->add("yuanbao",666);
message_vision(HIR"$N获得了666个灵石！"NOR"\n", me, this_object());
}
if (i>=4){
me->add("yuanbao",888);
message_vision(HIR"$N获得了888个灵石！"NOR"\n", me, this_object());
}	
	add_amount(-1);
	return 1;

}
