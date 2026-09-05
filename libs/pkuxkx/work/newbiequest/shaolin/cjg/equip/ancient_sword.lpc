// ancient_sword.c 远古之剑
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIY"远古之剑"NOR, ({ "ancient sword","jian","sword" }) );
  set_weight(1000);
  set("unit", "柄");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 3);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/strength", 20);
  set("weapon_prop/attack", 80);
  set("weapon/strength",20);
  set("weapon/attack",80);
  set("long", "一柄先秦时代遗留下来的宝剑。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 210);
	set("flag", 2 | (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
  setup();
}