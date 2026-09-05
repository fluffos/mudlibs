// std_weapon.c 藏经阁标准武器
// by seagate@pkuxkx 2012.03.14

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;
#include "cjg_weapon.h"

void create()
{
	set_name("藏经阁武器",({"weapon"}));
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("generation", 2);
  set("is_weapon", 1);
  if ( query("cjg_weapon") )
  	set_cjg_weapon(query("cjg_weapon"));
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
  object *enemy;
  int count, lp, level;
  string msg;
  mapping suit_lv=(["cjg_level1":1, "cjg_level2":2, "cjg_level3":3]);
  
  level=suit_lv[query("suit")];
  enemy=me->query_enemy();
  count=sizeof(enemy);
  if ( count>2+level )
  	count=2+level;
  
  if ( random(me->query_str()) >= (victim->query_str()+50-20*level)*2/(4+level) )
  {
    msg= YEL"只见$N"YEL"舞动着"+name()+YEL"大杀四方，周围的敌人都惊呆了。\n"NOR;
    for( lp=0; lp<count; lp++)
      enemy[lp]->add_busy(1+random(2));
  }
  
  message_vision( msg, me, victim );
  return 0;
}