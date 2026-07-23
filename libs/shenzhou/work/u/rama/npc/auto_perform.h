// auto perform function (dispatched by chat_combat_msg) for tough xingxiu npc like You Tanzhi
// Last updated: 1/20/2002

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();


        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if( objectp(me->query_temp("weapon")) ) {
                command("perform jinxian");
        }
        else
        {
            command("perform sanyin");
            command("perform yiji");
            
        }

/*        if( present("sanxiao san", me) ||present("biling zhen", me)
          ||present("lianxin dan", me)){
          command("throw " + target->query("id"));
          }
*/
                return 1;
}

