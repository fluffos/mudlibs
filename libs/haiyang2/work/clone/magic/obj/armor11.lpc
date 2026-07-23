// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(RED "炎之结晶" NOR, ({ "fire armor","firearmor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"\n这是一件炎之结晶恺甲,做工极其精致。上面有火炎的力量!\n"NOR);
		set("unit", "件");
                set("value", 500000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",RED"一阵火炎的光芒过后 ，$N的身上穿上了火炎恺甲。\n"NOR);
                set("unequip_msg",RED"$N把炎之结晶恺甲脱下。火炎的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 660);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(RED"$N身上的炎之结晶前出现了道火炎，保护了$N全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==2)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(WHT"$n被火炎烧的不能动弹!\n"NOR, me,ob);
}
message_vision(HIG"$n所有的攻击全被火炎档住！\n"NOR, me,ob);
return 0;
}	
else   return damage;
}