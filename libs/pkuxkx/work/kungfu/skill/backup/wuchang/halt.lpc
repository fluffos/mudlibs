#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object *ob;
        int i, skill, damage;
    message_vision(
        HIY "$N低头默念一声：“阿弥陀佛！”\n" NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) ) continue;
 if (ob[i]->is_fighting()) {
    tell_object(ob[i], "你觉得空中飘荡着一种异常详和的气氛，你再也不想打架了\n");
    ob[i]->remove_all_enemy();
  }
        }
        return 1;
}
int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
    message_vision(
        HIY "$N低头默念一声：“阿弥陀佛！”\n" NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) ) continue;
 if (ob[i]->is_fighting()) {
    tell_object(ob[i], "你觉得空中飘荡着一种异常详和的气氛，你再也不想打架了\n");
    ob[i]->remove_all_enemy();
  }
        }
        return 1;
}
