
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(GRN"养精丹"NOR, ({ "yangjing dan","dan" }));
   set_weight(100);
   set("unit", "颗");
   set("long","这是用来疗伤的药,你可以服用(fu dan)用它.\n");
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
	if(!arg||(arg!="dan"&&arg!="丹"))
		return notify_fail("你要服用什么?\n");
	if(me->query("eff_jing")==me->query("max_jing"))
		return notify_fail("你的精没有受到损伤,服什么药啊?\n");
    i=me->query("max_jing")-me->query("eff_jing");
	if(i<=10)
	me->add("eff_jing",i);
	else me->add("eff_jing",i/5);
	message_vision("$N服下了一颗[养精丹].\n",me);
	destruct(ob);
	return 1;
}