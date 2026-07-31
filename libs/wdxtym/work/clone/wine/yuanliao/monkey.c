// dangui.c

#include "herb.h"

void create()
{
	set_name(RED "鲜桃" NOR, ({ "tao zi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
	//	set("long", "据说猴子非常喜欢吃桃子之类的鲜果。据说某些猴子会给投缘的人以猴儿酒作为回报。\n");
		set("long","这是一枚新鲜的桃子。"ZJURL("cmds:use tao zi-b")ZJSIZE(22)"服用"NOR"之后能增加100点内力修为！注：可以连续服用，不能超出人物的内力上限。\n");
		set("base_unit", "枚");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",400);
		set("only_do_effect", 1);
		//set("wine","/clone/wine/monkey");
	}
	setup();
}
int do_effect(object me)
{
	

    if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("你已经不能使用桃子来提升内力修为了。\n"); 
 
	me->add("max_neili", 100);

    message_vision(me->query("name")+"服下一枚"RED"桃子"NOR"，顿觉内力大增！"NOR"\n",me);
	add_amount(-1);
	return 1;
}