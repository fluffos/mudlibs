// helper functions
#include <localtime.h>
#include <room.h>
#include <ansi.h>
#include "/d/beijing/beijing_defs.h"

#define START_ROOM "/d/beijing/tianqiao"

nosave int *kill_base_a = ({2, 3, 4, 5});
nosave int *job_upgrade_a = ({50, 100, 150, 200});
int job_upgrade_num(int rank) {return job_upgrade_a[rank];}

nosave int *exp_base_a = ({10000, 50000, 100000, 150000});
nosave int *exp_bonus_a = ({1000, 1500, 2000, 3000});
int exp_bonus(int rank) { return exp_bonus_a[rank]; }

object *obj_in_env(string file, object env)
{
    object *obs, *result;
    object ob;
    int n=0;

    result = ({});
    obs = filter_array(children(file), (: clonep :));
    foreach (ob in obs) {
        if (environment(ob) == env)
//	    result[n++] = ob;
		result = result + ({ob});	 
    }
    if (n > 0) return result;
    return 0;
}

object *obj_with_me(string file, object me)
{
    return obj_in_env(file, environment(me));
}

object clone_with_limit(string file, int max)
{
    object *obs;

    obs = filter_array(children(file), (: clonep :));
    if (sizeof(obs) >= max) return 0;
    return new(file);
}

object clonehere_with_limit(object room, string file, int max)
{
    object *obs, ob;

    obs = filter_array(children(file), (: clonep :));
    if (sizeof(obs) >= max) return 0;
    ob = new(file);
    ob->move(room);
    return ob;
}

int shichen()
{
    string ev = NATURE_D->outdoor_room_event();

    switch (ev) {
	case "event_dawn" :
	    return 4;
	case "event_sunrise" :
	    return 8;
	case "event_morning" :
	    return 10;
	case "event_noon" :
	    return 13;
	case "event_afternoon" :
	    return 16;
	case "event_evening" :
	    return 19;
	case "event_night":
	    return 21;
	default:
	case "event_midnight":
	    return 0;
    }
}

int is_night_shift()
{
    int sc = shichen();
    if (sc < 8 || sc >= 19) return 1;
    return 0;
}
int is_sunrise() { return shichen()-8; }
int is_sunset() { return shichen()-19; }
int is_dark_time()
{
    int sc = shichen();
    if (sc == 0 || sc == 21) return 1;
    return 0;
}


void job_reward(object player, int rank, int kill_num, int fail_num)
{
    int exp_reward, job_finish, exp_player, exp_bonus;
    int kill_base, exp_base, job_upgrade, sc;
    int kill_finish;
    float kill_ratio, ftemp_a, ftemp_b;

    // sanity check
    if (!player || rank < 0 || rank > 3 || kill_num < 0 || fail_num < 0) {
	write("BUG: 请告诉北大侠客行的巫师：job_reward sanity check error.\n");
	return;
    }

    player->add("chaoting/gate", 1);

    kill_base = kill_base_a[rank];
    exp_base = exp_base_a[rank];
    job_upgrade = job_upgrade_a[rank];
    exp_bonus = exp_bonus_a[rank];

    exp_player = player->query("combat_exp");
    job_finish = player->query("chaoting/gate");

	kill_finish = kill_num - fail_num;
	sc = 1;
	if (kill_finish <= 0)
	{
                sc = 0;
		kill_finish = 0;
		player->add("chaoting/job_fail", 1);
	}


    /* kill numbers and player exp take effect */
//暂时取消此限制
/*
    if (exp_player > exp_base)
    {
	kill_finish = kill_finish * exp_base/exp_player;
    }
*/
    ftemp_a = kill_finish;
    ftemp_b = kill_base;
    kill_ratio=ftemp_a/ftemp_b;
    if (kill_ratio > 2.0)
    {
       /* I hope log and floating point numbers work */
       kill_ratio = 1.0 + 0.5 * sqrt(kill_ratio);
       if (kill_ratio > 6.0) kill_ratio = 6.0;//好像不太可能达到
    }
//	if (player->query_temp("chaoting/night_job"))
//	kill_ratio += 0.1;

    /* primary reward: I wish the mixed float/int arithmetic is all right */
    exp_reward = exp_bonus * kill_ratio / 2; /* half hour job */

    if (job_finish > 3 * job_upgrade / 2)
    {
	exp_reward = exp_reward * job_upgrade / (job_finish-job_upgrade);
    }

//    exp_reward = exp_reward * (95+random(10))/200;  // 暂时注释，增加奖励
    player->add("combat_exp", exp_reward);
      player->add("exp/chaoting", exp_reward);
    player->add("potential",  exp_reward/8);
      player->add("pot/chaoting",  exp_reward/8);
    player->add("score", sc);
//    player->delete_temp("chaoting/current_job");
    player->delete_temp("chaoting/day_job");
    player->delete_temp("chaoting/night_job");

	if (exp_reward > 0)
	{
    player->add("combat_exp", player->query_temp("chaoting/gateexp"));
    player->add("exp/chaoting", player->query_temp("chaoting/gateexp"));
    tell_object(player, "你的经验增加了" + chinese_number(exp_reward + player->query_temp("chaoting/gateexp")) + "点！\n");
    tell_object(player, "你的潜能增加了" + chinese_number(exp_reward/8) + "点！\n");
    if (sc) tell_object(player, "你的对朝廷的贡献度增加了！\n");
	}
	else
    tell_object(player, "你本次守门任务看来做得并不成功！\n");

    player->delete_temp("chaoting/gateexp");
    tell_object(player, "到目前为止你已经守城门" + chinese_number(job_finish) + "次！\n");
    tell_object(player, "到目前为止你已经任务失败" + chinese_number(player->query("chaoting/job_fail")) + "次！\n");
     //测试用，成功后删除
     // tell me more details
	if (wizardp(player))
	{
	tell_object(player, "job_finish = "+job_finish+"\n");
	tell_object(player, "kill_finish = "+kill_finish+"\n");
	tell_object(player, "kill_ratio = "+kill_ratio+"\n");
	}

}


// must be called from an npc object
int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, last_room, this_room;
	object me = this_object();
        object here = environment(me);

	if ( strsrch(base_name(here), "/d/beijing") != 0) {
                message("vision", me->name() +
		    "急急忙忙地离开了。\n", here, me);
                me->move(START_ROOM);
                message("vision", me->name() + "走了过来。\n",
		    here, me);
        }

        if( !objectp(here)
        || me->is_fighting() || me->is_busy()
        || !mapp(exits = here->query("exits"))
        || me->query("jingli") < me->query("max_jingli") / 2 ) return 0;

        dirs = keys(exits);

        if( mapp(doors = here->query_doors()) ) {
                dirs += keys(doors);
        }
        if( sizeof(dirs) == 0 ) return 0;

        dir = dirs[random(sizeof(dirs))];
        if( stringp(last_room = me->query_temp("last_room"))
        &&  sizeof(dirs) > 1 && exits[dir] == last_room ) {
                dirs -= ({dir});
                dir = dirs[random(sizeof(dirs))];
        }

        if( mapp(doors) && !undefinedp(doors[dir])
        && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        me->set_temp("last_room", this_room);

        return 1;
}
