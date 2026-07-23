//Code by Scatter
//Anti-Multi-IP
#define SAVE_NPC "/family_job/savenpc"

int do_chkip(object me, object npc)
{
        if(npc->query_temp("ipcheck" + query_ip_number(me)))
        {
                if(npc->query_temp("ipcheck" + query_ip_number(me)) == me->query("id"))
                {
                        return 1;
                }
                else
                {
                        return 2;
                }
        }

        else
        {
                npc->set_temp("ipcheck/" + query_ip_number(me), me->query("id"));
                call_out("do_ip_count", 900, me, npc);
                return 1;
        }
}

void do_ip_count(object me, object npc)
{
        npc->delete_temp("ipcheck" + query_ip_number(me));
        return;
}

