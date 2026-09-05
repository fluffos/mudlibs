#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{       object *ob;
        int i, skill, damage;



    message_vision(
       HIY "$N披发仗剑，手指苍天，只听雷声大作，一阵黑风卷过！”\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
    tell_object(ob[i], "你觉得眼前一黑，仿佛看到一片金星……\n");

    ob[i]->move("/clone/misc/void");


        }


        return 1;
}
int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;



    message_vision(
       HIY "$N披发仗剑，手指苍天，只听雷声大作，一阵黑风卷过！”\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
    tell_object(ob[i], "你觉得眼前一黑，仿佛看到一片金星……\n");

    ob[i]->move("/clone/misc/void");


        }


        return 1;
}

