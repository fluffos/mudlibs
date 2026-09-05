// old_blade.c 近古之锤
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIG"近古之锤"NOR, ({ "old hammer", "hammer" }) );
  set_weight(8000);
  set("unit", "对");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 2);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/dexerity", -10);
  set("weapon/dexerity", -10);
  set("long", "一对宋代匠工精心打造的双锤，舞动起来四周都受到威胁。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 230);
	set("flag", flag );
	set("skill_type", "hammer");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
  setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
  object *enemy;
  int count, lp, dmg;
  string msg;
  
  enemy=me->query_enemy();
  enemy=enemy-({victim});
  count=sizeof(enemy);
  dmg=damage_bonus/20+1;
  if ( count>3 )
  	count=3;
  
  if ( dmg>=50 )
  	dmg=50;
  
  if ( random(me->query_str()) >= (victim->query_str()+30)/2 &&
  	   count>0 )
  {
    msg= YEL"只见$N"YEL"舞动着"+name()+YEL"大杀四方，周围的敌人都惊呆了。\n"NOR;
    for( lp=0; lp<count; lp++)
    {
      enemy[lp]->receive_damage("qi", dmg, me);
    	msg+= "( "+enemy[lp]->name()+COMBAT_D->eff_status_msg( (int)enemy[lp]->query("qi")*100/(int)enemy[lp]->query("max_qi") ) + " )\n";
    }
    message_vision( msg, me, victim);
  }
  
  return 0;
}
  	  