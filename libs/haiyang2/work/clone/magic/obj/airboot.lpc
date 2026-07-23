// shoe.c
//by steel
#include "armor.h"
#include "ansi.h"

inherit BOOTS;

void create()
{
	set_name(HIC "天空战靴" NOR, ({ "air boot", "airboot"}) );
       	set("long", HIC"这是一双天空战靴,做工极其精致。是众神的遗产之一。\n"NOR);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "双");
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                       set("armor_prop/dexterity",15);
       set("armor_prop/constitution",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-ice",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
		set("armor_prop/armor",150);
		set("armor_prop/damage", 250);
                set("wear_msg",HIC"一阵天蓝的光芒过后 ，$N的脚上多出了一双天空战靴。\n"NOR);
                set("unequip_msg",HIC"$N把天空战靴脱下。天蓝的光芒也跟着消失了。\n"NOR);
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
message_vision(HIC"$N脚上的天空战靴发出耀眼的光芒，一道闪电打向$n！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
a = (int)me->query_skill("magic-ice", 1);
a=300+a*2;
                ob->receive_damage("qi", a);
a=300+a;
                ob->receive_wound("qi", a);
message_vision(HIR"$n根本没法躲避，一道闪电端端正正打中$n!\n"NOR, me,ob);
}
else message_vision(HIR"闪电在$n身侧划过，$n毫发无伤。!\n"NOR, me,ob);
}
if (random(4)==1)
{
message_vision(HIC"$n脚上的天空战靴发出耀眼的光芒包围了$n！\n"NOR, ob,me);
if (me->is_busy())
{
me->start_busy(1);
message_vision(HIC"$n原本不太灵活的行动，恢复了！\n"NOR, ob,me);
}
}
else   return damage;
}