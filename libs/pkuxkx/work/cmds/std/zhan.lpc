// by snowman@SJ 18/02/2000
// Modified by iszt@pkuxkx, 2007-04-07

#include <ansi.h>

inherit F_CLEAN_UP;
#define HEAD    "/clone/misc/head"

int main(object me, string arg)
{
        object target, ob, weapon;
        string msg;
		int movetohand = 0;

        if( !arg || arg == " " ) return notify_fail("你要斩什么？\n"); 
 
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你现在正忙着呢。\n"); 

        if( !target = present(arg, environment(me)) ) {
                if( !target = present(arg, me) ) 
                        return notify_fail("找不到这个东西。\n");
        }

        if( !target->is_corpse() ) 
                return notify_fail("看清楚点，那不是尸体。\n");
/*       if (target->query("gender") != "男性"
                && target->query("gender") != "女性"
                && target->query("gender") != "无性")
                return notify_fail("不会吧，你对这种尸体也感兴趣？\n");
				*/
        if (target->query("no_head"))
                return notify_fail("那具尸体已经没有首级了。\n");
        if (!target->is_character())
                return notify_fail("那具尸体已经腐烂了。\n");
        if (target->query("victim_id")=="whuan" || target->query("victim_id")=="icer")
                return notify_fail("大胆！你不要命了！看清楚了，那是谁！\n");
        if( objectp(weapon = me->query_temp("weapon")))
        {
                if(weapon->query("weapon_prop/damage") < 25)
                        return notify_fail("你手中的武器也太钝了，斩不得首级。\n");
				if(objectp(me->query_temp("secondary_weapon")))
				{
					//双手都有装备，首级落地。
					msg = HIR"\n$N提起手中的"+weapon->name()+"和"+me->query_temp("secondary_weapon")->name()+HIR"，对准$n"
							HIR"的脖颈中一阵乱砍，血淋淋的首级咕噜噜的滚落在地。\n"NOR;
					movetohand = 0;
				}
				else
				{
					msg = HIR"\n$N提起手中的"+weapon->name()+HIR"，对准$n"
							HIR"的脖颈中猛斩了下去，将血淋淋的首级提在手中。\n"NOR;				
					movetohand = 1;	
				}
				
        }
        else
        {
                if(me->query("neili")<1000)
                        return notify_fail("你的手中并无兵器，如何斩得首级？\n");
                msg = HIR"\n$N抓住$n"HIR"，手上发力，硬生生的将";
                msg += target->query("victim_name");
                msg += HIR"的头颅从尸体上扯了下来，提在手中！\n"NOR;
                me->add("neili", -500);
				movetohand = 1;
        }
        message_vision(msg, me, target);

        ob = new(HEAD);
        ob->set_name( target->query("victim_name")+"的首级" , ({ "shou ji", "shouji", "head" }) );
        ob->set("long", "这是一颗"+target->query("victim_name")+"的首级。\n");

        if(target->query("victim_user")) 
                ob->set("victim_user", 1);  
        if(target->query("kill_by")) {
                target->set("kill_by", target->query("kill_by"));
                ob->set("kill_by", target->query("kill_by"));
                target->delete("kill_by");
        }

        ob->set("victim_id", target->query("victim_id"));
        ob->set("victim_name", target->query("victim_name"));
        target->delete("victim_id");
        target->delete("victim_id");
        
        if (movetohand && ob->move(me))
		{        
		}
		else
		{
			ob->move(environment(me));
		}
        target->set("name", "无头尸体");
        target->set("no_head", 1);
        target->set("long", "这是一具无头尸体，静静地躺在这里，看起来情状可怖。\n");
        me->start_busy(1);
        return 1;
}      

int help(object me)
{
        write(@HELP
指令格式 : qie <尸体>

这个指令可以让你把尸体的头部切下来。

HELP);
        return 1;
}
