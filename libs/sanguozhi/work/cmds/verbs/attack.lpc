// attck.c
// by Suicide on Aug 22 2000
#include <verb.h>
inherit VERB_OB;
mixed direct_attack_str(string str) {
	return 1;
}
mixed do_attack_str(string str)
{
	object o, env;
    	mixed ret;
    	string *where;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("自己打自己？笑话。\n");
		return;
	}
	where = explode(file_name(this_body()->query_room()),"/");
	if ((AREA_D->get_area(where[1],"meeting")==where[2])||
	    (AREA_D->get_area(where[1],"flying")==where[2]))
	   {
	   write("这儿是军机重地，在这儿打斗不是找死吗？想坐牢阿？\n");
	   return;
	}
	env = o->query_room();
	if((o->query_job("patrol","beg_time"))&&
        (o->query_job("patrol","status")!="done")&&
        (o->query_job("patrol","area")==env->get_area())){
                write("对方正在带兵执行巡逻任务，双拳难敌四手，还是躲远点吧!\n");
                return;
        }
	ret=FIGHT_D->can_fight(this_body(),o);
}

mixed * query_verb_info()
{
     return ({ ({"STR" }) });
}
