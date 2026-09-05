
#include <weapon.h>
inherit BLADE;
#include <ansi.h>

void create()
{
        set_name("陌刀", ({ "mo dao","dao","blade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沉重的陌刀，刀长丈余，重达50斤。\n");
                set("value", 5000);
                set("material", "steel");
                
        }
        set("no_sell",1);
        init_blade(80);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
  object *enemy;
  int count, lp, bleed;
  string msg;
  
  enemy=me->query_enemy();
  count=sizeof(enemy);
  if ( count>4 )
  	count=4;
  
  if ( random(me->query_str()) >= (victim->query_str()-10)/3 )
  {
    msg= RED"只见$N"RED"舞动着"+name()+RED"大杀四方，杀地热血飞溅，碎肉横飞。\n"NOR;
    for( lp=0; lp<count; lp++)
    {
    	bleed=enemy[lp]->query_condition("bleeding");
    	if ( bleed>0 )
    	{
    		enemy[lp]->apply_condition("bleeding", bleed+random(10));
    	}
    	else
    	{
        enemy[lp]->delete("pokong");
    	  enemy[lp]->apply_condition("bleeding", 10 + random(10));
      	enemy[lp]->add("pokong/bonus", 1+random(3));
        enemy[lp]->set("pokong/killer", me);
      }
    }
  }
  
  message_vision( msg, me, victim );
  return 0;
}