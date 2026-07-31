inherit COMBINED_ITEM;
#include <ansi.h>
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
	set_name(HIM"小还丹[绑]"NOR, ({"xiaohuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 20);
        set("no_sell",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1); 
        set("base_weight", 10);
        set("base_value", 100);
        set("base_unit", "颗");
		set("unit", "颗");
		set("long","这是一颗小还丹，服用之后能增加10点内力修为！注：可以连续服用，不能超出人物的内力上限。\n");
		set("only_do_effect", 1);
	}
   setup();
}

do_effect(object me)
{
	object ob1;
    int times;

	
    if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("你已经不能使用小还丹来提升内力修为了。\n"); 
 
	me->add("max_neili", 10);
    message_vision(me->query("name")+"服下一颗"HIM"小还丹"NOR"，顿觉内力大增！"NOR"\n",me);
	add_amount(-1);
	return 1;
}
