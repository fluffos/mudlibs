
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(HIR"补血丹"NOR, ({ "buxue dan","dan" }));
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
	if(me->query("eff_qi")==me->query("max_qi"))
		return notify_fail("你的气血没有受到损伤,服什么药啊?\n");
    i=me->query("max_qi")-me->query("eff_qi");
	if(i<=10)
	me->add("eff_qi",i);
	else me->add("eff_qi",i/5); 
	message_vision("$N服下了一颗[补血丹].\n",me);
	destruct(ob);
	return 1;
}