/* Conditions daemons, use to handle general infos of all conditions
** and control the execution of these conditions. 
** Flee@sgz August 20, 1999 
*/
#include <mudlib.h>
#include <security.h>

#define SAVE_FILE "/data/daemons/conditions"
#define BEAT_DURATION 	  4
#define DEFAULT_DURATION 30
#define DEFAULT_DAMAGE	 10

inherit M_ACCESS;

private mapping conds;

void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE, 1 :));
        return;
}
void create()
{
	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if( !conds||!mapp(conds) ) conds = ([ ]);
	call_out("condition_heart", BEAT_DURATION);
}
int set_cond_info(string id, string para, mixed value)
{
	mapping tmp;

	if( !stringp(id)||id=="" )	return 1;
	if( !stringp(para)||para=="" ) 	return 2;
	if( !value ) 			return 3;
	if( member_array(id, keys(conds))==-1 ){
		write("New condition is added to the database.\n");
		conds[id] = ([para: value, ]);
	} else  {
		write("Modified OK.\n");
		tmp = conds[id];
		tmp[para] = value;
		conds[id] = tmp;
	}

	save_data();

	return 4;
}
mixed query_cond_info(string id, string para)
{
	mapping tmp;

	if( !id||!stringp(id)||id=="" )	return conds;
	else if( member_array(id, keys(conds))==-1 ) return 1;

	tmp = conds[id];
	if( !para||!stringp(para)||para=="" ) return tmp;
	else if( member_array(para, keys(tmp))==-1 ) return 2;

	return tmp[para];
}
int rm_cond_info(string id)
{
        if( !id||!stringp(id)||id=="" )	return 1;
	if( member_array(id, keys(conds))==-1 ) return 2;

	map_delete(conds, id);

	return 3;
}
void do_summary()
{
	int i;
	mapping tmp;
	string output;
	
	if( !sizeof(conds) ) return;

	output=sprintf("%-8s%-12s  %-6s%-10s  %s\n",
		"名称", "ＩＤ", "等级", "发作间隔", "文件路径");
	foreach(string ss in keys(conds)){
		i++;
		tmp = conds[ss];
		output+=sprintf("%-8s%-12s  %-6s%-10s  %s\n", 
			tmp["name"], ss, chinese_number(tmp["level"])+"级", 
			chinese_number(tmp["times"]), tmp["path"]);
	}
	output+="当前三国中共有"+chinese_number(i)+"种状态\n";

	write(output);
}
void condition_heart()
{
	int *ids;
	mapping t_con, con_d;
	object con_obj;

	remove_call_out("condition_heart");
	call_out("condition_heart", BEAT_DURATION);

	ids = TROOP_D->list_troops();
	if( !ids||!arrayp(ids)||!sizeof(ids) ) return;

	foreach(int ii in ids){
		t_con = TROOP_D->get_troops(ii, "conds");
		if( !mapp(t_con)||!sizeof(t_con) ) continue;
		foreach(string ss in keys(t_con)){
			con_d = t_con[ss];
			con_d["duration"]--;
			con_d["times"]++;
			con_obj = load_object(conds[ss]["path"]);
			if( !con_obj||!objectp(con_obj)||con_d["duration"]<=0 )
				map_delete(t_con, ss);
			else if( con_d["times"]>=conds[ss]["times"] ){
				con_d["times"] = 0;
				con_obj->execute_con(ii, con_d["damage"], con_d["duration"]);
			}
			t_con[ss] = con_d;
			if (con_d["duration"] <=0)
			map_delete(t_con, ss);
		}

		TROOP_D->set_troops(ii, "conds", t_con);
	}
}
int apply_condition(int tid, string ss, int duration, int damage)
{
	int *tids;
	mapping troop_con, con_now;
	
	tids = TROOP_D->list_troops();

	if( !tid||!intp(tid)||member_array(tid, tids)==-1 ) return 1;
	if( !ss||!stringp(ss)||member_array(ss,keys(conds))==-1 ) return 2;
	if( !duration||!intp(duration) ) duration = DEFAULT_DURATION;
	if( !damage||!intp(damage) )	 damage   = DEFAULT_DAMAGE;

	troop_con = (["times":0, "duration":duration, "damage":damage, ]);

	con_now = TROOP_D->get_troops(tid, "conds");
	if( !con_now||!mapp(con_now)||!sizeof(con_now) ) con_now = ([ ]);
	con_now[ss] = troop_con; 
	TROOP_D->set_troops(tid, "conds", con_now);

	return 3;
}
int clear_condition(int tid, string ss)
{
	int *tids;
	mapping con_now;

	tids = TROOP_D->list_troops();
	if( !tid||!intp(tid)||member_array(tid, tids)==-1 ) return 1;
	con_now = TROOP_D->get_troops(tid, "conds");	
	if( !ss||!stringp(ss)||member_array(ss,keys(con_now))==-1 ){
		TROOP_D->set_troops(tid, "conds", ([ ]));
	} else {
		map_delete(con_now, ss);
		TROOP_D->set_troops(tid, "conds", con_now);
	}

	return 2;
}
