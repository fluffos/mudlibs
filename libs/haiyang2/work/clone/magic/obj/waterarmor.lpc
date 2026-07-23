// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

//inherit ARMOR;
inherit CLOTH;
void create()
{
	set_name(HIW "水神恺甲" NOR, ({ "water armor","waterarmor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW"\n这是一件水神恺甲,做工极其精致。是众神的遗产之一!\n"NOR);
		set("unit", "件");
		set("no_put", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
          set("armor_prop/intelligence",15);
          set("armor_prop/dexterity",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-water",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("wear_msg",HIW"一阵水色的光芒过后 ，$N的身上穿上了水神恺甲。\n"NOR);
                set("unequip_msg",HIW"$N把水神恺甲脱下。水色的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor", 1600);
		set("armor_prop/defense", 30);	
set("armor_prop/damage", 150);
	}
	setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(4)==0)
{
message_vision(HIW"$N身上的水神恺甲前出现了道冰壁，保护了$N全身！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (!ob->is_busy())
ob->start_busy(4);
message_vision(WHT"$n被冻的不能动弹!\n"NOR, me,ob);
}
message_vision(HIG"$n所有的攻击全打在了冰壁上！\n"NOR, me,ob);
return 0;
}
else   return damage;
}