// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIW "白金徽章" NOR, ({ "earth badge","earthbadge"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIY"\n这是一面白金徽章,做工极其精致。上面有大地的力量!\n"NOR);
		set("unit", "个");
                set("value", 50000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIY"一阵大地的光芒过后 ，$N的身上穿上了白金徽章。\n"NOR);
                set("unequip_msg",HIY"$N把白金徽章拿下。大地的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 500);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIC"$N身上的白金徽章前出现了道地矛，刺向了$n全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==3)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(HIC"$n被地矛刺的不能动弹!\n"NOR, me,ob);
}
message_vision(HIC"$n所有的攻击全被地矛档住！\n"NOR, me,ob);
return 0;
}	
else   return damage;
}