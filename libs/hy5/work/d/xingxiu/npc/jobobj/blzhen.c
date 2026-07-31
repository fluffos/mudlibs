// yfzhen.c 碧磷针
// By Kayin @ CuteRabbit Studio 1999.3.23 new
#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void init()
{
        add_action("do_yong","shoot");
}

void create()
{
   set_name(HIG"碧磷针"NOR, ({"bilin zhen", "zhen", "bilin"}));
    	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "些");
                set("value", 0);
                set("base_unit", "枚");
                set("base_weight", 300);
                set("base_value", 0);
	set("value", 0);
                set("material", "iron");
      set("long", HIG"一枚发出绿油油光茫的细针，一望而知喂有剧毒。你可以
      射(shoot)\n" NOR);
        	}
        set_amount(50);
        init_throwing(50);
	setup();
}
int do_yong(string arg)
{
	object me,target;
	mapping myfam;
string limbs;
	me=this_player();
if(!me->query("family"))
return notify_fail("不怕自己被这针扎到吗?\n");
	myfam = (mapping)me->query("family");
   if(!arg)
       return notify_fail("你要用针扎谁？\n");

   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派"))
                  return notify_fail("只有星宿弟子利用本门秘传内功方能使用碧磷针。\n"); 


	if( !me->is_fighting() )
		return notify_fail("碧磷针只能对战斗中的对手使用。\n");

        if ( (int)me->query_skill("poison",1) <= 0 )
        return notify_fail("你会用毒？！\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if(target == me)
        return notify_fail("你想自杀？ :p\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("碧磷针,只能对战斗中的对手使用。\n");
        
   message_vision(HIG"$N左手在袖底轻轻一扬，一蓬碧绿的闪光，向$n激射而去。\n" NOR, me, target);
    me-> start_busy (2) ;
    if (  random ( (int)me->query("combat_exp")+(int)me->query_skill("poison",1)*500 ) < (int)target->query("combat_exp") / 2 )
      {
      message_vision(HIB"\n但$n"HIB"反映神速，有惊无险的躲开了$N的"HIY"玉蜂针！\n"NOR , me, target);
      }
    else
      {
   limbs = target->query("limbs");
if (limbs)
{
   message_vision(CYN"\n结果$N一声惨叫，碧磷针已然穿进了$N的"+limbs[random(sizeof(limbs))]+"。\n"NOR, target, me);
}
	target->apply_condition("insect_poison",(int)target->query_condition("insect_poison")+ 40);
      }
         destruct(this_object());
    return 1;
}
	
	