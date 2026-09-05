//鞭影 created by Zine 2011.3.19
#include <ansi.h>
#include "query.h"
void remove_effect(object me);
inherit ITEM;

void create()
{
    set_name("小鞭",({"xiao bian", "bian","whip"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","柄");
    set("long","这是一柄非金非木的小鞭，鞭身上流动着五彩光纹.\n");
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_store",1);
    set("value",0);
    set("bianying",1);//判断
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
        string msg=HIW"鞭影连环，圆中有圆，生生不息。\n"+NOR;
        if( !me->is_fighting() )
		return notify_fail("鞭影只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
            &&(int)me->query("adv_weapon/class/whip/lv") !=12)
            {
                return notify_fail("你手中无鞭，也想使用鞭影？\n");
            }
        if (!weapon)
        {
            if (me->query("neili")>=5000)
            {
            
                    weapon=new(__DIR__"wubian");
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
        if ((string)weapon->query("skill_type") != "whip")
        {
            return notify_fail("你手中无鞭，也想使用鞭影？\n");
        }

        if( (int)me->query("adv_weapon/class/whip/lv") < 6 )
                return notify_fail("你对鞭影的掌握还不够娴熟。\n");

        if( (int)me->query_temp("adv_weapon/whip") ) 
                return notify_fail("你已经在运功中了。\n");
        me->delete_temp("adv_weapon/whipextra");
        me->delete_temp("adv_weapon/bianmorelv");
        message_vision(msg, me);
       
        if (me->query("adv_weapon/class/whip/lv")>=6)
        {
            i=weapon->query("weapon_prop/damage")/20;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/20;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/whipextra",i);
        }
        
        if (me->query("adv_weapon/class/whip/lv")>=9)
        {
            i=weapon->query("weapon_prop/damage")/10;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/10;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/whipextra",i);
            i=me->query("adv_weapon/class/whip/moredamage")/40;
            me->add_temp("apply/whip",i);
            me->add_temp("adv_weapon/bianmorelv",i);
        }
        if (me->query("adv_weapon/class/whip/lv")>=10)
        {
            i=me->query("adv_weapon/class/whip/moredamage")/100;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/whipextra",i);
        }
        if (me->query("adv_weapon/class/whip/lv")>=12)
        {
            i=me->query("adv_weapon/class/whip/moredamage")/300;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/whipextra",i);
            i=me->query("adv_weapon/class/whip/moredamage")/15;
            me->add_temp("apply/whip",i);
            me->add_temp("adv_weapon/bianmorelv",i);
        }
        
        me->set_temp("adv_weapon/whip", 1);
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
    eff=(int)me->query_temp("adv_weapon/whipextra");
    me->add_temp("apply/damage",-eff);
    me->delete_temp("adv_weapon/whip");
    me->delete_temp("adv_weapon/whipextra");
    eff=(int)me->query_temp("adv_weapon/bianmorelv");
    me->add_temp("apply/whip",-eff);
    me->delete_temp("adv_weapon/bianmorelv");
    tell_object(me, "你静下心来，纵横鞭影消散在天地间。\n");
    return;
}

