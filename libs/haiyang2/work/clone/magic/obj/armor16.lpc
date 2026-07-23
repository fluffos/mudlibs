// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit SHIELD;

void create()
{
	set_name(RED "恐惧之盾" NOR, ({ "dark shield","darkshield"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"\n这是一面恐惧之盾,做工极其精致。上面有黑暗的力量!\n"NOR);
		set("unit", "面");
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

        set("armor_prop/intelligence",10);
         set("armor_prop/strength",10);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",RED"一阵血红的光芒过后 ，$N的手上多了一面恐惧之盾。\n"NOR);
                set("unequip_msg",RED"$N把恐惧之盾脱下。血红的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 500);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(4)==0)
{
message_vision(HIR"$N身上的恐惧之盾前出大量的魔力制造出小型的黑洞打向$n全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==6)
{
if (!ob->is_busy())
ob->start_busy(3);
a=350+damage;
if (ob->query("qi") > a)
{
ob->receive_damage("qi", a);
a=200+damage;
ob->receive_wound("qi", a);
}
message_vision(HIC"$n被暗黑核融术打的不能动弹!\n"NOR, me,ob);
}
message_vision(HIC"$n所有的攻击全被恐惧之盾档住！\n"NOR, me,ob);
return 0;
}	
else   return damage;
}