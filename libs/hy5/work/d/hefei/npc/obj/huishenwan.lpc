
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(GRN"回神丸"NOR, ({ "huishen wan","wan" }));
   set_weight(100);
   set("unit", "颗");
   set("long","这是用来疗伤的药,你可以服用(fu wan)用它.\n");
   set("value", 2000);
   
}

void init()
{
	add_action("do_fu","fu");
}
int do_fu(string arg)
{
	object me,ob;int i;
	ob=this_object();me=this_player();
	if(!arg||(arg!="wan"&&arg!="丸"))
		return notify_fail("你要服用什么?\n");
	if(me->query("sen")==me->query("max_jing"))
		return notify_fail("你的精神很好,服什么药啊?\n");
    i=me->query("max_jing")-me->query("sen");
	if(i<=10)
	me->add("sen",i);
	else me->add("sen",i/5);
	message_vision("$N服下了一颗[回神丸].\n",me);
	destruct(ob);
	return 1;
}