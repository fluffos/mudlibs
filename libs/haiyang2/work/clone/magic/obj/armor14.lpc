// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIC "风神头盔" NOR, ({ "ice helmet","icehelmet"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"\n这是一个风神头盔,做工极其精致。上面有天空的力量!\n"NOR);
		set("unit", "个");
                set("value", 50000);
                set("treasure",1);       
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIC"一阵大地的光芒过后 ，$N戴上了风神头盔。\n"NOR);
                set("unequip_msg",HIC"$N把风神头盔拿下。大地的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 200);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIC"$N身上的风神头盔前出现了道闪电，打向了$n全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==4)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(HIC"$n被闪电打的不能动弹!\n"NOR, me,ob);
}
message_vision(HIC"$n所有的攻击全被闪电档住！\n"NOR, me,ob);
return 0;
}	
else   return damage;
}