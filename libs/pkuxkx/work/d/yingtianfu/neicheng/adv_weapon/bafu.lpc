//霸斧 created by Zine 2011.3.19
#include <ansi.h>
#include "query.h"
void remove_effect(object me);
inherit ITEM;
void create()
{
    set_name("小斧",({"xiao fu", "fu","axe"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","柄");
    set("long","这是一柄非金非木的小斧，斧身上流动着五彩光纹.\n");
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_store",1);
    set("value",0);
    set("bafu",1);//判断
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
        string msg=HIY"战斧霸道，冲阵斩将，端的是天下第一神兵。\n"+NOR;
        if( !me->is_fighting() )
		return notify_fail("霸斧只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
            &&(int)me->query("adv_weapon/class/axe/lv") !=12)
            {
                return notify_fail("你手中无斧，也想使用霸斧？\n");
            }
        if (!weapon)
        {
            if (me->query("neili")>=5000)
            {
            
                    weapon=new(__DIR__"wufu");
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
        if ((string)weapon->query("skill_type") != "axe")
        {
            return notify_fail("你手中无斧，也想使用霸斧？\n");
        }

        if( (int)me->query("adv_weapon/class/axe/lv") < 6 )
                return notify_fail("你对霸斧的掌握还不够娴熟。\n");

        if( (int)me->query_temp("adv_weapon/axe") ) 
                return notify_fail("你已经在运功中了。\n");
        me->delete_temp("adv_weapon/axeextra");
        me->delete_temp("adv_weapon/fumorelv");
        message_vision(msg, me);
       
        if (me->query("adv_weapon/class/axe/lv")>=6)
        {
            i=weapon->query("weapon_prop/damage")/20;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/20;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/axeextra",i);
        }
        
        if (me->query("adv_weapon/class/axe/lv")>=9)
        {
            i=weapon->query("weapon_prop/damage")/10;
            if (weapon->query("forge"))
            {
                i=weapon->query("weapon/damage")/10;
            }
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/axeextra",i);
            i=me->query("adv_weapon/class/axe/moredamage")/40;
            me->add_temp("apply/axe",i);
            me->add_temp("adv_weapon/fumorelv",i);
        }
        if (me->query("adv_weapon/class/axe/lv")>=10)
        {
            i=me->query("adv_weapon/class/axe/moredamage")/100;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/axeextra",i);
        }
        if (me->query("adv_weapon/class/axe/lv")>=12)
        {
            i=me->query("adv_weapon/class/axe/moredamage")/300;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/axeextra",i);
            i=me->query("adv_weapon/class/axe/moredamage")/15;
            me->add_temp("apply/axe",i);
            me->add_temp("adv_weapon/fumorelv",i);
        }
        
        me->set_temp("adv_weapon/axe", 1);
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
    eff=(int)me->query_temp("adv_weapon/axeextra");
    me->add_temp("apply/damage",-eff);
    me->delete_temp("adv_weapon/axe");
    me->delete_temp("adv_weapon/axeextra");
    eff=(int)me->query_temp("adv_weapon/fumorelv");
    me->add_temp("apply/axe",-eff);
    me->delete_temp("adv_weapon/fumorelv");
    tell_object(me, "你静下心来，漫天斧影全无踪迹。\n");
    return;
}

