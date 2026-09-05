// ancient_blade.c 远古之锏
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIY"远古之锏"NOR, ({ "ancient rapier", "rapier" }) );
  set_weight(4000);
  set("unit", "对");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 3);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/strength", 10);
  set("weapon_prop/dexerity", -5);
  set("weapon/strength", 10);
  set("weapon/dexerity", -5);
  set("long", "一对先秦时代遗留下来的双锏，舞动起来让对手感觉移动都有些困难。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 210);
	set("flag", 2 | (int)flag );
	set("skill_type", "whip");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
  setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
  object *enemy;
  int count, lp;
  string msg;
  
  enemy=me->query_enemy();
  count=sizeof(enemy);
  if ( count>4 )
  	count=4;
  
  if ( random(me->query_str()) >= (victim->query_str()-10)/2 )
  {
    msg= YEL"只见$N"YEL"舞动着"+name()+YEL"大杀四方，周围的敌人都惊呆了。\n"NOR;
    for( lp=0; lp<count; lp++)
      enemy[lp]->add_busy(1);
  }
  
  message_vision( msg, me, victim );
  return 0;
}
  	  