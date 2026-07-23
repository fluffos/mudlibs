// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(HIB "水之法衣" NOR, ({ "water cloth","watercloth"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"\n这是一件水之法衣,做工极其精致。上面有水的力量!\n"NOR);
		set("unit", "件");
                set("value", 50000);
                set("treasure",1);       
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIB"一阵蓝色的光芒过后 ，$N的身上穿上了水之法衣。\n"NOR);
                set("unequip_msg",HIB"$N把水之法衣脱下。蓝色的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 670);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIB"$N身上的水之法衣前出现了道火墙，保护了$N全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==1)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(HIB"$n被水墙挡的不能动弹!\n"NOR, me,ob);
}
message_vision(HIB"$n所有的攻击全被水墙档住！\n"NOR, me,ob);
return 0;
}	
else   return damage;
}