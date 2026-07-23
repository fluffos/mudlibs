// Pingguo

// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();

        if ( !objectp(target))
        return 0;

        if( objectp(me->query_temp("weapon")) ) {
                command("perform wucai");
                command("perform qilin");
        }
        else
        {
                if( !me->query_temp("juding") )
                        command("perform juding");

                else
                                           command("perform baliu");
                                           command("perform jue");
                        command("perform huanxue "+target->query("id"));
        }


                return 1;
}
