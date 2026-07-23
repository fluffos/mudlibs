// cw_hat
//by steel
#include "ansi.h"
#include "armor.h"
inherit HEAD;
void create()
{	
  set_name(HIR"火炎之盔"NOR, ({ "fire hat", "firehat" }) );
  set_weight(1000);	
   if( clonep() )
  set_default_object(__FILE__);
  else {
		set("unit", "顶");
set("long", HIR"这是一顶火炎之盔,做工极其精致。是众神的遗产之一。\n"NOR);
		set("no_put", 1);
//		//set("value", 100000);
set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-fire",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("wear_msg",HIR"一阵火红的光芒过后 ，$N的头上多出了一顶火炎之盔。\n"NOR);
                set("unequip_msg",HIR"$N把火炎之盔脱下。火红的光芒也跟着消失了。\n"NOR);
		set("armor_prop/armor",200);
		set("armor_prop/damage", 200);
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
message_vision(HIR"$N头上的火炎之盔发出漫天火光，一个火炎球打向$n！\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
a = (int)me->query_skill("magic-fire", 1);
a=300+a*4;
                ob->receive_damage("qi", a);
a=300+a;
                ob->receive_wound("qi", a);
message_vision(HIR"$n全身都烧了起来!\n"NOR, me,ob);
}
else message_vision(HIG"火炎球在$n身侧划过，$n毫发无伤。!\n"NOR, me,ob);
}
else   return damage;
}