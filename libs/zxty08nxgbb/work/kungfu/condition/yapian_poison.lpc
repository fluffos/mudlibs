//by diabio
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int limit,limit1,limit2,limit3,limit4,damage;
        damage = me->query("max_qi")/30;
        if(damage < 20) damage = 20;
        limit = me->query("con") + (int)me->query_skill("force",1) / 10;
        if(me->query_temp("nopoison")) return 0;
        if(limit >50) limit =49;
        limit1=50 - limit + 2;
        limit2=50 - limit*2/3;
        limit3=50 - limit/2;
        limit4=50 - limit/4;
        if( duration < limit1
        &&      living(me) ) {
                tell_object(me, "你毒气攻心，心中犹如万蚁蚀骨，口角鼻涕眼泪直往下流。\n");
                message("vision", me->name() + "忽然大叫一声，面色发黑口中耳中鲜血直流，一头倒在地上。\n",
                        environment(me), me);
                me->unconcious();
                me->die();
                return 0;
        } 
        if( duration > limit4 ) {
                tell_object(me, "你忽然间鼻涕眼泪忍不住流了下来，心中非常的难受，好象要吃些什么才好。\n");
                message("vision", me->name() + "忽然脸色发黑，鼻涕从鼻子中直往下流。\n",
                        environment(me), me);
        }
        if( duration > limit3 && duration < limit4) {
                tell_object(me, "你觉得肝肠寸断，全身痛苦得缩成一团，毒气似乎已经开始扩散了。\n");
                message("vision", me->name() + "嘴唇发青，牙关咬的咯咯直响，身子已经蜷缩成了一团。\n",
                        environment(me), me);
        }
        if( duration > limit2 && duration < limit3) {
                tell_object(me, "你觉得四肢已经麻木，鼻涕眼泪止不住的往下流，快找解药吧，否则会死的。\n");
                message("vision", me->name() + "面上现出一股黑气，双目突出，眼中全是通红的血丝。\n",
                        environment(me), me);
        }
        if( duration > limit1 && duration < limit2) {
                tell_object(me, "你觉得视线开始模糊起来，快找解药吧，否则会死的。\n");
                message("vision", me->name() + "面上黑气越来越浓了，口鼻不断的流下眼泪跟鼻涕，一定是吸食鸦片过度了。\n",
                        environment(me), me);
        }
        me->receive_wound("qi", damage);
        me->receive_damage("jing", damage);
        me->apply_condition("yapian_poison", duration - 1);
        if( !duration ) return 0;
        return 1;
}
