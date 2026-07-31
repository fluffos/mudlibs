// cracked by vikee 2/09/2002   vikee@263.net
// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>
#include <login.h>

inherit F_CLEAN_UP;

string *msgs= ({
"\n半空中劈下一道闪电，轰的一声落在你头上！\n",
"你仿佛觉得有人在你耳边隐隐说道：“还．．我．．命．．来．．．”",
"你突然觉得背脊上泛起一阵凉意：鬼？！",
"你想起以前干过的那么多伤天害理之事，不由惭愧得汗流浃背。",
"你抬头看看天，暗自嘀咕：我干了那么多坏事，不会天打雷劈吧？",
"你眼露凶光，发疯似地大喊：“杀！杀！杀！”累得上气不接下气。",
});

int update_condition(object me, int duration)
{

        object env=environment(me);
	
	if(env) {
	    if(!env->query("no_fight") && !env->query("no_magic")) {
	       me->apply_condition("no_pk_time", duration - 1);
	       me->delete_temp("no_heal_up/no_pk_time");
	    }
	    // can't hide in safe room to count hours.
	    else { // in a safe place.
		// no heal_up when in safe room.
		me->set_temp("no_heal_up/no_pk_time",1);
		if(living(me) && duration>100) {
		    seteuid(getuid());
                  if(env!=load_object(DEATH_ROOM) ||
			 !me->is_ghost()) {
		    me->receive_damage("kee",me->query("max_kee")/20);
		    me->receive_damage("sen",me->query("max_sen")/20);
//     if (me->query("sen")<0) me->set("sen",0);
//     if (me->query("kee")<0) me->set("kee",0);
		    write(msgs[random(sizeof(msgs))]+"\n");
		  }
		}
	    }
	}

	if( duration < 1 ) {
	    me->delete_temp("no_heal_up/no_pk_time");
	    return 0;
	}

	return CND_CONTINUE;
}

// mon 8/1/98
// this condition can't be cleared.
int no_clear_condition() {return 1;}

