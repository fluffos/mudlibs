// shield.c 牛皮盾
#include "ansi.h"
#include "armor.h"
 
inherit SHIELD;
 
void create()
{
	set_name(YEL"大地之盾"NOR, ({ "earth shield", "earthshield" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
set("long", HIR"这是一面大地之盾,做工极其精致。是众神的遗产之一。\n"NOR);
set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
        set("armor_prop/intelligence",15);
         set("armor_prop/strength",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-earth",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );	}
                set("wear_msg",YEL"一阵大地的光芒过后 ，$N的手上多出了面大地之盾。\n"NOR);
                set("unequip_msg",YEL"$N把大地之盾放下。大地的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor",400);
set("armor_prop/damage", 100);
	setup();
}


int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(4)==0)
{
message_vision(YEL"$N的大地之盾与大地共鸣，一个地刺刺向$n！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
a = (int)me->query_skill("magic-earth", 1);
a=400+a;
                ob->receive_damage("qi", a);
a=a;
                ob->receive_wound("qi", a);
if (!ob->is_busy())
ob->start_busy(3);
message_vision(HIR"$n被地刺刺的不能动弹!\n"NOR, me,ob);
}
else message_vision(HIG"地刺在$n身侧刺过，$n毫发无伤。!\n"NOR, me,ob);
}
else   return damage;
}
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}