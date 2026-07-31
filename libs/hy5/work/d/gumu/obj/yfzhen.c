// yfzhen.c 玉峰针
// By Kayin @ CuteRabbit Studio 1999.3.23 new
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_yong","shoot");
}

void create()
{
	set_name(HIY"玉峰针"NOR, ({ "yufeng zhen", "zhen" }) );
    	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "枚");
	set("value", 1000);
	set("material", "gold");
        set("long", "这是一枚用精钢配以黄金铸成的细如发丝的金针  你可以用来(shoot).\n");
        	}
	setup();
}
int do_yong(string arg)
{
	object me,target;
	mapping myfam;
	me=this_player();
if(!me->query("family"))
return notify_fail("不怕自己被这玉蜂针扎到吗?\n");
	myfam = (mapping)me->query("family");
   if(!arg)
       return notify_fail("你要用玉蜂针扎谁？\n");
	
	if( !me->is_fighting() )
		return notify_fail("玉峰针只能对战斗中的对手使用。\n");

	if ((!myfam || myfam["family_name"] != "古墓派"))
		return notify_fail("不怕自己被这玉蜂针扎到吗?\n");
		

        if ( (int)me->query_skill("throwing",1) <= 0 )
        return notify_fail("你会用暗器吗？！\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if(target == me)
        return notify_fail("你想自杀？ :p\n");
        
    message_vision(HIY "\n$N从怀里摸出一枚"HIY"玉蜂针"HIY"扣在手中，手起针出，一枚细如发丝的金针射向$n,\n"NOR,me,target);
    me-> start_busy (2) ;
    if (  random ( (int)me->query_skill("throwing")*2 ) < (int)target->query_skill("dodge") / 2 )
      {
      message_vision(HIB"\n但$n"HIB"反映神速，有惊无险的躲开了$N的"HIY"玉蜂针！\n"NOR , me, target);
      }
    else
      {
       message_vision( HIR "\n只见"HIC"$n"HIR"左手一挥，一枚金针射入"HIC"$N"HIR"的体内。\n"NOR,target ,me);
	target->apply_condition("yufeng_poison",(int)target->query_condition("yufeng_poison")+ 10);
      }
         destruct(this_object());
    return 1;
}
	
		