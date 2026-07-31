// /d/shenlong/cancel_pk.h
// Last Modified by winder on Jul. 12 2002

void cancel_pk()
{
        mapping pkjob;
        object pker;
        string *v_list, v_id, p_id;
        int i, punish;

        if( !(pkjob = query("pkjob")) ) return;

        v_list = keys(pkjob);
        for(i = 0; i < sizeof(v_list); i++)
        {
                v_id = v_list[i];
                p_id = pkjob[v_id];

                if( !find_player(v_id) && (pker=find_player(p_id)) )
                {
                        tell_object(pker, "\n你要追杀的人已经离开了。\n");
                        delete("sgjob", pker);
                        punish = 3 + random(6);
                        addn("sg/failure", punish, pker);
                        addn("sg/exp", -punish, pker);
                        map_delete(pkjob, v_id);
                        set("pkjob", pkjob);
                }
                else
                        if( !pker )
                        {
                                pker = new(USER_OB);
                                set("id", p_id, pker);
                                if( pker->restore() )
                                {
                                        delete("sgjob", pker);
                                        punish = 1 + random(6);
                                        addn("sg/failure", punish, pker);
                                        addn("sg/exp", -punish, pker);
                                        pker->save();
                                }
                                destruct(pker);                                
                                map_delete(pkjob, v_id);
                                set("pkjob", pkjob);
                        }
        }
}