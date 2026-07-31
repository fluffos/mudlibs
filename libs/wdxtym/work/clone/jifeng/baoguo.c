inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"背包卡"NOR, ({"zen card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000000);
		set("tongbao", 600);
		set("jifeng", 100);
                set("no_sell",1);
		set("unit", "张");
		set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("only_do_effect", 1);
		set("long","，一人只能用一次，买多了概不负责！！这是一张背包加大卡，"ZJURL("cmds:use zengrong card")ZJSIZE(20)"使用"NOR"之后包裹容量可以扩大十格!\n");
		set("spectxt", "使用后背包容量可以扩大十格。\n");
	}
}
/*
void init()
{
    if (environment()==this_player())
    	add_action("do_use","duihuan");
}
*/
//int do_use(string arg)

int do_effect(object me)
{
	me=this_player();

	//if (arg!="zengrong card")
      	//	return notify_fail("你要使用什么?\n");  

	if ( me->query("zengrong"))
      		return notify_fail("你已经使用过背包卡啦!\n");  

        me->set("zengrong",10);
	write(YEL"使用成功！你的背包容量扩大了10格。"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }