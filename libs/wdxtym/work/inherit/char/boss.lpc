// boss.c

inherit NPC;
#include <boss.h>
#define GIFT_D "/adm/daemons/giftd"
int is_boss() { return 1; }

mapping killer_reward(string name)
{
        mapping award_rate;
        string *temp_key;

        temp_key = keys(all_reward);
        if (member_array(name, temp_key) != -1)
                award_rate = all_reward[name];
        else
                award_rate = ([  ]);

        return award_rate;
}

varargs void die(object killer)
{
        object *obs, env;
        object me, ob;
        int exp, pot, mar;

        me = this_object();

        if (objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s"))
        {
                me->recover();
                return;
        }

        env = environment(me);

        if (! killer)
                killer = me->query_last_damage_from();

        if (objectp(killer))
        {
                obs = pointerp(killer->query_team()) ?
                                killer->query_team() : ({ killer });
                obs = filter_array(obs, (: environment($1) == $(env) :));

                exp = me->query("bonus");
                pot = exp / 2;
                mar = pot / 2;
                foreach (object user in obs)
                        GIFT_D->bonus(user, ([
                                "exp" : exp, "pot" : pot, "mar" : mar ]));
        }

        if( me->query("death_msg") )
                message_vision(me->query("death_msg"), me);

        if( me->query("clear_fuben") ) {
                object mazeobj;
                string fbname, owner;
                mazeobj = FUBEN_D->query_maze_mainobj(me);
                if( sscanf(base_name(mazeobj), "/f/%s/%s/maze", fbname, owner) == 2 )
                        FUBEN_D->delay_clear_fuben(fbname, owner);
        }
        return ::die(killer);
}

void unconcious()
{
        object ob;

        if (objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s"))
        {
                this_object()->recover();
                return;
        }

        die();
}

