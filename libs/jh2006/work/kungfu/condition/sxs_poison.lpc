#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (duration % 2) {
   if( !living(me) ) {
      message("vision", me->name() + "脸上忽现古怪笑容。\n", environment(me), me);
   }
   else {
      message("vision", me->name() + "突然间微微一笑，神色古怪。\n",
            environment(me), me);
   }
	}

      me->apply_condition("sxs_poison", duration - 1);
   if( duration < 1 ) {
      tell_object(me, BLU "突然，你脸上又现诡秘之极的笑容。\n" NOR );
      message("vision", me->name() + "突然身子瘫软，扭动了几下，俯伏在地，一动也不动了！\n",
      environment(me), me);
      me->set_temp("last_damage_from", "中三笑散之毒");
      me->die();
      return 0;
      }
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
