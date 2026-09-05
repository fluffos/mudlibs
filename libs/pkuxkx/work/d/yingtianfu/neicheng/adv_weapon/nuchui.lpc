//怒锤 created by Zine 2011.3.19
#include <ansi.h>
#include "query.h"
void remove_effect(object me);
inherit ITEM;

void create()
{
    set_name("小锤",({"xiao chui", "chui","hammer"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","柄");
    set("long","这是一柄非金非木的小锤，锤身上流动着五彩光纹.\n");
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_store",1);
    set("value",0);
    set("nuchui",1);//判断
    set("material","unknown");
  }
 setup();
}

void init()
{
    object ob=this_object();
    object belong=environment(ob);
    if (userp(belong))
    {
        destruct(ob);
        return;
    }
}

int act()
{
        object me=this_player();
        object weapon;
        int damage,i;
        string msg=HIG"天锤之下，其势不可挡，直如雷神之怒。\n"+NOR;
        if( !me->is_fighting() )
		return notify_fail("怒锤只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
            &&(int)me->query("adv_weapon/class/hammer/lv") !=12)
            {
                return notify_fail("你手中无锤，也想使用怒锤？\n");
            }
        if (!weapon)
        {
            if (me->query("neili")>=5000)
            {
            
                    weapon=new(__DIR__"wuchui");
                    weapon->move(me);
                    me->set_temp("weapon",weapon);
                    me->add("neili", -1000);
                    message_vision(HIR"$N早已领悟了无招胜有招的境界，天兵实在神威莫测！\n"NOR,me);
            }
            else
            {
                return notify_fail("你的内力不足，暂时不能使用无招胜有招。\n");
            }
        }
        if ((string)weapon->query("skill_type") != "hammer")
        {
            return notify_fail("你手中无锤，也想使用怒锤？\n");
        }

        if( (int)me->query("adv_weapon/class/hammer/lv") < 6 )
                return notify_fail("你对怒锤的掌握还不够娴熟。\n");

        if( (int)me->query_temp("adv_weapon/hammer") ) 
                return notify_fail("你已经在运功中了。\n");
        me->delete_temp("adv_weapon/hammerextra");
        me->delete_temp("adv_weapon/chuimorelv");
        message_vision(msg, me);
       
        if (me->query("adv_weapon/class/hammer/lv")>=6)
        {
            i=weapon->query("weapon_prop/damage")/20;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/20;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/hammerextra",i);
        }
        
        if (me->query("adv_weapon/class/hammer/lv")>=9)
        {
            i=weapon->query("weapon_prop/damage")/10;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/10;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/hammerextra",i);
            i=me->query("adv_weapon/class/hammer/moredamage")/40;
            me->add_temp("apply/hammer",i);
            me->add_temp("adv_weapon/chuimorelv",i);
        }
        if (me->query("adv_weapon/class/hammer/lv")>=10)
        {
            i=me->query("adv_weapon/class/hammer/moredamage")/100;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/hammerextra",i);
        }
        if (me->query("adv_weapon/class/hammer/lv")>=12)
        {
            i=me->query("adv_weapon/class/hammer/moredamage")/300;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/hammerextra",i);
            i=me->query("adv_weapon/class/hammer/moredamage")/15;
            me->add_temp("apply/hammer",i);
            me->add_temp("adv_weapon/chuimorelv",i);
        }
        
        me->set_temp("adv_weapon/hammer", 1);
        call_out("check_fight",1,me,weapon);
	    me->add("neili", -300);
	    if( me->is_fighting() ) me->add_busy(random(2));

        return 1;
}

void check_fight(object me, object weapon) 
{ 
	if(!me
	|| !living(me)
	|| !me->is_fighting()
	|| !me->query_temp("weapon")
	||  me->query_temp("weapon") != weapon) 
	{
		remove_effect(me);
		return;
	}
    call_out("check_fight", 1, me, weapon); 
} 


void remove_effect(object me)
{
	int eff;
    if(!objectp(me))
        return;
    eff=(int)me->query_temp("adv_weapon/hammerextra");
    me->add_temp("apply/damage",-eff);
    me->delete_temp("adv_weapon/hammer");
    me->delete_temp("adv_weapon/hammerextra");
    eff=(int)me->query_temp("adv_weapon/chuimorelv");
    me->add_temp("apply/hammer",-eff);
    me->delete_temp("adv_weapon/chuimorelv");
    tell_object(me, "你静下心来，天地之间再无雷神之怒。\n");
    return;
}

