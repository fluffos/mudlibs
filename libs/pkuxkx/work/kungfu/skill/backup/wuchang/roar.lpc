#include <ansi.h>


inherit F_SSERVER;
int perform(object me, object target)
{    object *ob;
        int i, skill, damage;



    message_vision(
       HIY "$N披发仗剑，手指苍天，只听雷声大作，口中大喝：“死吧！”\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
    tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样ⅵ\n");           
    ob[i]->unconcious();
                       
    
                
               
        }


        return 1;
}

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;



    message_vision(
       HIY "$N披发仗剑，手指苍天，只听雷声大作，口中大喝：“死吧！”\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
    tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样ⅵ\n");           
    ob[i]->unconcious();
                       
    
                
               
        }


        return 1;
}

