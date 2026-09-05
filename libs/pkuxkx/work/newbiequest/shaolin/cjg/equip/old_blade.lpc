// old_blade.c 近古之刀
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIG"近古之刀"NOR, ({ "old blade","dao","blade" }) );
  set_weight(1000);
  set("unit", "把");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 2);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/strength", 15);
  set("weapon_prop/attack", 30);
  set("weapon/strength", 15);
  set("weapon/attack", 30);
  set("long", "一把宋代匠工精心打造的宝刀。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 230);
	set("flag", 2 | (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
  setup();
}