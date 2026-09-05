//流戟 created by Zine 2011.3.19
#include <ansi.h>
#include "query.h"
void remove_effect(object me);
inherit ITEM;

void create()
{
    set_name("小戟",({"xiao ji", "ji","halberd"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","柄");
    set("long","这是一柄非金非木的小戟，戟身上流动着五彩光纹.\n");
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_store",1);
    set("value",0);
    set("liuji",1);//判断
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
        string msg=HIC"戟似流云，天威难测，横斩劈刺无往不利。\n"+NOR;
        if( !me->is_fighting() )
		return notify_fail("流戟只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
            &&(int)me->query("adv_weapon/class/halberd/lv") !=12)
            {
                return notify_fail("你手中无戟，也想使用流戟？\n");
            }
        if (!weapon)
        {
            if (me->query("neili")>=5000)
            {
            
                    weapon=new(__DIR__"wuji");
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
        if ((string)weapon->query("skill_type") != "halberd")
        {
            return notify_fail("你手中无戟，也想使用流戟？\n");
        }

        if( (int)me->query("adv_weapon/class/halberd/lv") < 6 )
                return notify_fail("你对流戟的掌握还不够娴熟。\n");

        if( (int)me->query_temp("adv_weapon/halberd") ) 
                return notify_fail("你已经在运功中了。\n");
        me->delete_temp("adv_weapon/halberdextra");
        me->delete_temp("adv_weapon/jimorelv");
        message_vision(msg, me);
       
        if (me->query("adv_weapon/class/halberd/lv")>=6)
        {
            i=weapon->query("weapon_prop/damage")/20;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/20;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/halberdextra",i);
        }
        
        if (me->query("adv_weapon/class/halberd/lv")>=9)
        {
            i=weapon->query("weapon_prop/damage")/10;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/10;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/halberdextra",i);
            i=me->query("adv_weapon/class/halberd/moredamage")/40;
            me->add_temp("apply/halberd",i);
            me->add_temp("adv_weapon/jimorelv",i);
        }
        if (me->query("adv_weapon/class/halberd/lv")>=10)
        {
            i=me->query("adv_weapon/class/halberd/moredamage")/100;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/halberdextra",i);
        }
        if (me->query("adv_weapon/class/halberd/lv")>=12)
        {
            i=me->query("adv_weapon/class/halberd/moredamage")/300;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/halberdextra",i);
            i=me->query("adv_weapon/class/halberd/moredamage")/15;
            me->add_temp("apply/halberd",i);
            me->add_temp("adv_weapon/jimorelv",i);
        }
        
        me->set_temp("adv_weapon/halberd", 1);
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
    eff=(int)me->query_temp("adv_weapon/halberdextra");
    me->add_temp("apply/damage",-eff);
    me->delete_temp("adv_weapon/halberd");
    me->delete_temp("adv_weapon/halberdextra");
    eff=(int)me->query_temp("adv_weapon/jimorelv");
    me->add_temp("apply/halberd",-eff);
    me->delete_temp("adv_weapon/jimorelv");
    tell_object(me, "你静下心来，流云般的戟影悄然无踪。\n");
    return;
}

