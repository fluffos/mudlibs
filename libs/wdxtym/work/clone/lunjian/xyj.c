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
	set_name(HIR"玄阴剑法", ({"xuanyin"}));	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10);
		set("coin", 1);
        set("base_unit", "本");    
		set("no_drop",1); 
		set("no_give",1);
        set("no_get",1);	
		set("no_steal",1);		
		set("base_weight", 10);
		set("gongxian",5000);
		set("long",HIW"这是一本玄阴剑，可无限使用。\n");
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

	me->set_skill("xuanyin-jian",360);
        

	write(HIW"你获得了360+玄阴剑法，"NOR+HIG"感谢您的大力支持，祝您游戏愉快！"NOR"\n");

    return 1;
}
